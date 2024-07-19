// gen time: 2024-07-14 04:39:33 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_logic_Upgrades_h__
#define __gen_t_logic_Upgrades_h__

#include <common.h>
#include <gen/t.logic.Logic.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_BaseBuilding ent_BaseBuilding;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Structure ent_Structure;
typedef struct haxe_ds_StringMap haxe_ds_StringMap;
typedef struct hl_types_ArrayBytes_Int hl_types_ArrayBytes_Int;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct logic_Upgrades logic_Upgrades;


// type: logic.Upgrades, kind: HOBJ, pType: 0x02748E3E78D8
struct logic_Upgrades {
  // super: logic.Logic
  logic_Logic               super;

  // cls: logic.Upgrades, begin_offset: 0x0090
  hxbit_ArrayProxyData*     upgrades;           // +0090: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     pending;            // +0098: HOBJ hxbit.ArrayProxyData
  ent_Entity*               entity;             // +00A0: HOBJ ent.Entity
  int                       uid;                // +00A8
  haxe_ds_StringMap*        districtBonuses;    // +00B0: HOBJ haxe.ds.StringMap
  int                       districtBonusesCount; // +00B8
  hxbit_ArrayProxyData*     districtStates;     // +00C0: HOBJ hxbit.ArrayProxyData
  int                       BASE_REGION_LIMIT;  // +00C8
  double                    lastPendingSync;    // +00D0
  hl_types_ArrayObj*        conds;              // +00D8: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        ups;                // +00E0: HOBJ hl.types.ArrayObj
  // total_size: 0x00E8
}; // logic_Upgrades (logic.Upgrades)

_Static_assert(sizeof(logic_Upgrades) == 0x00E8, "cls logic.Upgrades has wrong size");


