// gen time: 2024-07-14 16:21:58 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_Harvester_h__
#define __gen_t_ent_Harvester_h__

#include <common.h>
#include <gen/t.ent.SpiceHarvester.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Carrier ent_Carrier;
typedef struct ent_EState ent_EState;
typedef struct ent_EStatus ent_EStatus;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Harvester ent_Harvester;
typedef struct ent_Ornithopter ent_Ornithopter;
typedef struct ent_Refinery ent_Refinery;
typedef struct ent_Sandworm ent_Sandworm;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct h3d_scene_Object h3d_scene_Object;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct prefab_FXAnimation prefab_FXAnimation;


// type: ent.Harvester, kind: HOBJ, pType: 0x01EC714D2178
struct ent_Harvester {
  // super: ent.SpiceHarvester
  ent_SpiceHarvester        super;

  // cls: ent.Harvester, begin_offset: 0x04D1
  ent_EStatus*              status;             // +04D8: HENUM ent.EStatus
  ent_Carrier*              lastCarrier;        // +04E0: HOBJ ent.Carrier
  ent_Ornithopter*          assignedOrnithopter; // +04E8: HOBJ ent.Ornithopter
  bool                      wantsSafeMode;      // +04F0
  h3d_scene_Object*         tracks;             // +04F8: HOBJ h3d.scene.Object
  hl_types_ArrayObj*        tracksEmitters;     // +0500: HOBJ hl.types.ArrayObj
  prefab_FXAnimation*       curFX;              // +0508: HOBJ prefab.FXAnimation
  // total_size: 0x0510
}; // ent_Harvester (ent.Harvester)

_Static_assert(sizeof(ent_Harvester) == 0x0510, "cls ent.Harvester has wrong size");


