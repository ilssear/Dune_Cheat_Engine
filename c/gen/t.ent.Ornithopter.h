// gen time: 2024-07-14 16:24:04 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_Ornithopter_h__
#define __gen_t_ent_Ornithopter_h__

#include <common.h>
#include <gen/t.ent.Unit.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_AttackKind ent_AttackKind;
typedef struct ent_AttackType ent_AttackType;
typedef struct ent_DamageSource ent_DamageSource;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Ornithopter ent_Ornithopter;
typedef struct ent_Structure ent_Structure;
typedef struct ent_Zone ent_Zone;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct prefab_Curve prefab_Curve;


// type: ent.Ornithopter, kind: HOBJ, pType: 0x01EC714D2138
struct ent_Ornithopter {
  // super: ent.Unit
  ent_Unit                  super;

  // cls: ent.Ornithopter, begin_offset: 0x04D1
  ent_Zone*                 reconZone;          // +04D8: HOBJ ent.Zone
  double                    idleTime;           // +04E0
  prefab_Curve*             deathZCurve;        // +04E8: HOBJ prefab.Curve
  double                    lastDestroyChance;  // +04F0
  double                    lastDestroyCheck;   // +04F8
  // total_size: 0x0500
}; // ent_Ornithopter (ent.Ornithopter)

_Static_assert(sizeof(ent_Ornithopter) == 0x0500, "cls ent.Ornithopter has wrong size");


