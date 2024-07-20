
#ifndef __COMMON_NO_GEN_H__
#define __COMMON_NO_GEN_H__

// this is to silence vscode c_cpp ext madness
#ifdef __VSCODE
#define _Static_assert(c, msg) static_assert(c, msg)
#endif // __VSCODE

// some tcc stuff
//#include <tccdefs.h>
#define va_list __builtin_va_list
#define va_arg __builtin_va_arg
#define va_end __builtin_va_end
#define va_copy __builtin_va_copy

// common basic types
typedef char sbyte;
typedef unsigned char byte, BYTE;

//#define bool byte
#define true ((bool)1)
#define false ((bool)0)

typedef unsigned short int16;
typedef unsigned short ushort, uint16, WORD;

typedef int int32;
typedef unsigned int uint, uint32, DWORD;

typedef long long int64;
typedef unsigned long long uint64, qword, intptr_t, size_t, SIZE_T, ULONGLONG;

typedef void *PVOID;

// hashlink specific
#define LIBHL_STATIC
//#define HL_NATIVE_UCHAR_FUN
//#define HL_API extern
#define bool byte
//typedef unsigned char uchar;
typedef short	uchar;
#define _CE
#include <hl.h>

#define lengthof(a) (sizeof(a)/sizeof(*a))

#endif // __COMMON_NO_GEN_H__
