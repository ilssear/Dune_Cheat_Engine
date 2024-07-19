// gen time: 2024-07-14 04:39:47 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_logic_Logic_h__
#define __gen_t_logic_Logic_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct ProductionKind ProductionKind;
typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Object ent_Object;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_WaitEvent lib_WaitEvent;
typedef struct logic_EFlowSource logic_EFlowSource;
typedef struct logic_Logic logic_Logic;


// type: logic.Logic, kind: HOBJ, pType: 0x02748E3E4538
struct logic_Logic {
  // super: net.Serializable
  net_Serializable          super;

  // cls: logic.Logic, begin_offset: 0x0038
  bool                      inited;             // +0038
  bool                      creating;           // +0039
  bool                      removed;            // +003A
  double                    removeTime;         // +0040
  int                       removeFrame;        // +0048
  void*                     oldHxBitFields;     // +0050: HDYN
  lib_WaitEvent*            event;              // +0058: HOBJ lib.WaitEvent
  double                    totalProd;          // +0060
  double                    totalProdPositive;  // +0068
  double                    totalProdNegative;  // +0070
  double                    serverFrameUpdateTimer; // +0078
  double                    frameUpdateTimer;   // +0080
  double                    regUpdateTimer;     // +0088
  // total_size: 0x0090
}; // logic_Logic (logic.Logic)

_Static_assert(sizeof(logic_Logic) == 0x0090, "cls logic.Logic has wrong size");


extern bool logic_Logic_get_clientSideUpdates(logic_Logic* obj);
extern ent_Faction* logic_Logic_get_factionOwner(logic_Logic* obj);
extern String* logic_Logic_get_factionOwnerKind(logic_Logic* obj);
extern ent_Faction* logic_Logic_get_diplomaticOwner(logic_Logic* obj);
extern bool logic_Logic_set_removed(logic_Logic* obj, bool arg1);
extern bool logic_Logic_networkAllow(logic_Logic* obj, int arg1, int arg2, void* arg3);
extern void* logic_Logic_getLogData(logic_Logic* obj);
extern bool logic_Logic_enableApiLog(logic_Logic* obj);
extern void logic_Logic_log(logic_Logic* obj, String* arg1, void* arg2, void* arg3);
extern void logic_Logic_logWarning(logic_Logic* obj, String* arg1, void* arg2, void* arg3);
extern void logic_Logic_logError(logic_Logic* obj, String* arg1, void* arg2, void* arg3);
extern void logic_Logic_doLog(logic_Logic* obj, int arg1, String* arg2, void* arg3, void* arg4);
extern void logic_Logic_onCreate(logic_Logic* obj);
extern void logic_Logic_init(logic_Logic* obj);
extern void logic_Logic_patchEntity(logic_Logic* obj, int arg1);
extern void logic_Logic_remove(logic_Logic* obj);
extern void logic_Logic_doRemove(logic_Logic* obj);
extern void logic_Logic_alive(logic_Logic* obj);
extern void logic_Logic_postInit(logic_Logic* obj);
extern bool logic_Logic_hasAccessToRes(logic_Logic* obj, int arg1);
extern double logic_Logic_getResourceProduction(logic_Logic* obj, int arg1, void* arg2, ProductionKind* arg3, void* arg4, void* arg5);
extern hl_types_ArrayObj* logic_Logic_getResourceProductionDetail(logic_Logic* obj, int arg1, ProductionKind* arg2, void* arg3, void* arg4);
extern void logic_Logic_addDescProd(logic_Logic* obj, logic_EFlowSource* arg1, double arg2, void* arg3, void* arg4);
extern void logic_Logic_addDescConso(logic_Logic* obj, logic_EFlowSource* arg1, double arg2, void* arg3, void* arg4);
extern void logic_Logic_addDescFlow(logic_Logic* obj, logic_EFlowSource* arg1, double arg2, void* arg3, void* arg4);
extern void logic_Logic_addFlow(logic_Logic* obj, double arg1);
extern void logic_Logic_addDescAttributeFlat(logic_Logic* obj, ent_Object* arg1, int arg2, void* arg3, void* arg4, void* arg5, void* arg6);
extern void logic_Logic_addDescAttributeMultiplier(logic_Logic* obj, ent_Object* arg1, int arg2, int64 arg3, void* arg4);
extern void logic_Logic_addDescResultMultiplier(logic_Logic* obj, logic_EFlowSource* arg1, double arg2, void* arg3);
extern double logic_Logic_doGetResourceProductionDetail(logic_Logic* obj, int arg1, void* arg2, ProductionKind* arg3, void* arg4, void* arg5);
extern void logic_Logic_reload(logic_Logic* obj);
extern void logic_Logic_finalize(logic_Logic* obj);
extern void logic_Logic_onReady(logic_Logic* obj);
extern void logic_Logic_onLoadingFinished(logic_Logic* obj, bool arg1);
extern void logic_Logic_regularUpdate(logic_Logic* obj, double arg1);
extern void logic_Logic_clientRegularUpdate(logic_Logic* obj, double arg1);
extern void logic_Logic_update(logic_Logic* obj, double arg1);
extern void logic_Logic_clientUpdate(logic_Logic* obj, double arg1);
extern void logic_Logic_serverFrameUpdate(logic_Logic* obj, double arg1);
extern void logic_Logic_serverFrameRegularUpdate(logic_Logic* obj, double arg1);
extern void logic_Logic_frameUpdate(logic_Logic* obj, double arg1);
extern void logic_Logic_frameRegularUpdate(logic_Logic* obj, double arg1);
extern void logic_Logic_dailyUpdate(logic_Logic* obj);
extern void logic_Logic_monthlyUpdate(logic_Logic* obj);
extern void logic_Logic_tick(logic_Logic* obj, double arg1);
extern void logic_Logic_onPlayerSwitch(logic_Logic* obj);
extern String* logic_Logic_getIdStr(logic_Logic* obj);
extern String* logic_Logic_getMarkRoot(logic_Logic* obj);
extern String* logic_Logic_getMarkStr(logic_Logic* obj, void* arg1);
extern void logic_Logic_mark(logic_Logic* obj, String* arg1);
extern bool logic_Logic___net_mark_removed(logic_Logic* obj, bool arg1);
extern int logic_Logic_get_networkPropRemoved(logic_Logic* obj);
extern void logic_Logic_networkFlush(logic_Logic* obj, hxbit_Serializer* arg1);
extern void logic_Logic_networkSync(logic_Logic* obj, hxbit_Serializer* arg1);
extern String* logic_Logic_networkGetName(logic_Logic* obj, int arg1, void* arg2);
extern int logic_Logic_getCLID(logic_Logic* obj);
extern void logic_Logic_serialize(logic_Logic* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_Logic_getSerializeSchema(logic_Logic* obj);
extern void logic_Logic_unserializeInit(logic_Logic* obj);
extern void logic_Logic_unserialize(logic_Logic* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_Logic_h__
