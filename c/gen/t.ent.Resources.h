// gen time: 2024-07-14 16:18:12 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_Resources_h__
#define __gen_t_ent_Resources_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct String String;
typedef struct ent_ETransactionType ent_ETransactionType;
typedef struct ent_Object ent_Object;
typedef struct ent_Resources ent_Resources;
typedef struct haxe_ds_StringMap haxe_ds_StringMap;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.Resources, kind: HOBJ, pType: 0x01EC714D0678
struct ent_Resources {
  // super: net.Serializable
  net_Serializable          super;

  // cls: ent.Resources, begin_offset: 0x0038
  ent_Object*               owner;              // +0038: HOBJ ent.Object
  haxe_ds_StringMap*        stock;              // +0040: HOBJ haxe.ds.StringMap
  haxe_ds_StringMap*        stockDiff;          // +0048: HOBJ haxe.ds.StringMap
  bool                      stockDirty;         // +0050
  hl_types_ArrayObj*        outgoing;           // +0058: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        incoming;           // +0060: HOBJ hl.types.ArrayObj
  double                    nextRefreshTimer;   // +0068
  double                    refreshRate;        // +0070
  // total_size: 0x0078
}; // ent_Resources (ent.Resources)

_Static_assert(sizeof(ent_Resources) == 0x0078, "cls ent.Resources has wrong size");


extern void ent_Resources_refreshStocks__impl(ent_Resources* obj, haxe_ds_StringMap* arg1);
extern void ent_Resources_alive(ent_Resources* obj);
extern void ent_Resources_init(ent_Resources* obj);
extern void ent_Resources_remove(ent_Resources* obj);
extern double ent_Resources_get(ent_Resources* obj, String* arg1);
extern void ent_Resources_set(ent_Resources* obj, String* arg1, double arg2);
extern void ent_Resources_add(ent_Resources* obj, String* arg1, double arg2, void* arg3);
extern bool ent_Resources_use(ent_Resources* obj, String* arg1, double arg2);
extern bool ent_Resources_has(ent_Resources* obj, String* arg1, double arg2);
extern void ent_Resources_addOutgoing(ent_Resources* obj, String* arg1, double arg2, ent_Object* arg3, ent_ETransactionType* arg4, ent_Object* arg5);
extern hl_types_ArrayObj* ent_Resources_getOutgoing(ent_Resources* obj, String* arg1);
extern hl_types_ArrayObj* ent_Resources_getIncoming(ent_Resources* obj, String* arg1);
extern void ent_Resources_resetTransactions(ent_Resources* obj, ent_Object* arg1);
extern void ent_Resources_regularUpdate(ent_Resources* obj, double arg1);
extern void ent_Resources_serverFrameUpdate(ent_Resources* obj, double arg1);
extern ent_Object* ent_Resources___net_mark_owner(ent_Resources* obj, ent_Object* arg1);
extern ent_Object* ent_Resources_set_owner(ent_Resources* obj, ent_Object* arg1);
extern int ent_Resources_get_networkPropOwner(ent_Resources* obj);
extern haxe_ds_StringMap* ent_Resources___net_mark_stock(ent_Resources* obj, haxe_ds_StringMap* arg1);
extern haxe_ds_StringMap* ent_Resources_set_stock(ent_Resources* obj, haxe_ds_StringMap* arg1);
extern int ent_Resources_get_networkPropStock(ent_Resources* obj);
extern void ent_Resources_refreshStocks(ent_Resources* obj, haxe_ds_StringMap* arg1);
extern void ent_Resources_networkFlush(ent_Resources* obj, hxbit_Serializer* arg1);
extern void ent_Resources_networkSync(ent_Resources* obj, hxbit_Serializer* arg1);
extern bool ent_Resources_networkRPC(ent_Resources* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Resources_networkGetName(ent_Resources* obj, int arg1, void* arg2);
extern int ent_Resources_getCLID(ent_Resources* obj);
extern void ent_Resources_serialize(ent_Resources* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Resources_getSerializeSchema(ent_Resources* obj);
extern void ent_Resources_unserializeInit(ent_Resources* obj);
extern void ent_Resources_unserialize(ent_Resources* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_Resources_h__