extern void ent_Ornithopter_patchEntity(ent_Ornithopter* obj, int arg1);
extern void ent_Ornithopter_init(ent_Ornithopter* obj);
extern bool ent_Ornithopter_isAutonomous(ent_Ornithopter* obj);
extern bool ent_Ornithopter_enableApiLog(ent_Ornithopter* obj);
extern EReason* ent_Ornithopter_implToggleAutonomous(ent_Ornithopter* obj);
extern void ent_Ornithopter_setAutonomous(ent_Ornithopter* obj, bool arg1);
extern bool ent_Ornithopter_canAutoRecon(ent_Ornithopter* obj);
extern void ent_Ornithopter_doActionInternal(ent_Ornithopter* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern bool ent_Ornithopter_get_refundable(ent_Ornithopter* obj);
extern bool ent_Ornithopter_isIdle(ent_Ornithopter* obj);
extern bool ent_Ornithopter_isAtGroundLevel(ent_Ornithopter* obj);
extern void ent_Ornithopter_initRotFilter(ent_Ornithopter* obj);
extern void ent_Ornithopter_doSetOutline(ent_Ornithopter* obj, void* arg1, void* arg2, void* arg3);
extern bool ent_Ornithopter_isFlagVisible(ent_Ornithopter* obj);
extern hl_types_ArrayObj* ent_Ornithopter_getAvailableActions(ent_Ornithopter* obj);
extern double ent_Ornithopter_getWormDetectionDelay(ent_Ornithopter* obj);
extern bool ent_Ornithopter_willExploreCell(ent_Ornithopter* obj);
extern void ent_Ornithopter_chooseJob(ent_Ornithopter* obj);
extern void ent_Ornithopter_updateCurrentAction(ent_Ornithopter* obj, double arg1);
extern void* ent_Ornithopter_rightClickForAction(ent_Ornithopter* obj, void* arg1, hl_types_ArrayObj* arg2, void* arg3, void* arg4);
extern bool ent_Ornithopter_requestAction(ent_Ornithopter* obj, void* arg1, void* arg2, ent_Faction* arg3, void* arg4);
extern void ent_Ornithopter_hurtBy(ent_Ornithopter* obj, ent_Entity* arg1, double arg2, ent_DamageSource* arg3, ent_AttackKind* arg4, ent_AttackType* arg5, void* arg6, void* arg7);
extern void ent_Ornithopter_goToMainBase(ent_Ornithopter* obj, void* arg1);
extern EReason* ent_Ornithopter_implRpcRefreshAutoRecon(ent_Ornithopter* obj, void* arg1, ent_Zone* arg2);
extern void ent_Ornithopter_refreshAutoRecon(ent_Ornithopter* obj, void* arg1, ent_Zone* arg2);
extern void ent_Ornithopter_onReconEnd(ent_Ornithopter* obj, ent_Structure* arg1);
extern hl_types_ArrayObj* ent_Ornithopter_getReconnableStructuresInZone(ent_Ornithopter* obj, ent_Zone* arg1);
extern bool ent_Ornithopter_isStormCloseToZone(ent_Ornithopter* obj, ent_Zone* arg1);
extern ent_Structure* ent_Ornithopter_getPriorityReconnableStructureInZone(ent_Ornithopter* obj, ent_Zone* arg1);
extern void ent_Ornithopter_findAutoReconZone(ent_Ornithopter* obj, ent_Zone* arg1);
extern void ent_Ornithopter_updateAttributes(ent_Ornithopter* obj, double arg1);
extern void ent_Ornithopter_updateAlerts(ent_Ornithopter* obj);
extern void ent_Ornithopter_doRemove(ent_Ornithopter* obj);
extern void ent_Ornithopter_regularUpdate(ent_Ornithopter* obj, double arg1);
extern void ent_Ornithopter_clientRegularUpdate(ent_Ornithopter* obj, double arg1);
extern bool ent_Ornithopter_hasBeenIdle(ent_Ornithopter* obj);
extern void ent_Ornithopter_update(ent_Ornithopter* obj, double arg1);
extern double ent_Ornithopter_getZOffset(ent_Ornithopter* obj);
extern bool ent_Ornithopter_getZSmoothing(ent_Ornithopter* obj);
extern void ent_Ornithopter_fireUnitEvent(ent_Ornithopter* obj, int arg1, ent_Entity* arg2);
extern void ent_Ornithopter_die(ent_Ornithopter* obj, void* arg1);
extern void ent_Ornithopter_deathFall__impl(ent_Ornithopter* obj);
extern int ent_Ornithopter_getCLID(ent_Ornithopter* obj);
extern void ent_Ornithopter_serialize(ent_Ornithopter* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Ornithopter_getSerializeSchema(ent_Ornithopter* obj);
extern void ent_Ornithopter_unserializeInit(ent_Ornithopter* obj);
extern void ent_Ornithopter_unserialize(ent_Ornithopter* obj, hxbit_Serializer* arg1);
extern EReason* ent_Ornithopter_toggleAutonomous(ent_Ornithopter* obj, void* arg1);
extern bool ent_Ornithopter_rpcToggleAutonomous__impl(ent_Ornithopter* obj);
extern EReason* ent_Ornithopter_checkToggleAutonomous(ent_Ornithopter* obj);
extern bool ent_Ornithopter_canToggleAutonomous(ent_Ornithopter* obj);
extern EReason* ent_Ornithopter_rpcRefreshAutoRecon(ent_Ornithopter* obj, void* arg1, ent_Zone* arg2, void* arg3);
extern bool ent_Ornithopter_rpcRpcRefreshAutoRecon__impl(ent_Ornithopter* obj, void* arg1, ent_Zone* arg2);
extern EReason* ent_Ornithopter_checkRpcRefreshAutoRecon(ent_Ornithopter* obj, void* arg1, ent_Zone* arg2);
extern bool ent_Ornithopter_canRpcRefreshAutoRecon(ent_Ornithopter* obj, void* arg1, ent_Zone* arg2);
extern ent_Zone* ent_Ornithopter___net_mark_reconZone(ent_Ornithopter* obj, ent_Zone* arg1);
extern ent_Zone* ent_Ornithopter_set_reconZone(ent_Ornithopter* obj, ent_Zone* arg1);
extern int ent_Ornithopter_get_networkPropReconZone(ent_Ornithopter* obj);
extern double ent_Ornithopter___net_mark_lastDestroyChance(ent_Ornithopter* obj, double arg1);
extern double ent_Ornithopter_set_lastDestroyChance(ent_Ornithopter* obj, double arg1);
extern int ent_Ornithopter_get_networkPropLastDestroyChance(ent_Ornithopter* obj);
extern double ent_Ornithopter___net_mark_lastDestroyCheck(ent_Ornithopter* obj, double arg1);
extern double ent_Ornithopter_set_lastDestroyCheck(ent_Ornithopter* obj, double arg1);
extern int ent_Ornithopter_get_networkPropLastDestroyCheck(ent_Ornithopter* obj);
extern void ent_Ornithopter_deathFall(ent_Ornithopter* obj);
extern void ent_Ornithopter_rpcToggleAutonomous(ent_Ornithopter* obj, void* arg1);
extern void ent_Ornithopter_rpcRpcRefreshAutoRecon(ent_Ornithopter* obj, void* arg1, ent_Zone* arg2, void* arg3);
extern void ent_Ornithopter_networkFlush(ent_Ornithopter* obj, hxbit_Serializer* arg1);
extern void ent_Ornithopter_networkSync(ent_Ornithopter* obj, hxbit_Serializer* arg1);
extern bool ent_Ornithopter_networkRPC(ent_Ornithopter* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Ornithopter_networkGetName(ent_Ornithopter* obj, int arg1, void* arg2);


#endif // __gen_t_ent_Ornithopter_h__
