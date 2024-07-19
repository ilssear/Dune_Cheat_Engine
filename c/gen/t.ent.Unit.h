// gen time: 2024-07-19 08:03:59 UTC, pid: 0x00002F70 (12144)

#ifndef __gen_t_ent_Unit_h__
#define __gen_t_ent_Unit_h__

#include <common.h>
#include <gen/t.ent.MobileEntity.h>

typedef struct DisplayTarget DisplayTarget;
typedef struct EReason EReason;
typedef struct ETargetKind ETargetKind;
typedef struct ProductionKind ProductionKind;
typedef struct String String;
typedef struct ent_ActionEndReason ent_ActionEndReason;
typedef struct ent_AttackKind ent_AttackKind;
typedef struct ent_AttackType ent_AttackType;
typedef struct ent_DamageSource ent_DamageSource;
typedef struct ent_DeathReason ent_DeathReason;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_GamePlane ent_GamePlane;
typedef struct ent_Sandworm ent_Sandworm;
typedef struct ent_State ent_State;
typedef struct ent_Structure ent_Structure;
typedef struct ent_Unit ent_Unit;
typedef struct ent_Zone ent_Zone;
typedef struct ent_comp_HarvestComponent ent_comp_HarvestComponent;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct h3d_VectorImpl h3d_VectorImpl;
typedef struct h3d_scene_Interactive h3d_scene_Interactive;
typedef struct h3d_scene_Object h3d_scene_Object;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_Application logic_Application;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct logic_ai_AIOrder logic_ai_AIOrder;
typedef struct prefab_FXAnimation prefab_FXAnimation;


// type: ent.Unit, kind: HOBJ, pType: 0x02117AB70B98
struct ent_Unit {
  // super: ent.MobileEntity
  ent_MobileEntity          super;

  // cls: ent.Unit, begin_offset: 0x0428
  String*                   kind;               // +0428: HOBJ String
  bool                      repairing;          // +0430
  void*                     inf;                // +0438: HVIRTUAL
  ent_Sandworm*             targettedByWorm;    // +0440: HOBJ ent.Sandworm
  ent_Sandworm*             lastWorm;           // +0448: HOBJ ent.Sandworm
  void*                     nativeTrait;        // +0450: HVIRTUAL
  hl_types_ArrayObj*        eventFxs;           // +0458: HOBJ hl.types.ArrayObj
  h3d_scene_Interactive*    int;                // +0460: HOBJ h3d.scene.Interactive
  double                    speedFactor;        // +0468
  double                    deployLockEnd;      // +0470
  hl_types_ArrayObj*        cameras;            // +0478: HOBJ hl.types.ArrayObj
  ETargetKind*              targetKind;         // +0480: HENUM ETargetKind
  ent_comp_HarvestComponent* harvestComponent;  // +0488: HOBJ ent.comp.HarvestComponent
  hxbit_ArrayProxyData*     deathBlockers;      // +0490: HOBJ hxbit.ArrayProxyData
  bool                      awaitingDeath;      // +0498
  logic_ai_AIOrder*         aiOrder;            // +04A0: HOBJ logic.ai.AIOrder
  DisplayTarget*            _displayTarget;     // +04A8: HENUM DisplayTarget
  int                       maxLevel;           // +04B0
  DisplayTarget*            abilityDisplayTgt;  // +04B8: HENUM DisplayTarget
  prefab_FXAnimation*       vibrationsFX;       // +04C0: HOBJ prefab.FXAnimation
  hl_types_ArrayObj*        vibrationsEmitters; // +04C8: HOBJ hl.types.ArrayObj
  bool                      playingDeath;       // +04D0
  // total_size: 0x04D1
}; // ent_Unit (ent.Unit)

_Static_assert(sizeof(ent_Unit) == 0x04D8, "cls ent.Unit has wrong size");