extern bool ent_Harvester_get_isOrnithopterAssigned(ent_Harvester* obj);
extern ent_Refinery* ent_Harvester_get_refinery(ent_Harvester* obj);
extern String* ent_Harvester_getHarvesterKind(ent_Harvester* obj, String* arg1);
extern void ent_Harvester_finalize(ent_Harvester* obj);
extern bool ent_Harvester_isSafe(ent_Harvester* obj);
extern bool ent_Harvester_canBeAttacked(ent_Harvester* obj, ent_Faction* arg1);
extern bool ent_Harvester_canBeRaidedBy(ent_Harvester* obj, String* arg1);
extern void ent_Harvester_onFollowed(ent_Harvester* obj, ent_Entity* arg1, bool arg2);
extern bool ent_Harvester_get_neverWormTarget(ent_Harvester* obj);
extern bool ent_Harvester_isIdle(ent_Harvester* obj);
extern bool ent_Harvester_canBeWormTarget(ent_Harvester* obj, void* arg1);
extern double ent_Harvester_getWormEatChance(ent_Harvester* obj);
extern bool ent_Harvester_isCloseToBase(ent_Harvester* obj);
extern ent_EStatus* ent_Harvester_set_status(ent_Harvester* obj, ent_EStatus* arg1);
extern ent_EState* ent_Harvester_getState(ent_Harvester* obj);
extern bool ent_Harvester_isProducing(ent_Harvester* obj);
extern bool ent_Harvester_isHome(ent_Harvester* obj);
extern double ent_Harvester_getCurrentVibrations(ent_Harvester* obj);
extern double ent_Harvester_getRotatingMoveSpeedFactor(ent_Harvester* obj, double arg1);
extern void ent_Harvester_startWorking(ent_Harvester* obj);
extern bool ent_Harvester_isAutonomous(ent_Harvester* obj);
extern EReason* ent_Harvester_implToggleAutonomous(ent_Harvester* obj);
extern void ent_Harvester_setAutonomous(ent_Harvester* obj, bool arg1);
extern bool ent_Harvester_canActivateSafeMode(ent_Harvester* obj);
extern bool ent_Harvester_isInSafeMode(ent_Harvester* obj);
extern EReason* ent_Harvester_implTryActivateSafeMode(ent_Harvester* obj);
extern EReason* ent_Harvester_implToggleHarvestSafeMode(ent_Harvester* obj);
extern EReason* ent_Harvester_implToggleHarvestGreedMode(ent_Harvester* obj);
extern void ent_Harvester_setHarvestMode(ent_Harvester* obj, bool arg1);
extern bool ent_Harvester_canAutoRecall(ent_Harvester* obj);
extern bool ent_Harvester_canAutoDeploy(ent_Harvester* obj);
extern void ent_Harvester_onTransitPickup(ent_Harvester* obj);
extern void ent_Harvester_onTransitDrop(ent_Harvester* obj, h2d_col_PointImpl* arg1);
extern void ent_Harvester_doActionInternal(ent_Harvester* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern bool ent_Harvester_canRepair(ent_Harvester* obj);
extern void ent_Harvester_finishRepair(ent_Harvester* obj);
extern void ent_Harvester_initVisual(ent_Harvester* obj);
extern void ent_Harvester_init(ent_Harvester* obj);
extern void ent_Harvester_playDeath__impl(ent_Harvester* obj);
extern void ent_Harvester_playDeathWorm__impl(ent_Harvester* obj, ent_Sandworm* arg1);
extern void ent_Harvester_doRemoveVisual(ent_Harvester* obj);
extern void ent_Harvester_update(ent_Harvester* obj, double arg1);
extern void ent_Harvester_refreshInactive(ent_Harvester* obj);
extern void ent_Harvester_refreshAlert(ent_Harvester* obj, bool arg1);
extern void ent_Harvester_regularUpdate(ent_Harvester* obj, double arg1);
extern hrt_prefab_Resource* ent_Harvester_getWorkingFx(ent_Harvester* obj);
extern void ent_Harvester_frameUpdate(ent_Harvester* obj, double arg1);
extern void ent_Harvester_updateProducingFX(ent_Harvester* obj);
extern void ent_Harvester_doRemove(ent_Harvester* obj);
extern bool ent_Harvester_canAutoRemoveVisual(ent_Harvester* obj);
extern EReason* ent_Harvester_implRequestDeploy(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_playCancelFeedback__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_implCancelDeploy(ent_Harvester* obj);
extern bool ent_Harvester_hasRecallRequest(ent_Harvester* obj);
extern bool ent_Harvester_hasDeployRequest(ent_Harvester* obj);
extern void ent_Harvester_doRecall(ent_Harvester* obj);
extern void ent_Harvester_cancelDeploying(ent_Harvester* obj);
extern void ent_Harvester_playRecallFeedback__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_implRequestRecall(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_forceRecall(ent_Harvester* obj);
extern EReason* ent_Harvester_implCancelRecall(ent_Harvester* obj);
extern hl_types_ArrayObj* ent_Harvester_getAffectingAtbApps(ent_Harvester* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern EReason* ent_Harvester_toggleAutonomous(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_rpcToggleAutonomous__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_checkToggleAutonomous(ent_Harvester* obj);
extern bool ent_Harvester_canToggleAutonomous(ent_Harvester* obj);
extern EReason* ent_Harvester_tryActivateSafeMode(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_rpcTryActivateSafeMode__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_checkTryActivateSafeMode(ent_Harvester* obj);
extern bool ent_Harvester_canTryActivateSafeMode(ent_Harvester* obj);
extern EReason* ent_Harvester_toggleHarvestSafeMode(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_rpcToggleHarvestSafeMode__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_checkToggleHarvestSafeMode(ent_Harvester* obj);
extern bool ent_Harvester_canToggleHarvestSafeMode(ent_Harvester* obj);
extern EReason* ent_Harvester_toggleHarvestGreedMode(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_rpcToggleHarvestGreedMode__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_checkToggleHarvestGreedMode(ent_Harvester* obj);
extern bool ent_Harvester_canToggleHarvestGreedMode(ent_Harvester* obj);
extern EReason* ent_Harvester_requestDeploy(ent_Harvester* obj, void* arg1, void* arg2);
extern bool ent_Harvester_rpcRequestDeploy__impl(ent_Harvester* obj, void* arg1);
extern EReason* ent_Harvester_checkRequestDeploy(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_canRequestDeploy(ent_Harvester* obj, void* arg1);
extern EReason* ent_Harvester_cancelDeploy(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_rpcCancelDeploy__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_checkCancelDeploy(ent_Harvester* obj);
extern bool ent_Harvester_canCancelDeploy(ent_Harvester* obj);
extern EReason* ent_Harvester_requestRecall(ent_Harvester* obj, void* arg1, void* arg2);
extern bool ent_Harvester_rpcRequestRecall__impl(ent_Harvester* obj, void* arg1);
extern EReason* ent_Harvester_checkRequestRecall(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_canRequestRecall(ent_Harvester* obj, void* arg1);
extern EReason* ent_Harvester_cancelRecall(ent_Harvester* obj, void* arg1);
extern bool ent_Harvester_rpcCancelRecall__impl(ent_Harvester* obj);
extern EReason* ent_Harvester_checkCancelRecall(ent_Harvester* obj);
extern bool ent_Harvester_canCancelRecall(ent_Harvester* obj);
extern ent_EStatus* ent_Harvester___net_mark_status(ent_Harvester* obj, ent_EStatus* arg1);
extern int ent_Harvester_get_networkPropStatus(ent_Harvester* obj);
extern ent_Carrier* ent_Harvester___net_mark_lastCarrier(ent_Harvester* obj, ent_Carrier* arg1);
extern ent_Carrier* ent_Harvester_set_lastCarrier(ent_Harvester* obj, ent_Carrier* arg1);
extern int ent_Harvester_get_networkPropLastCarrier(ent_Harvester* obj);
extern ent_Ornithopter* ent_Harvester___net_mark_assignedOrnithopter(ent_Harvester* obj, ent_Ornithopter* arg1);
extern ent_Ornithopter* ent_Harvester_set_assignedOrnithopter(ent_Harvester* obj, ent_Ornithopter* arg1);
extern int ent_Harvester_get_networkPropAssignedOrnithopter(ent_Harvester* obj);
extern bool ent_Harvester___net_mark_wantsSafeMode(ent_Harvester* obj, bool arg1);
extern bool ent_Harvester_set_wantsSafeMode(ent_Harvester* obj, bool arg1);
extern int ent_Harvester_get_networkPropWantsSafeMode(ent_Harvester* obj);
extern void ent_Harvester_playDeathWorm(ent_Harvester* obj, ent_Sandworm* arg1);
extern void ent_Harvester_playCancelFeedback(ent_Harvester* obj);
extern void ent_Harvester_playRecallFeedback(ent_Harvester* obj);
extern void ent_Harvester_rpcToggleAutonomous(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_rpcTryActivateSafeMode(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_rpcToggleHarvestSafeMode(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_rpcToggleHarvestGreedMode(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_rpcRequestDeploy(ent_Harvester* obj, void* arg1, void* arg2);
extern void ent_Harvester_rpcCancelDeploy(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_rpcRequestRecall(ent_Harvester* obj, void* arg1, void* arg2);
extern void ent_Harvester_rpcCancelRecall(ent_Harvester* obj, void* arg1);
extern void ent_Harvester_networkFlush(ent_Harvester* obj, hxbit_Serializer* arg1);
extern void ent_Harvester_networkSync(ent_Harvester* obj, hxbit_Serializer* arg1);
extern bool ent_Harvester_networkRPC(ent_Harvester* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Harvester_networkGetName(ent_Harvester* obj, int arg1, void* arg2);
extern int ent_Harvester_getCLID(ent_Harvester* obj);
extern void ent_Harvester_serialize(ent_Harvester* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Harvester_getSerializeSchema(ent_Harvester* obj);
extern void ent_Harvester_unserializeInit(ent_Harvester* obj);
extern void ent_Harvester_unserialize(ent_Harvester* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_Harvester_h__
