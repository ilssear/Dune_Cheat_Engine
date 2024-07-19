// gen time: 2024-07-14 08:52:41 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_String_h__
#define __gen_t_String_h__

#include <common.h>
typedef struct String String;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;


// type: String, kind: HOBJ, pType: 0x02748E3E11F8
struct String {
  hl_type* pType;

  // cls: String, begin_offset: 0x0008
  byte*                     bytes;              // +0008: HBYTES
  int                       length;             // +0010
  // total_size: 0x0014
}; // String (String)

_Static_assert(sizeof(String) == 0x0018, "cls String has wrong size");


extern String* String_toUpperCase(String* obj);
extern String* String_toLowerCase(String* obj);
extern String* String_charAt(String* obj, int arg1);
extern void* String_charCodeAt(String* obj, int arg1);
extern int String_findChar(String* obj, int arg1, int arg2, byte* arg3, int arg4);
extern int String_indexOf(String* obj, String* arg1, void* arg2);
extern int String_lastIndexOf(String* obj, String* arg1, void* arg2);
extern hl_types_ArrayObj* String_split(String* obj, String* arg1);
extern String* String_substr(String* obj, int arg1, void* arg2);
extern String* String_substring(String* obj, int arg1, void* arg2);
extern String* String_toString(String* obj);
extern byte* String_toUtf8(String* obj);
extern byte* String___string(String* obj);
extern int String___compare(String* obj, void* arg1);


#endif // __gen_t_String_h__