extern String* ent_Unit_get_name(ent_Unit* obj);
extern void ent_Unit_patchEntity(ent_Unit* obj, int arg1);
extern void* ent_Unit_get_stats(ent_Unit* obj);
extern void ent_Unit_init(ent_Unit* obj);
extern void ent_Unit_refreshNativeTrait(ent_Unit* obj);
extern void ent_Unit_setupComponents(ent_Unit* obj);
extern void ent_Unit_onReady(ent_Unit* obj);
extern String* ent_Unit_get_baseKind(ent_Unit* obj);
extern double ent_Unit_getDeployTime(ent_Unit* obj);
extern double ent_Unit_getDeployTimeModifier(ent_Unit* obj);
extern bool ent_Unit_isDeployed(ent_Unit* obj);
extern bool ent_Unit_isDeployable(ent_Unit* obj);
extern bool ent_Unit_canDeploy(ent_Unit* obj);
extern bool ent_Unit_tryDeploy(ent_Unit* obj);
extern bool ent_Unit_canUndeploy(ent_Unit* obj);
extern bool ent_Unit_canAutoUndeploy(ent_Unit* obj);
extern bool ent_Unit_tryUndeploy(ent_Unit* obj, void* arg1);
extern void ent_Unit_deploy(ent_Unit* obj, void* arg1);
extern void ent_Unit_convertToUnitKind(ent_Unit* obj, String* arg1);
extern void ent_Unit_rpcConvertToUnitKind__impl(ent_Unit* obj, String* arg1, String* arg2);
extern void ent_Unit_swapModels(ent_Unit* obj, void* arg1, void* arg2);
extern void ent_Unit_onConvertKind(ent_Unit* obj, String* arg1, String* arg2);
extern void ent_Unit_rpcPlayDeployFeedback__impl(ent_Unit* obj);
extern void ent_Unit_playDeployFeedback(ent_Unit* obj);
extern bool ent_Unit_isInDeployLock(ent_Unit* obj);
extern bool ent_Unit_isInLock(ent_Unit* obj);
extern void* ent_Unit_get_bannerIcon(ent_Unit* obj);
extern int ent_Unit_getBannerWidgetPriority(ent_Unit* obj);
extern bool ent_Unit_isFlagVisible(ent_Unit* obj);
extern bool ent_Unit_canShowAlignment(ent_Unit* obj);
extern void ent_Unit_applyNaturalTraits(ent_Unit* obj);
extern void* ent_Unit_getClass(ent_Unit* obj);
extern String* ent_Unit_getClassId(ent_Unit* obj);
extern void* ent_Unit_getLogData(ent_Unit* obj);
extern String* ent_Unit_set_kind(ent_Unit* obj, String* arg1);
extern String* ent_Unit_getRefundTitle(ent_Unit* obj, void* arg1);
extern String* ent_Unit_getRefundDesc(ent_Unit* obj);
extern double ent_Unit_getReconRate(ent_Unit* obj);
extern double ent_Unit_getBaseMaxLife(ent_Unit* obj);
extern double ent_Unit_getBaseArmor(ent_Unit* obj);
extern double ent_Unit_getMaxLifeAdditiveModifier(ent_Unit* obj);
extern bool ent_Unit_hasPower(ent_Unit* obj);
extern bool ent_Unit_hasLife(ent_Unit* obj);
extern double ent_Unit_getBasePower(ent_Unit* obj);
extern double ent_Unit_getPowerModifier(ent_Unit* obj, void* arg1);
extern h3d_VectorImpl* ent_Unit_getDefaultProjectileOrigin(ent_Unit* obj);
extern bool ent_Unit_canAttackWithNoTarget(ent_Unit* obj);
extern bool ent_Unit_hasAttacks(ent_Unit* obj);
extern hl_types_ArrayObj* ent_Unit_getAttackCombos(ent_Unit* obj, hl_types_ArrayObj* arg1);
extern double ent_Unit_getBaseAttackRange(ent_Unit* obj);
extern double ent_Unit_getFlatModifierRange(ent_Unit* obj);
extern double ent_Unit_getMinRange(ent_Unit* obj);
extern double ent_Unit_getDefenseFactor(ent_Unit* obj, ent_Entity* arg1, ent_DamageSource* arg2, void* arg3, ent_AttackKind* arg4);
extern double ent_Unit_get_modelScale(ent_Unit* obj);
extern bool ent_Unit_set_repairing(ent_Unit* obj, bool arg1);
extern String* ent_Unit_getExposedName(ent_Unit* obj);
extern String* ent_Unit_getNightTrait(ent_Unit* obj);
extern void ent_Unit_regularUpdate(ent_Unit* obj, double arg1);
extern void ent_Unit_updateAlerts(ent_Unit* obj);
extern void ent_Unit_updateAttributes(ent_Unit* obj, double arg1);
extern void ent_Unit_onTraitStart(ent_Unit* obj, logic_Application* arg1);
extern void ent_Unit_onTraitEnd(ent_Unit* obj, logic_Application* arg1, bool arg2);
extern logic_AttributeApplication* ent_Unit_addAttributeRaw(ent_Unit* obj, int arg1, void* arg2);
extern void ent_Unit_updateTraitBlockers(ent_Unit* obj);
extern void ent_Unit_fireUnitEventRpc__impl(ent_Unit* obj, int arg1, ent_Entity* arg2);
extern bool ent_Unit_hasUnitEvent(ent_Unit* obj, int arg1);
extern void ent_Unit_fireUnitEvent(ent_Unit* obj, int arg1, ent_Entity* arg2);
extern void ent_Unit_tryFireUnitEvent(ent_Unit* obj, int arg1, ent_Entity* arg2);
extern void ent_Unit_updateUnitEvents(ent_Unit* obj);
extern double ent_Unit_getDamageModifier(ent_Unit* obj, ent_Entity* arg1, void* arg2);
extern bool ent_Unit_isPlayingUnitEvent(ent_Unit* obj, int arg1);
extern hl_types_ArrayObj* ent_Unit_getUnitEventsOverride(ent_Unit* obj);
extern void ent_Unit_killUnitEventRpc__impl(ent_Unit* obj, int arg1);
extern void ent_Unit_killUnitEvent(ent_Unit* obj, int arg1, void* arg2);
extern bool ent_Unit_isHero(ent_Unit* obj);
extern bool ent_Unit_isMilitary(ent_Unit* obj);
extern bool ent_Unit_isMechanical(ent_Unit* obj);
extern bool ent_Unit_isHuman(ent_Unit* obj);
extern bool ent_Unit_isElite(ent_Unit* obj);
extern bool ent_Unit_isOrni(ent_Unit* obj);
extern bool ent_Unit_isHarvester(ent_Unit* obj);
extern bool ent_Unit_isAerial(ent_Unit* obj);
extern bool ent_Unit_isDrone(ent_Unit* obj);
extern bool ent_Unit_isInfantry(ent_Unit* obj);
extern bool ent_Unit_isAnimal(ent_Unit* obj);
extern bool ent_Unit_isShip(ent_Unit* obj);
extern bool ent_Unit_isFrigate(ent_Unit* obj);
extern bool ent_Unit_isEcazChampion(ent_Unit* obj);
extern bool ent_Unit_isConscript(ent_Unit* obj);
extern void ent_Unit_initVisual(ent_Unit* obj);
extern void ent_Unit_initModel(ent_Unit* obj, h3d_scene_Object* arg1);
extern void ent_Unit_finalize(ent_Unit* obj);
extern void ent_Unit_postInitVisual(ent_Unit* obj);
extern bool ent_Unit_get_selected(ent_Unit* obj);
extern void ent_Unit_onSelect(ent_Unit* obj, void* arg1);
extern void ent_Unit_onDoubleSelect(ent_Unit* obj);
extern bool ent_Unit_canBeSelected(ent_Unit* obj);
extern bool ent_Unit_canBeGroupSelected(ent_Unit* obj);
extern String* ent_Unit_getBaseKind(ent_Unit* obj);
extern void* ent_Unit_getBaseInf(ent_Unit* obj);
extern bool ent_Unit_matchesKind(ent_Unit* obj, String* arg1);
extern bool ent_Unit_isSameUnitType(ent_Unit* obj, ent_Unit* arg1);
extern void ent_Unit_onUnselect(ent_Unit* obj);
extern String* ent_Unit_getAlignmentColor(ent_Unit* obj, void* arg1);
extern void* ent_Unit_getDataModel(ent_Unit* obj);
extern void ent_Unit_selectFeedback(ent_Unit* obj, void* arg1);
extern void ent_Unit_onOver(ent_Unit* obj);
extern void ent_Unit_onOut(ent_Unit* obj);
extern bool ent_Unit_isModelVisibleForFaction(ent_Unit* obj, ent_Faction* arg1);
extern bool ent_Unit_isGameplayVisibleForFaction(ent_Unit* obj, ent_Faction* arg1);
extern void ent_Unit_refreshCombatWith(ent_Unit* obj, ent_Entity* arg1, void* arg2, void* arg3);
extern void ent_Unit_endCombat(ent_Unit* obj);
extern ent_GamePlane* ent_Unit_get_plane(ent_Unit* obj);
extern double ent_Unit_getZOffset(ent_Unit* obj);
extern void ent_Unit_onDeath(ent_Unit* obj, ent_DeathReason* arg1);
extern void ent_Unit_onZoneChange(ent_Unit* obj, ent_Zone* arg1);
extern void ent_Unit_deliverLoot(ent_Unit* obj, hl_types_ArrayObj* arg1, void* arg2);
extern int ent_Unit_calcPower(ent_Unit* obj, void* arg1);
extern bool ent_Unit_isNearAllyBase(ent_Unit* obj);
extern bool ent_Unit_canRepair(ent_Unit* obj);
extern void ent_Unit_finishRepair(ent_Unit* obj);
extern void ent_Unit_updateStructure(ent_Unit* obj, double arg1);
extern void ent_Unit_reload(ent_Unit* obj);
extern double ent_Unit_getResourceProduction(ent_Unit* obj, int arg1, void* arg2, ProductionKind* arg3, void* arg4, void* arg5);
extern hl_types_ArrayObj* ent_Unit_getRefund(ent_Unit* obj);
extern EReason* ent_Unit_getNoRefundReason(ent_Unit* obj);
extern void ent_Unit_doRequestRefund(ent_Unit* obj);
extern EReason* ent_Unit_implDisband(ent_Unit* obj);
extern void ent_Unit_doDisband(ent_Unit* obj);
extern bool ent_Unit_needsMoveToTurn(ent_Unit* obj);
extern double ent_Unit_getSpeed(ent_Unit* obj, void* arg1);
extern double ent_Unit_getSpeedFactor(ent_Unit* obj);
extern bool ent_Unit_isSlowed(ent_Unit* obj);
extern bool ent_Unit_isAtGroundLevel(ent_Unit* obj);
extern double ent_Unit_getRotationSpeed(ent_Unit* obj);
extern double ent_Unit_getRotationTilt(ent_Unit* obj);
extern double ent_Unit_getAccelerationSpeed(ent_Unit* obj);
extern bool ent_Unit_hasFlag(ent_Unit* obj, int arg1);
extern bool ent_Unit_hasFlag2(ent_Unit* obj, int arg1);
extern void ent_Unit_moveTo(ent_Unit* obj, h2d_col_PointImpl* arg1, void* arg2);
extern bool ent_Unit_isMoving(ent_Unit* obj);
extern void ent_Unit_doRemove(ent_Unit* obj);
extern void ent_Unit_doRemoveVisual(ent_Unit* obj);
extern bool ent_Unit_isIdle(ent_Unit* obj);
extern bool ent_Unit_hasCloakedAttribute(ent_Unit* obj);
extern double ent_Unit_getUpkeepFlatModif(ent_Unit* obj, int arg1);
extern double ent_Unit_getAdditiveUpkeepFactor(ent_Unit* obj, int arg1);
extern double ent_Unit_getMultiplicativeUpkeepFactor(ent_Unit* obj, int arg1);
extern double ent_Unit_doGetUpkeepDetail(ent_Unit* obj, int arg1, void* arg2);
extern bool ent_Unit_isNearOwnedVillage(ent_Unit* obj, void* arg1);
extern bool ent_Unit_isNearAllyVillage(ent_Unit* obj, void* arg1);
extern bool ent_Unit_isNearAllyBuilding(ent_Unit* obj, void* arg1);
extern bool ent_Unit_isNearAllySietch(ent_Unit* obj, void* arg1);
extern bool ent_Unit_isNearAllyHeadquarter(ent_Unit* obj, void* arg1);
extern bool ent_Unit_hasControl(ent_Unit* obj);
extern bool ent_Unit_isTaunted(ent_Unit* obj);
extern bool ent_Unit_isNoControl(ent_Unit* obj);
extern bool ent_Unit_canShowQueuedActions(ent_Unit* obj);
extern bool ent_Unit_canRecon(ent_Unit* obj);
extern bool ent_Unit_hasActionQuotes(ent_Unit* obj);
extern bool ent_Unit_hasQuoteForAction(ent_Unit* obj, int arg1);
extern void ent_Unit_playActionQuote(ent_Unit* obj, int arg1);
extern void ent_Unit_playRecruitFeedback__impl(ent_Unit* obj);
extern hl_types_ArrayObj* ent_Unit_getAvailableActions(ent_Unit* obj);
extern void ent_Unit_randomMoveHarvester(ent_Unit* obj);
extern void ent_Unit_chooseJob(ent_Unit* obj);
extern void* ent_Unit_rightClickForAction(ent_Unit* obj, void* arg1, hl_types_ArrayObj* arg2, void* arg3, void* arg4);
extern EReason* ent_Unit_getNoActionReason(ent_Unit* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Unit_onMoveEnd(ent_Unit* obj);
extern void ent_Unit_updateCurrentAction(ent_Unit* obj, double arg1);
extern void ent_Unit_onReconEnd(ent_Unit* obj, ent_Structure* arg1);
extern void ent_Unit_doActionInternal(ent_Unit* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Unit_doEndCurrentAction(ent_Unit* obj, ent_ActionEndReason* arg1);
extern void ent_Unit_returnAction(ent_Unit* obj, ent_ActionEndReason* arg1);
extern void ent_Unit_refreshState(ent_Unit* obj);
extern void ent_Unit_updateState(ent_Unit* obj, double arg1);
extern ent_State* ent_Unit_set_state(ent_Unit* obj, ent_State* arg1);
extern hl_types_ArrayObj* ent_Unit_getRegenCostToHeal(ent_Unit* obj, double arg1);
extern double ent_Unit_getRegenCost(ent_Unit* obj, int arg1);
extern double ent_Unit_getRegenUpkeep(ent_Unit* obj, int arg1);
extern String* ent_Unit_getRegenUpkeepRes(ent_Unit* obj);
extern double ent_Unit_getDailyLifeRegen(ent_Unit* obj);
extern double ent_Unit_getDailyLifeDecay(ent_Unit* obj);
extern bool ent_Unit_isSafe(ent_Unit* obj);
extern bool ent_Unit_canSafeRegen(ent_Unit* obj);
extern bool ent_Unit_shouldSafeRegen(ent_Unit* obj);
extern bool ent_Unit_hasSafeRegen(ent_Unit* obj);
extern double ent_Unit_getSafeLifeRegen(ent_Unit* obj);
extern double ent_Unit_getBaseSafeRegenLifeRatio(ent_Unit* obj);
extern double ent_Unit_getSafeRegenLifeRatioModifier(ent_Unit* obj);
extern double ent_Unit_getModifiedSafeRegenLifeRatio(ent_Unit* obj);
extern double ent_Unit_getLifeRegenModifier(ent_Unit* obj);
extern void ent_Unit_updateSounds(ent_Unit* obj, double arg1);
extern bool ent_Unit_isFlying(ent_Unit* obj);
extern bool ent_Unit_hasLevels(ent_Unit* obj);
extern bool ent_Unit_isEscortedByOrni(ent_Unit* obj);
extern bool ent_Unit_isWormTarget(ent_Unit* obj);
extern bool ent_Unit_canDieFromWorm(ent_Unit* obj);
extern bool ent_Unit_get_neverWormTarget(ent_Unit* obj);
extern bool ent_Unit_canBeWormTarget(ent_Unit* obj, void* arg1);
extern bool ent_Unit_canBeAttacked(ent_Unit* obj, ent_Faction* arg1);
extern void ent_Unit_update(ent_Unit* obj, double arg1);
extern bool ent_Unit_canFightWith(ent_Unit* obj, ent_Entity* arg1, void* arg2);
extern bool ent_Unit_isDamageableEntity(ent_Unit* obj);
extern bool ent_Unit_canCauseFightImplications(ent_Unit* obj);
extern void ent_Unit_updateFighting(ent_Unit* obj, double arg1);
extern void ent_Unit_updateLife(ent_Unit* obj, double arg1);
extern void ent_Unit_onLifeUpdated(ent_Unit* obj, double arg1);
extern void ent_Unit_onReceiveDamage(ent_Unit* obj, ent_Entity* arg1, double arg2, ent_AttackKind* arg3, ent_AttackType* arg4);
extern void ent_Unit_updateVibrationsFX(ent_Unit* obj);
extern void ent_Unit_frameRegularUpdate(ent_Unit* obj, double arg1);
extern bool ent_Unit_hasSpottedWorm(ent_Unit* obj);
extern void ent_Unit_updateAbilityAutoTrigger(ent_Unit* obj);
extern void ent_Unit_updateDeathBlockers(ent_Unit* obj);
extern bool ent_Unit_canDie(ent_Unit* obj);
extern void ent_Unit_preDie(ent_Unit* obj);
extern void ent_Unit_die(ent_Unit* obj, void* arg1);
extern void ent_Unit_playDeath__impl(ent_Unit* obj);
extern bool ent_Unit_canAutoRemoveVisual(ent_Unit* obj);
extern String* ent_Unit_getIdStr(ent_Unit* obj);
extern EReason* ent_Unit_disband(ent_Unit* obj, void* arg1);
extern bool ent_Unit_rpcDisband__impl(ent_Unit* obj);
extern EReason* ent_Unit_checkDisband(ent_Unit* obj);
extern bool ent_Unit_canDisband(ent_Unit* obj);
extern String* ent_Unit___net_mark_kind(ent_Unit* obj, String* arg1);
extern int ent_Unit_get_networkPropKind(ent_Unit* obj);
extern bool ent_Unit___net_mark_repairing(ent_Unit* obj, bool arg1);
extern int ent_Unit_get_networkPropRepairing(ent_Unit* obj);
extern ent_Sandworm* ent_Unit___net_mark_targettedByWorm(ent_Unit* obj, ent_Sandworm* arg1);
extern ent_Sandworm* ent_Unit_set_targettedByWorm(ent_Unit* obj, ent_Sandworm* arg1);
extern int ent_Unit_get_networkPropTargettedByWorm(ent_Unit* obj);
extern double ent_Unit___net_mark_speedFactor(ent_Unit* obj, double arg1);
extern double ent_Unit_set_speedFactor(ent_Unit* obj, double arg1);
extern int ent_Unit_get_networkPropSpeedFactor(ent_Unit* obj);
extern double ent_Unit___net_mark_deployLockEnd(ent_Unit* obj, double arg1);
extern double ent_Unit_set_deployLockEnd(ent_Unit* obj, double arg1);
extern int ent_Unit_get_networkPropDeployLockEnd(ent_Unit* obj);
extern hxbit_ArrayProxyData* ent_Unit___net_mark_deathBlockers(ent_Unit* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Unit_set_deathBlockers(ent_Unit* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Unit_get_networkPropDeathBlockers(ent_Unit* obj);
extern bool ent_Unit___net_mark_awaitingDeath(ent_Unit* obj, bool arg1);
extern bool ent_Unit_set_awaitingDeath(ent_Unit* obj, bool arg1);
extern int ent_Unit_get_networkPropAwaitingDeath(ent_Unit* obj);
extern void ent_Unit_rpcConvertToUnitKind(ent_Unit* obj, String* arg1, String* arg2);
extern void ent_Unit_rpcPlayDeployFeedback(ent_Unit* obj);
extern void ent_Unit_fireUnitEventRpc(ent_Unit* obj, int arg1, ent_Entity* arg2);
extern void ent_Unit_killUnitEventRpc(ent_Unit* obj, int arg1);
extern void ent_Unit_playRecruitFeedback(ent_Unit* obj);
extern void ent_Unit_playDeath(ent_Unit* obj);
extern void ent_Unit_rpcDisband(ent_Unit* obj, void* arg1);
extern void ent_Unit_networkFlush(ent_Unit* obj, hxbit_Serializer* arg1);
extern void ent_Unit_networkSync(ent_Unit* obj, hxbit_Serializer* arg1);
extern void ent_Unit_networkInitProxys(ent_Unit* obj);
extern bool ent_Unit_networkRPC(ent_Unit* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Unit_networkGetName(ent_Unit* obj, int arg1, void* arg2);
extern int ent_Unit_getCLID(ent_Unit* obj);
extern void ent_Unit_serialize(ent_Unit* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Unit_getSerializeSchema(ent_Unit* obj);
extern void ent_Unit_unserializeInit(ent_Unit* obj);
extern void ent_Unit_unserialize(ent_Unit* obj, hxbit_Serializer* arg1);


#endif // __gen_t_ent_Unit_h__