extern ent_Structure* logic_Upgrades_get_structure(logic_Upgrades* obj);
extern ent_Structure* logic_Upgrades_get_fieldStructure(logic_Upgrades* obj);
extern hxbit_ArrayProxyData* logic_Upgrades_set_pending(logic_Upgrades* obj, hxbit_ArrayProxyData* arg1);
extern void logic_Upgrades_init(logic_Upgrades* obj);
extern void logic_Upgrades_onReady(logic_Upgrades* obj);
extern void logic_Upgrades_doRemove(logic_Upgrades* obj);
extern ent_Faction* logic_Upgrades_get_factionOwner(logic_Upgrades* obj);
extern bool logic_Upgrades_isEmpty(logic_Upgrades* obj);
extern hl_types_ArrayObj* logic_Upgrades_all(logic_Upgrades* obj, void* arg1);
extern hl_types_ArrayObj* logic_Upgrades_allUpgrades(logic_Upgrades* obj, void* arg1, hl_types_ArrayObj* arg2);
extern hl_types_ArrayObj* logic_Upgrades_allUpgradesInProgress(logic_Upgrades* obj, void* arg1, hl_types_ArrayObj* arg2);
extern hl_types_ArrayObj* logic_Upgrades_allContainedUpgrades(logic_Upgrades* obj, void* arg1);
extern int logic_Upgrades_domainCount(logic_Upgrades* obj, String* arg1, String* arg2, void* arg3);
extern hl_types_ArrayObj* logic_Upgrades_getAllInProgress(logic_Upgrades* obj, void* arg1);
extern hl_types_ArrayObj* logic_Upgrades_getAllContained(logic_Upgrades* obj, void* arg1, void* arg2);
extern int logic_Upgrades_getMasterpiecesCount(logic_Upgrades* obj, void* arg1);
extern hl_types_ArrayObj* logic_Upgrades_getAllMasterpieces(logic_Upgrades* obj, void* arg1);
extern bool logic_Upgrades_isMasterpiece(logic_Upgrades* obj, int arg1);
extern bool logic_Upgrades_isUpgradeMasterpiece(logic_Upgrades* obj, void* arg1);
extern bool logic_Upgrades_has(logic_Upgrades* obj, int arg1);
extern void* logic_Upgrades_get(logic_Upgrades* obj, int arg1);
extern void* logic_Upgrades_getInfo(logic_Upgrades* obj, int arg1);
extern void* logic_Upgrades_getPending(logic_Upgrades* obj, int arg1);
extern void* logic_Upgrades_getPendingKind(logic_Upgrades* obj, String* arg1, void* arg2);
extern bool logic_Upgrades_contains(logic_Upgrades* obj, int arg1);
extern bool logic_Upgrades_hasKind(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3);
extern void* logic_Upgrades_getKind(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3);
extern bool logic_Upgrades_containsKind(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3);
extern bool logic_Upgrades_isRemoving(logic_Upgrades* obj, int arg1);
extern int logic_Upgrades_getIsolatedLimit(logic_Upgrades* obj, String* arg1);
extern int logic_Upgrades_getLimit(logic_Upgrades* obj, String* arg1);
extern int logic_Upgrades_getFactionLimit(logic_Upgrades* obj, String* arg1);
extern int logic_Upgrades_getKindCount(logic_Upgrades* obj, String* arg1, void* arg2);
extern void* logic_Upgrades_getDistrictIndex(logic_Upgrades* obj, int arg1);
extern int logic_Upgrades_getDistrictBonusNb(logic_Upgrades* obj, String* arg1, int arg2);
extern int logic_Upgrades_getDistrictBonusCount(logic_Upgrades* obj);
extern int logic_Upgrades_getMaxDistrictLevel(logic_Upgrades* obj, String* arg1);
extern void logic_Upgrades_clear(logic_Upgrades* obj);
extern bool logic_Upgrades_isDestroyedOnClear(logic_Upgrades* obj, void* arg1);
extern void logic_Upgrades_cancelAllPending(logic_Upgrades* obj);
extern void logic_Upgrades_onChangeOwner(logic_Upgrades* obj, ent_Faction* arg1, ent_Faction* arg2);
extern EReason* logic_Upgrades_implCancelUpgrade(logic_Upgrades* obj, int arg1, void* arg2, hl_types_ArrayObj* arg3);
extern hl_types_ArrayObj* logic_Upgrades_getRefund(logic_Upgrades* obj, void* arg1, void* arg2);
extern double logic_Upgrades_getRefundRate(logic_Upgrades* obj);
extern hl_types_ArrayObj* logic_Upgrades_getLootingValue(logic_Upgrades* obj, String* arg1, double arg2);
extern EReason* logic_Upgrades_implRemoveUpgrade(logic_Upgrades* obj, int arg1, void* arg2);
extern void logic_Upgrades_demolishUpgrade(logic_Upgrades* obj, int arg1);
extern ent_BaseBuilding* logic_Upgrades_findBuilding(logic_Upgrades* obj, int arg1);
extern void logic_Upgrades_destroyUpgrade(logic_Upgrades* obj, int arg1);
extern void logic_Upgrades_doRemoveUpgrade(logic_Upgrades* obj, int arg1, void* arg2, void* arg3);
extern bool logic_Upgrades_allowMultipleUpgradeSlots(logic_Upgrades* obj, void* arg1);
extern EReason* logic_Upgrades_checkAnyAddUpgrade(logic_Upgrades* obj, void* arg1, void* arg2, void* arg3);
extern EReason* logic_Upgrades_implAddUpgrade(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6);
extern void* logic_Upgrades_forceAddUpgrade(logic_Upgrades* obj, String* arg1, int arg2, void* arg3, hl_types_ArrayObj* arg4);
extern void* logic_Upgrades_doAddUpgrade(logic_Upgrades* obj, int arg1, String* arg2, int arg3, void* arg4, hl_types_ArrayObj* arg5);
extern void logic_Upgrades_updateState(logic_Upgrades* obj, int arg1, int arg2);
extern void logic_Upgrades_setState(logic_Upgrades* obj, void* arg1, int arg2);
extern void logic_Upgrades_addAttributes(logic_Upgrades* obj, void* arg1, int arg2);
extern void logic_Upgrades_removeAttributes(logic_Upgrades* obj, void* arg1);
extern logic_AttributeApplication* logic_Upgrades_getUpgradeAtbApp(logic_Upgrades* obj, void* arg1, String* arg2);
extern void logic_Upgrades_onChange(logic_Upgrades* obj);
extern haxe_ds_StringMap* logic_Upgrades_getSplitedDistrictBonus(logic_Upgrades* obj, int arg1, int arg2);
extern haxe_ds_StringMap* logic_Upgrades_getRegularDisctrictBonuses(logic_Upgrades* obj, int arg1, int arg2);
extern haxe_ds_StringMap* logic_Upgrades_getDisctrictBonuses(logic_Upgrades* obj, int arg1, int arg2);
extern void logic_Upgrades_rpcSyncDistricts__impl(logic_Upgrades* obj);
extern void logic_Upgrades_syncDistricts(logic_Upgrades* obj, void* arg1);
extern void logic_Upgrades_sendCompletionAlerts(logic_Upgrades* obj, String* arg1);
extern hl_types_ArrayObj* logic_Upgrades_getAttributes(logic_Upgrades* obj, String* arg1, int arg2);
extern hl_types_ArrayBytes_Int* logic_Upgrades_getAllDistrictSlotTypes(logic_Upgrades* obj);
extern hl_types_ArrayObj* logic_Upgrades_getCost(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3);
extern double logic_Upgrades_getUpkeepFlatModif(logic_Upgrades* obj, String* arg1, String* arg2);
extern double logic_Upgrades_getUpkeepFactor(logic_Upgrades* obj, String* arg1, String* arg2);
extern void* logic_Upgrades_getDuration(logic_Upgrades* obj, String* arg1, void* arg2);
extern hl_types_ArrayObj* logic_Upgrades_getCompatibleUpgrades(logic_Upgrades* obj);
extern bool logic_Upgrades_inProgress(logic_Upgrades* obj, int arg1);
extern bool logic_Upgrades_inProgressKind(logic_Upgrades* obj, String* arg1, void* arg2);
extern double logic_Upgrades_getProgressSpeed(logic_Upgrades* obj, String* arg1, void* arg2);
extern double logic_Upgrades_getProgress(logic_Upgrades* obj, int arg1);
extern double logic_Upgrades_getEstimatedProgress(logic_Upgrades* obj, int arg1);
extern int logic_Upgrades_getAnyFreeDistrict(logic_Upgrades* obj);
extern void logic_Upgrades_updateReminderAlert(logic_Upgrades* obj);
extern void logic_Upgrades_regularUpdate(logic_Upgrades* obj, double arg1);
extern double logic_Upgrades_getUpgradeFactor(logic_Upgrades* obj, String* arg1);
extern void logic_Upgrades_updateAttributes(logic_Upgrades* obj, void* arg1, void* arg2);
extern void logic_Upgrades_reload(logic_Upgrades* obj);
extern void logic_Upgrades_structPatchEntity(logic_Upgrades* obj, int arg1);
extern EReason* logic_Upgrades_checkBlockingReasons(logic_Upgrades* obj, void* arg1);
extern void logic_Upgrades_updateBuildingStates(logic_Upgrades* obj);
extern int logic_Upgrades_getBuildingState(logic_Upgrades* obj, void* arg1);
extern bool logic_Upgrades_getBuildingWorkingConditions(logic_Upgrades* obj, void* arg1);
extern bool logic_Upgrades_buildingsAreWorking(logic_Upgrades* obj);
extern hl_types_ArrayObj* logic_Upgrades_getDisabledUpgrades(logic_Upgrades* obj);
extern int logic_Upgrades_getCLID(logic_Upgrades* obj);
extern void logic_Upgrades_serialize(logic_Upgrades* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_Upgrades_getSerializeSchema(logic_Upgrades* obj);
extern void logic_Upgrades_unserializeInit(logic_Upgrades* obj);
extern void logic_Upgrades_unserialize(logic_Upgrades* obj, hxbit_Serializer* arg1);
extern EReason* logic_Upgrades_cancelUpgrade(logic_Upgrades* obj, int arg1, void* arg2, hl_types_ArrayObj* arg3, void* arg4);
extern bool logic_Upgrades_rpcCancelUpgrade__impl(logic_Upgrades* obj, int arg1, void* arg2, hl_types_ArrayObj* arg3);
extern EReason* logic_Upgrades_checkCancelUpgrade(logic_Upgrades* obj, int arg1, void* arg2, hl_types_ArrayObj* arg3);
extern bool logic_Upgrades_canCancelUpgrade(logic_Upgrades* obj, int arg1, void* arg2, hl_types_ArrayObj* arg3);
extern EReason* logic_Upgrades_removeUpgrade(logic_Upgrades* obj, int arg1, void* arg2, void* arg3);
extern bool logic_Upgrades_rpcRemoveUpgrade__impl(logic_Upgrades* obj, int arg1, void* arg2);
extern EReason* logic_Upgrades_checkRemoveUpgrade(logic_Upgrades* obj, int arg1, void* arg2);
extern bool logic_Upgrades_canRemoveUpgrade(logic_Upgrades* obj, int arg1, void* arg2);
extern EReason* logic_Upgrades_addUpgrade(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7);
extern bool logic_Upgrades_rpcAddUpgrade__impl(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6);
extern EReason* logic_Upgrades_checkAddUpgrade(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6);
extern bool logic_Upgrades_canAddUpgrade(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6);
extern hxbit_ArrayProxyData* logic_Upgrades___net_mark_upgrades(logic_Upgrades* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_Upgrades_set_upgrades(logic_Upgrades* obj, hxbit_ArrayProxyData* arg1);
extern int logic_Upgrades_get_networkPropUpgrades(logic_Upgrades* obj);
extern hxbit_ArrayProxyData* logic_Upgrades___net_mark_pending(logic_Upgrades* obj, hxbit_ArrayProxyData* arg1);
extern int logic_Upgrades_get_networkPropPending(logic_Upgrades* obj);
extern ent_Entity* logic_Upgrades___net_mark_entity(logic_Upgrades* obj, ent_Entity* arg1);
extern ent_Entity* logic_Upgrades_set_entity(logic_Upgrades* obj, ent_Entity* arg1);
extern int logic_Upgrades_get_networkPropEntity(logic_Upgrades* obj);
extern int logic_Upgrades___net_mark_uid(logic_Upgrades* obj, int arg1);
extern int logic_Upgrades_set_uid(logic_Upgrades* obj, int arg1);
extern int logic_Upgrades_get_networkPropUid(logic_Upgrades* obj);
extern hxbit_ArrayProxyData* logic_Upgrades___net_mark_districtStates(logic_Upgrades* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_Upgrades_set_districtStates(logic_Upgrades* obj, hxbit_ArrayProxyData* arg1);
extern int logic_Upgrades_get_networkPropDistrictStates(logic_Upgrades* obj);
extern void logic_Upgrades_rpcSyncDistricts(logic_Upgrades* obj);
extern void logic_Upgrades_rpcCancelUpgrade(logic_Upgrades* obj, int arg1, void* arg2, hl_types_ArrayObj* arg3, void* arg4);
extern void logic_Upgrades_rpcRemoveUpgrade(logic_Upgrades* obj, int arg1, void* arg2, void* arg3);
extern void logic_Upgrades_rpcAddUpgrade(logic_Upgrades* obj, String* arg1, void* arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7);
extern void logic_Upgrades_networkFlush(logic_Upgrades* obj, hxbit_Serializer* arg1);
extern void logic_Upgrades_networkSync(logic_Upgrades* obj, hxbit_Serializer* arg1);
extern void logic_Upgrades_networkInitProxys(logic_Upgrades* obj);
extern bool logic_Upgrades_networkRPC(logic_Upgrades* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_Upgrades_networkGetName(logic_Upgrades* obj, int arg1, void* arg2);


#endif // __gen_t_logic_Upgrades_h__
