#include <common_no_gen.h>

/*
typedef struct _MEMORY_BASIC_INFORMATION {
  PVOID  BaseAddress;
  PVOID  AllocationBase;
  DWORD  AllocationProtect;
  WORD   PartitionId;
  SIZE_T RegionSize;
  DWORD  State;
  DWORD  Protect;
  DWORD  Type;
} MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION;
*/

typedef struct __declspec(align(16)) _MEMORY_BASIC_INFORMATION64 {
    ULONGLONG BaseAddress;
    ULONGLONG AllocationBase;
    DWORD     AllocationProtect;
    DWORD     __alignment1;
    ULONGLONG RegionSize;
    DWORD     State;
    DWORD     Protect;
    DWORD     Type;
    DWORD     __alignment2;
} MEMORY_BASIC_INFORMATION64, MEMORY_BASIC_INFORMATION, *PMEMORY_BASIC_INFORMATION64, *PMEMORY_BASIC_INFORMATION;



extern SIZE_T VirtualQuery(
  /*[in, optional]*/ PVOID                     lpAddress,
  /*[out]         */ PMEMORY_BASIC_INFORMATION lpBuffer,
  /*[in]          */ SIZE_T                    dwLength
);

extern void *memset(void *dest, int c, size_t count);

extern DWORD GetLastError();

const DWORD MEM_PRIVATE    = 0x00020000;
const DWORD MEM_COMMIT     = 0x00001000;
const DWORD PAGE_READWRITE = 0x00000004;

const SIZE_T minRegionSize = 0x1000; // 0x100000;
const SIZE_T minTypesOffset = 0x0000;
//const SIZE_T maxTypesOffset = 0x0180;

typedef struct {
  hl_type* pBegin;
  void* pBaseAddr;
  void* pAllocAddr;
  qword nRegionsScanned;
  qword nScans;
  qword nQwTotal;
  PVOID pErrRegionBase;
  DWORD errCode;
} hlFindTypes_Result_t;
hlFindTypes_Result_t hlFindTypes_Result;
#define res hlFindTypes_Result

void* hlFindTypes()
{
  memset(&res, 0, sizeof(res));

  MEMORY_BASIC_INFORMATION mbi;
  
  SIZE_T retSize = sizeof(mbi);
  int nRegions = 0;
  int nScans = 0;
  for (BYTE* pAddr = 0; retSize > 0; pAddr = ((BYTE*)mbi.BaseAddress) + mbi.RegionSize) {
    nRegions++;

    memset(&mbi, 0, sizeof(mbi));
    retSize = VirtualQuery(pAddr, &mbi, sizeof(mbi));
    if (retSize == 0) {
      res.nRegionsScanned = nRegions;
      res.pErrRegionBase = pAddr;
      res.errCode = GetLastError();
      return &res;
    }

    BYTE* ab = (BYTE*)mbi.AllocationBase;
    BYTE* ba = (BYTE*)mbi.BaseAddress;
    SIZE_T sz = mbi.RegionSize;

    if (mbi.Type != MEM_PRIVATE)
      continue; // wrong type of the region

    //if (mbi.BaseAddress != mbi.AllocationBase)
    //  continue; // not an alloc base

    if ((mbi.State != MEM_COMMIT) || (mbi.Protect != PAGE_READWRITE))
      continue; // wrong state or page protection

    if (mbi.RegionSize < minRegionSize)
      continue; // type array is allocated in large region

    /* ------------------------------------------------------
       we have found a candidate region with right properties
       so we can scan for type definition array
       - each type takes 0x20 bytes
       - and those at te beginning look like (in 8 byte integers):
           0, 0, 0, 0,
           1, 0, 0, 0,
           2, 0, 0, 0,
           3, 0, 0, 0,
           4, 0, 0, 0,
           5, 0, 0, 0,
           6, 0, 0, 0,

       - alligned at 8 bytes
       - this pattern seems to be unique in the whole process
       - and we also know that so far it always began at
           mbi.AllocationBase + 0x00000098

       - but we should probably give it some tolerance

       ------------------------------------------------------ */


    // simple (not optimized) pattern scan
    size_t maxTypesOffset = sz - 0x100;  // search through whole region minus the size of what we are searching for
    size_t* scanEnd = (size_t*)(ba + maxTypesOffset);
    size_t v = (size_t)-1LL;
    size_t* a = (size_t*)(ba + minTypesOffset);

try_next_addr: ;

    nScans++;
    int nZeros = 0;
    while (a <= scanEnd) {
      v = *(a++); res.nQwTotal++;
			if (v == 0) {
        nZeros++;
      } else {
        if ((nZeros >= 4) && (v == 1))
          break;
        nZeros = 0;
      }
		}

    // we exited the first loop (counting leading zeros)
    // if the nZeros < 4 or v != 1 then we failed and can try another region
    if ((nZeros < 4) || (v != 1))
      continue; // not the type array we are searching for

    // this will count the non-zero qwords from 1 to 6 (see the pattern above)
    bool bFailed = false;
    const int maxNZ = 6;
		for (int i = 1; !bFailed && (i <= maxNZ); i++) {
      // check the non-zero qword (it must be v == i)
      if (v != i) {
			  bFailed = true;
        break;
			}
      // there must be 3 zeros
      for (int j = 0; !bFailed && (j < 3); j++) {
        v = *(a++); res.nQwTotal++;
        if (v != 0)
          bFailed = true;
      }
			v = *(a++); res.nQwTotal++;
    }

    // we finished the scan loop
    // if we failed, try another region
    if (bFailed)
      goto try_next_addr; // continue;

    // we have found the pattern of the beginning of type array
    // move the pointer back before the pattern to real array begin
		size_t* pBegin = a - 1 - (maxNZ + 1) * 4;
    res.pBegin = pBegin;
    res.pBaseAddr = ba;
    res.pAllocAddr = ab;
    res.nRegionsScanned = nRegions;
    res.nScans = nScans;
    return &res;
	}
  return -2;
}
