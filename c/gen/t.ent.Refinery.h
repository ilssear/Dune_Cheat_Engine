// gen time: 2024-07-14 04:10:49 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_Refinery_h__
#define __gen_t_ent_Refinery_h__

#include <common.h>
#include <gen/t.ent.Building.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Refinery ent_Refinery;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;


// type: ent.Refinery, kind: HOBJ, pType: 0x02748E3EABB8
struct ent_Refinery {
  // super: ent.Building
  ent_Building              super;

  // cls: ent.Refinery, begin_offset: 0x03C8
  hxbit_ArrayProxyData*     harvesters;         // +03C8: HOBJ hxbit.ArrayProxyData
  bool                      requestedAutoRecall; // +03D0
  hxbit_ArrayProxyData*     recruitments;       // +03D8: HOBJ hxbit.ArrayProxyData
  // total_size: 0x03E0
}; // ent_Refinery (ent.Refinery)

_Static_assert(sizeof(ent_Refinery) == 0x03E0, "cls ent.Refinery has wrong size");


extern ent_Faction* ent_Refinery_get_factionOwner(ent_Refinery* obj);
extern void ent_Refinery_init(ent_Refinery* obj);
extern void ent_Refinery_doRemove(ent_Refinery* obj);
extern void ent_Refinery_die(ent_Refinery* obj, void* arg1);
extern void ent_Refinery_clearHarvesters(ent_Refinery* obj);
extern String* ent_Refinery_getHarvesterKind(ent_Refinery* obj);
extern void ent_Refinery_onFinishConstruction(ent_Refinery* obj);
extern bool ent_Refinery_updateStatus(ent_Refinery* obj);
extern void ent_Refinery_onDisable(ent_Refinery* obj);
extern bool ent_Refinery_isProducing(ent_Refinery* obj);
extern int ent_Refinery_getMaxHarvesters(ent_Refinery* obj);
extern int ent_Refinery_getMaxCaryalls(ent_Refinery* obj);
extern hl_types_ArrayObj* ent_Refinery_getHarvesterBuyCost(ent_Refinery* obj, void* arg1);
extern hl_types_ArrayObj* ent_Refinery_getHarvesterUpkeepCost(ent_Refinery* obj);
extern EReason* ent_Refinery_implAddHarvester(ent_Refinery* obj);
extern void ent_Refinery_addRecruitment(ent_Refinery* obj);
extern EReason* ent_Refinery_implCancelRecruitment(ent_Refinery* obj, int arg1);
extern double ent_Refinery_getProduction(ent_Refinery* obj);
extern void ent_Refinery_update(ent_Refinery* obj, double arg1);
extern void ent_Refinery_updateRecruitment(ent_Refinery* obj, double arg1);
extern void ent_Refinery_onChangeOwner(ent_Refinery* obj, ent_Faction* arg1, ent_Faction* arg2);
extern void ent_Refinery_doAddHarvester(ent_Refinery* obj);
extern int ent_Refinery_getCLID(ent_Refinery* obj);
extern void ent_Refinery_serialize(ent_Refinery* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Refinery_getSerializeSchema(ent_Refinery* obj);
extern void ent_Refinery_unserializeInit(ent_Refinery* obj);
extern void ent_Refinery_unserialize(ent_Refinery* obj, hxbit_Serializer* arg1);
extern EReason* ent_Refinery_addHarvester(ent_Refinery* obj, void* arg1);
extern bool ent_Refinery_rpcAddHarvester__impl(ent_Refinery* obj);
extern EReason* ent_Refinery_checkAddHarvester(ent_Refinery* obj);
extern bool ent_Refinery_canAddHarvester(ent_Refinery* obj);
extern EReason* ent_Refinery_cancelRecruitment(ent_Refinery* obj, int arg1, void* arg2);
extern bool ent_Refinery_rpcCancelRecruitment__impl(ent_Refinery* obj, int arg1);
extern EReason* ent_Refinery_checkCancelRecruitment(ent_Refinery* obj, int arg1);
extern bool ent_Refinery_canCancelRecruitment(ent_Refinery* obj, int arg1);
extern hxbit_ArrayProxyData* ent_Refinery___net_mark_harvesters(ent_Refinery* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Refinery_set_harvesters(ent_Refinery* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Refinery_get_networkPropHarvesters(ent_Refinery* obj);
extern bool ent_Refinery___net_mark_requestedAutoRecall(ent_Refinery* obj, bool arg1);
extern bool ent_Refinery_set_requestedAutoRecall(ent_Refinery* obj, bool arg1);
extern int ent_Refinery_get_networkPropRequestedAutoRecall(ent_Refinery* obj);
extern hxbit_ArrayProxyData* ent_Refinery___net_mark_recruitments(ent_Refinery* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Refinery_set_recruitments(ent_Refinery* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Refinery_get_networkPropRecruitments(ent_Refinery* obj);
extern void ent_Refinery_rpcAddHarvester(ent_Refinery* obj, void* arg1);
extern void ent_Refinery_rpcCancelRecruitment(ent_Refinery* obj, int arg1, void* arg2);
extern void ent_Refinery_networkFlush(ent_Refinery* obj, hxbit_Serializer* arg1);
extern void ent_Refinery_networkSync(ent_Refinery* obj, hxbit_Serializer* arg1);
extern void ent_Refinery_networkInitProxys(ent_Refinery* obj);
extern bool ent_Refinery_networkRPC(ent_Refinery* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Refinery_networkGetName(ent_Refinery* obj, int arg1, void* arg2);


#endif // __gen_t_ent_Refinery_h__
