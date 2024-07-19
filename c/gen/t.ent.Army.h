// gen time: 2024-07-14 04:39:24 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_Army_h__
#define __gen_t_ent_Army_h__

#include <common.h>
#include <gen/t.ent.Unit.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_ActionEndReason ent_ActionEndReason;
typedef struct ent_Army ent_Army;
typedef struct ent_ArmyModel ent_ArmyModel;
typedef struct ent_ArmyStance ent_ArmyStance;
typedef struct ent_AttackKind ent_AttackKind;
typedef struct ent_AttackTargetKind ent_AttackTargetKind;
typedef struct ent_AttackType ent_AttackType;
typedef struct ent_DamageSource ent_DamageSource;
typedef struct ent_DeathReason ent_DeathReason;
typedef struct ent_DeployStatus ent_DeployStatus;
typedef struct ent_EActionState ent_EActionState;
typedef struct ent_Entity ent_Entity;
typedef struct ent_Faction ent_Faction;
typedef struct ent_GamePlane ent_GamePlane;
typedef struct ent_MovementMode ent_MovementMode;
typedef struct ent_Sandworm ent_Sandworm;
typedef struct ent_State ent_State;
typedef struct ent_Structure ent_Structure;
typedef struct ent_comp_OccupierKind ent_comp_OccupierKind;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct h3d_VectorImpl h3d_VectorImpl;
typedef struct h3d_col_Collider h3d_col_Collider;
typedef struct h3d_col_Sphere h3d_col_Sphere;
typedef struct h3d_scene_Object h3d_scene_Object;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_RangeFX lib_RangeFX;
typedef struct lib_SceneObject lib_SceneObject;
typedef struct lib_SelectionFX lib_SelectionFX;
typedef struct logic_Application logic_Application;
typedef struct logic_state_Raid logic_state_Raid;
typedef struct prefab_Curve prefab_Curve;
typedef struct prefab_FXAnimation prefab_FXAnimation;
typedef struct shaders_Dithering shaders_Dithering;


// type: ent.Army, kind: HOBJ, pType: 0x02748E3E6078
struct ent_Army {
  // super: ent.Unit
  ent_Unit                  super;

  // cls: ent.Army, begin_offset: 0x04D1
  String*                   customName;         // +04D8: HOBJ String
  int                       bannerIndex;        // +04E0
  double                    overloadedXp;       // +04E8
  double                    supplyDiff;         // +04F0
  double                    afkSupplyTime;      // +04F8
  hl_types_ArrayObj*        models;             // +0500: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        formationPoints;    // +0508: HOBJ hl.types.ArrayObj
  logic_state_Raid*         raid;               // +0510: HOBJ logic.state.Raid
  int                       combatAttackCount;  // +0518
  bool                      isMilitia;          // +051C
  bool                      engagedMilitia;     // +051D
  ent_Structure*            occupiedStructure;  // +0520: HOBJ ent.Structure
  ent_Structure*            contestingStructure; // +0528: HOBJ ent.Structure
  String*                   copiedTrait;        // +0530: HOBJ String
  hxbit_ArrayProxyData*     equipment;          // +0538: HOBJ hxbit.ArrayProxyData
  ent_ArmyStance*           stance;             // +0540: HENUM ent.ArmyStance
  double                    calculatedRadius;   // +0548
  lib_SelectionFX*          selectionFX;        // +0550: HOBJ lib.SelectionFX
  lib_RangeFX*              rangeFX;            // +0558: HOBJ lib.RangeFX
  lib_RangeFX*              minRangeFX;         // +0560: HOBJ lib.RangeFX
  lib_SelectionFX*          aoeFX;              // +0568: HOBJ lib.SelectionFX
  h3d_col_Sphere*           sphereCollider;     // +0570: HOBJ h3d.col.Sphere
  prefab_FXAnimation*       directionFx;        // +0578: HOBJ prefab.FXAnimation
  prefab_Curve*             dropCurve;          // +0580: HOBJ prefab.Curve
  prefab_Curve*             pickupCurve;        // +0588: HOBJ prefab.Curve
  double                    currentZOffset;     // +0590
  double                    stateTime;          // +0598
  ent_DeployStatus*         deployStatus;       // +05A0: HENUM ent.DeployStatus
  bool                      isBeingExecuted;    // +05A8
  hl_types_ArrayObj*        prevEquipment;      // +05B0: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        unitEventsOverride; // +05B8: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        hostileEntities;    // +05C0: HOBJ hl.types.ArrayObj
  // total_size: 0x05C8
}; // ent_Army (ent.Army)

_Static_assert(sizeof(ent_Army) == 0x05C8, "cls ent.Army has wrong size");


extern logic_state_Raid* ent_Army_set_raid(ent_Army* obj, logic_state_Raid* arg1);
extern String* ent_Army_getRaidKind(ent_Army* obj);
extern bool ent_Army_isRaider(ent_Army* obj);
extern double ent_Army_get_radius(ent_Army* obj);
extern bool ent_Army_set_lockSyncVisibility(ent_Army* obj, bool arg1);
extern ent_Faction* ent_Army_get_diplomaticOwner(ent_Army* obj);
extern double ent_Army_get_avoidanceRadius(ent_Army* obj);
extern bool ent_Army_isCloaked(ent_Army* obj);
extern void ent_Army_finalize(ent_Army* obj);
extern void ent_Army_init(ent_Army* obj);
extern void ent_Army_postInit(ent_Army* obj);
extern void ent_Army_initCurrentAction(ent_Army* obj);
extern void ent_Army_setVisible(ent_Army* obj, bool arg1);
extern void ent_Army_onReady(ent_Army* obj);
extern void ent_Army_reload(ent_Army* obj);
extern double ent_Army_getFlagOffset(ent_Army* obj);
extern double ent_Army_getZOffset(ent_Army* obj);
extern double ent_Army_getWormDetectionDelay(ent_Army* obj);
extern bool ent_Army_isNoControl(ent_Army* obj);
extern bool ent_Army_hasSupply(ent_Army* obj);
extern double ent_Army_get_supply(ent_Army* obj);
extern double ent_Army_get_maxSupply(ent_Army* obj);
extern double ent_Army_addSupply(ent_Army* obj, double arg1, void* arg2);
extern double ent_Army_stealSupply(ent_Army* obj, ent_Army* arg1, double arg2);
extern void* ent_Army_getBaseMaxResStock(ent_Army* obj, String* arg1);
extern void* ent_Army_getMaxResStock(ent_Army* obj, String* arg1);
extern String* ent_Army_getExposedName(ent_Army* obj);
extern double ent_Army_getMaxLifeAdditiveModifier(ent_Army* obj);
extern double ent_Army_getBaseMaxLife(ent_Army* obj);
extern double ent_Army_getBasePower(ent_Army* obj);
extern double ent_Army_get_power(ent_Army* obj);
extern double ent_Army_getPowerModifier(ent_Army* obj, void* arg1);
extern double ent_Army_getPowerModifierAgainst(ent_Army* obj, ent_Entity* arg1, ent_AttackKind* arg2);
extern double ent_Army_getDefenseFactor(ent_Army* obj, ent_Entity* arg1, ent_DamageSource* arg2, void* arg3, ent_AttackKind* arg4);
extern bool ent_Army_isVillageDefender(ent_Army* obj);
extern ent_Structure* ent_Army_getDefendedStructure(ent_Army* obj);
extern hl_types_ArrayObj* ent_Army_getAffectingAtbApps(ent_Army* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern void ent_Army_engage(ent_Army* obj, ent_Entity* arg1);
extern void ent_Army_engageMilitia(ent_Army* obj, ent_Structure* arg1);
extern double ent_Army_getEngageSpeed(ent_Army* obj);
extern double ent_Army_getSpeedFactor(ent_Army* obj);
extern bool ent_Army_isReturningToVillage(ent_Army* obj);
extern int ent_Army_getSquadSize(ent_Army* obj);
extern void* ent_Army_resolveModel(ent_Army* obj);
extern void ent_Army_initVisual(ent_Army* obj);
extern void ent_Army_initModels(ent_Army* obj);
extern bool ent_Army_isCulled(ent_Army* obj);
extern void ent_Army_fireUnitEvent(ent_Army* obj, int arg1, ent_Entity* arg2);
extern void ent_Army_spawnModels(ent_Army* obj, int arg1);
extern ent_ArmyModel* ent_Army_spawnModel(ent_Army* obj, double arg1, int arg2, void* arg3, void* arg4);
extern h3d_col_Collider* ent_Army_makeInteractiveCollider(ent_Army* obj);
extern void ent_Army_selectFeedback(ent_Army* obj, void* arg1);
extern void ent_Army_onUnselect(ent_Army* obj);
extern void ent_Army_setTutoHighlight(ent_Army* obj, bool arg1);
extern void ent_Army_setOutline(ent_Army* obj, bool arg1);
extern void ent_Army_onOver(ent_Army* obj);
extern void ent_Army_onOut(ent_Army* obj);
extern bool ent_Army_isInLeashRange(ent_Army* obj, ent_Entity* arg1);
extern bool ent_Army_canMove(ent_Army* obj);
extern bool ent_Army_isMoveLockedBySkill(ent_Army* obj);
extern bool ent_Army_hasSmoothRotation(ent_Army* obj);
extern double ent_Army_getFollowingDistance(ent_Army* obj, ent_Entity* arg1);
extern bool ent_Army_isInAttackRange(ent_Army* obj, ent_Entity* arg1, void* arg2);
extern double ent_Army_getAttackRangeFactor(ent_Army* obj);
extern h2d_col_PointImpl* ent_Army_getMovementModeTarget(ent_Army* obj, ent_MovementMode* arg1);
extern bool ent_Army_canPatrol(ent_Army* obj);
extern bool ent_Army_showRange(ent_Army* obj);
extern bool ent_Army_shouldShowRange(ent_Army* obj);
extern bool ent_Army_requiresDeployToAttack(ent_Army* obj);
extern String* ent_Army_deployedCombo(ent_Army* obj);
extern void ent_Army_onTransitPickup(ent_Army* obj);
extern shaders_Dithering* ent_Army_fadeIn(ent_Army* obj, void* arg1, void* arg2);
extern shaders_Dithering* ent_Army_fadeOut(ent_Army* obj, void* arg1, void* arg2);
extern h2d_col_PointImpl* ent_Army_nearestOpenPosFromTarget(ent_Army* obj, ent_Entity* arg1, double arg2);
extern bool ent_Army_hasArmyInTargetRadius(ent_Army* obj, double arg1, double arg2, double arg3, hl_types_ArrayObj* arg4);
extern hl_types_ArrayObj* ent_Army_findAvoidanceTargets(ent_Army* obj, double arg1, double arg2, double arg3);
extern bool ent_Army_canCollide(ent_Army* obj, ent_Entity* arg1);
extern double ent_Army_getOverlap(ent_Army* obj, ent_Entity* arg1, h2d_col_PointImpl* arg2);
extern ent_State* ent_Army_set_state(ent_Army* obj, ent_State* arg1);
extern void ent_Army_updateState(ent_Army* obj, double arg1);
extern void ent_Army_regularUpdateState(ent_Army* obj, double arg1);
extern bool ent_Army_isForceAlly(ent_Army* obj, ent_Entity* arg1);
extern void ent_Army_hurtBy(ent_Army* obj, ent_Entity* arg1, double arg2, ent_DamageSource* arg3, ent_AttackKind* arg4, ent_AttackType* arg5, void* arg6, void* arg7);
extern void ent_Army_onLifeUpdated(ent_Army* obj, double arg1);
extern void ent_Army_playSplitFeedback__impl(ent_Army* obj, hl_types_ArrayObj* arg1);
extern void ent_Army_executedBy(ent_Army* obj, ent_Entity* arg1, void* arg2);
extern void ent_Army_playExecuteFeedback__impl(ent_Army* obj, ent_Entity* arg1);
extern ent_AttackTargetKind* ent_Army_getAssociatedTargetType(ent_Army* obj);
extern bool ent_Army_canCauseFightImplications(ent_Army* obj);
extern bool ent_Army_isAttackerPriorityTarget(ent_Army* obj, ent_Entity* arg1);
extern bool ent_Army_isAlly(ent_Army* obj, ent_Entity* arg1);
extern bool ent_Army_isHostileWith(ent_Army* obj, ent_Entity* arg1);
extern void ent_Army_refreshCombatWith(ent_Army* obj, ent_Entity* arg1, void* arg2, void* arg3);
extern void ent_Army_startFight(ent_Army* obj, ent_Entity* arg1);
extern void ent_Army_playAttack__impl(ent_Army* obj, String* arg1, int arg2, ent_Entity* arg3, void* arg4);
extern void ent_Army_playSkill__impl(ent_Army* obj, String* arg1);
extern void ent_Army_playSkillStart__impl(ent_Army* obj, String* arg1);
extern void ent_Army_playSkillStop__impl(ent_Army* obj, String* arg1);
extern void ent_Army_endFight(ent_Army* obj);
extern void ent_Army_endCombat(ent_Army* obj);
extern int ent_Army_getHitType(ent_Army* obj);
extern void ent_Army_preDie(ent_Army* obj);
extern prefab_FXAnimation* ent_Army_playTraitsFx(ent_Army* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4, void* arg5, int arg6, hl_types_ArrayObj* arg7);
extern void ent_Army_onDeath(ent_Army* obj, ent_DeathReason* arg1);
extern void ent_Army_gainEliminationExperience(ent_Army* obj, ent_Entity* arg1);
extern void ent_Army_onEliminate(ent_Army* obj, ent_Entity* arg1, ent_Entity* arg2);
extern void ent_Army_swapModels(ent_Army* obj, void* arg1, void* arg2);
extern void ent_Army_zOffsetChangesOnDeploy(ent_Army* obj, ent_DeployStatus* arg1, String* arg2, String* arg3);
extern void ent_Army_onConvertKind(ent_Army* obj, String* arg1, String* arg2);
extern void* ent_Army_getStateDuration(ent_Army* obj);
extern double ent_Army_getStateProgress(ent_Army* obj);
extern void ent_Army_playAnim(ent_Army* obj, String* arg1, void* arg2, void* arg3);
extern double ent_Army_getBaseArmor(ent_Army* obj);
extern double ent_Army_getTargetArmorFactor(ent_Army* obj, ent_Entity* arg1);
extern double ent_Army_getAttackSpeedAdditiveModifiers(ent_Army* obj, ent_AttackType* arg1);
extern double ent_Army_getAttackSpeedMultiplicativeModifiers(ent_Army* obj, ent_AttackType* arg1);
extern double ent_Army_getAttackStat(ent_Army* obj);
extern double ent_Army_getImpactsRadiusOffset(ent_Army* obj);
extern h3d_scene_Object* ent_Army_getAttackMuzzle(ent_Army* obj, String* arg1);
extern double ent_Army_getNextAttackDamage(ent_Army* obj);
extern void ent_Army_doAttackEffects(ent_Army* obj, String* arg1, int arg2, double arg3, ent_Entity* arg4, h3d_VectorImpl* arg5, ent_GamePlane* arg6);
extern void ent_Army_playAttackEffects__impl(ent_Army* obj, String* arg1, int arg2, ent_Entity* arg3, void* arg4);
extern void ent_Army_onTraitStart(ent_Army* obj, logic_Application* arg1);
extern void ent_Army_onTraitEnd(ent_Army* obj, logic_Application* arg1, bool arg2);
extern void ent_Army_routeArmy(ent_Army* obj, ent_Army* arg1);
extern void ent_Army_defeatArmy(ent_Army* obj, ent_Army* arg1);
extern void ent_Army_battleVictory(ent_Army* obj, ent_Army* arg1);
extern void ent_Army_conquerStructure(ent_Army* obj, ent_Structure* arg1);
extern ent_comp_OccupierKind* ent_Army_getOccupierKind(ent_Army* obj);
extern hl_types_ArrayObj* ent_Army_getAvailableActions(ent_Army* obj);
extern hl_types_ArrayObj* ent_Army_getActionSustainCost(ent_Army* obj, void* arg1, void* arg2, ent_Faction* arg3, ent_EActionState* arg4);
extern void ent_Army_doActionInternal(ent_Army* obj, void* arg1, void* arg2, ent_Faction* arg3);
extern void ent_Army_stopMove(ent_Army* obj);
extern EReason* ent_Army_implSetStance(ent_Army* obj, ent_ArmyStance* arg1);
extern bool ent_Army_isDefensive(ent_Army* obj);
extern bool ent_Army_isAggressive(ent_Army* obj);
extern void ent_Army_updateCurrentAction(ent_Army* obj, double arg1);
extern void ent_Army_doEndCurrentAction(ent_Army* obj, ent_ActionEndReason* arg1);
extern double ent_Army_set_headingDirection(ent_Army* obj, double arg1);
extern void ent_Army_moveTo(ent_Army* obj, h2d_col_PointImpl* arg1, void* arg2);
extern void ent_Army_teleport__impl(ent_Army* obj, void* arg1);
extern double ent_Army_getInterpSpeed(ent_Army* obj);
extern void ent_Army_makeFormations(ent_Army* obj);
extern hl_types_ArrayObj* ent_Army_resetMovingFormation(ent_Army* obj, void* arg1);
extern bool ent_Army_get_refundable(ent_Army* obj);
extern String* ent_Army_getRefundTitle(ent_Army* obj, void* arg1);
extern String* ent_Army_getRefundDesc(ent_Army* obj);
extern void ent_Army_doMilitiaDisband(ent_Army* obj);
extern bool ent_Army_tryMilitiaRemove(ent_Army* obj);
extern void ent_Army_doDisband(ent_Army* obj);
extern void ent_Army_addDither(ent_Army* obj);
extern void ent_Army_clearDither(ent_Army* obj);
extern lib_SceneObject* ent_Army_removeWaitUntil(ent_Army* obj, void* arg1);
extern void ent_Army_playDeathWorm__impl(ent_Army* obj, ent_Sandworm* arg1);
extern void ent_Army_update(ent_Army* obj, double arg1);
extern void ent_Army_frameUpdate(ent_Army* obj, double arg1);
extern bool ent_Army_ignoresTerrain(ent_Army* obj);
extern void ent_Army_updateTerrain(ent_Army* obj, double arg1);
extern double ent_Army_getCurrentVibrations(ent_Army* obj);
extern double ent_Army_getDailyLifeRegen(ent_Army* obj);
extern double ent_Army_getDailyLifeDecay(ent_Army* obj);
extern double ent_Army_getLifeRegenModifier(ent_Army* obj);
extern void ent_Army_die(ent_Army* obj, void* arg1);
extern bool ent_Army_isInHostileZone(ent_Army* obj);
extern void ent_Army_updateSupply(ent_Army* obj, double arg1);
extern void ent_Army_breakFightWith(ent_Army* obj, ent_Faction* arg1, ent_Entity* arg2);
extern bool ent_Army_isLosingSupply(ent_Army* obj);
extern bool ent_Army_isGainingSupply(ent_Army* obj);
extern double ent_Army_getSupplyChanges(ent_Army* obj, ent_Structure* arg1, void* arg2);
extern bool ent_Army_isDirectionVisible(ent_Army* obj);
extern bool ent_Army_isGameplayVisibleForFaction(ent_Army* obj, ent_Faction* arg1);
extern bool ent_Army_isFlagVisible(ent_Army* obj);
extern void ent_Army_onTransitStart(ent_Army* obj);
extern void ent_Army_onTransitDrop(ent_Army* obj, h2d_col_PointImpl* arg1);
extern void ent_Army_regUpdateMovement(ent_Army* obj, double arg1);
extern bool ent_Army_canHaveIndividualEquipment(ent_Army* obj);
extern EReason* ent_Army_getAnyIndividualEquipmentReason(ent_Army* obj);
extern EReason* ent_Army_implAddEquipment(ent_Army* obj, String* arg1, int arg2);
extern EReason* ent_Army_implRemoveEquipment(ent_Army* obj, String* arg1);
extern void ent_Army_updateEquipment(ent_Army* obj);
extern void ent_Army_syncEquipment(ent_Army* obj, hl_types_ArrayObj* arg1);
extern void ent_Army_syncEquipmentVisuals(ent_Army* obj);
extern hl_types_ArrayObj* ent_Army_getUnitEventsOverride(ent_Army* obj);
extern void ent_Army_onAddEquipment(ent_Army* obj, String* arg1);
extern void ent_Army_onRemoveEquipment(ent_Army* obj, String* arg1);
extern void ent_Army_regularUpdate(ent_Army* obj, double arg1);
extern void ent_Army_updateBackSupply(ent_Army* obj, double arg1);
extern ent_Structure* ent_Army_getNeareastOwnedVillage(ent_Army* obj);
extern void ent_Army_clientRegularUpdate(ent_Army* obj, double arg1);
extern void ent_Army_frameRegularUpdate(ent_Army* obj, double arg1);
extern void ent_Army_dailyUpdate(ent_Army* obj);
extern int ent_Army_getBonusTraitsGivenByAllyArmiesCount(ent_Army* obj);
extern void ent_Army_updateAttributes(ent_Army* obj, double arg1);
extern String* ent_Army_getNightTrait(ent_Army* obj);
extern double ent_Army_comparePowers(ent_Army* obj, ent_Army* arg1);
extern bool ent_Army_canBesiege(ent_Army* obj, ent_Structure* arg1);
extern bool ent_Army_canOccupy(ent_Army* obj, ent_Structure* arg1);
extern bool ent_Army_canContestOccupation(ent_Army* obj, ent_Structure* arg1);
extern bool ent_Army_canAutoEngage(ent_Army* obj, ent_Entity* arg1);
extern bool ent_Army_canAutoFightWith(ent_Army* obj, ent_Entity* arg1);
extern bool ent_Army_canFightWith(ent_Army* obj, ent_Entity* arg1, void* arg2);
extern bool ent_Army_isFightingFaction(ent_Army* obj, ent_Faction* arg1);
extern double ent_Army_getAutoFightDistance(ent_Army* obj);
extern void ent_Army_updateAutoEngages(ent_Army* obj, double arg1);
extern void ent_Army_tryAutoEngage(ent_Army* obj);
extern void ent_Army_updateAlerts(ent_Army* obj);
extern bool ent_Army_isOccupying(ent_Army* obj, ent_Structure* arg1);
extern bool ent_Army_isOccupyingSelf(ent_Army* obj, ent_Structure* arg1);
extern int ent_Army_getMaxExperienceLevel(ent_Army* obj);
extern void ent_Army_gainExperience(ent_Army* obj, double arg1);
extern void ent_Army_upToXpLevel(ent_Army* obj, int arg1);
extern void ent_Army_setXpLevel(ent_Army* obj, int arg1);
extern void ent_Army_setToXpLevel(ent_Army* obj, int arg1);
extern double ent_Army_getLevelTotalXp(ent_Army* obj, int arg1);
extern int ent_Army_getCurrentXpLevel(ent_Army* obj);
extern double ent_Army_getCurrentLevelNeed(ent_Army* obj);
extern double ent_Army_getNextLevelNeed(ent_Army* obj);
extern double ent_Army_getNextLevelProgressNeed(ent_Army* obj);
extern double ent_Army_getCurrentLevelProgress(ent_Army* obj);
extern double ent_Army_getCurrentLevelRatio(ent_Army* obj);
extern void ent_Army_updateExperience(ent_Army* obj);
extern void ent_Army_updateMovement(ent_Army* obj, double arg1);
extern double ent_Army_getAirfieldRange(ent_Army* obj);
extern void ent_Army_doRemove(ent_Army* obj);
extern bool ent_Army_enableApiLog(ent_Army* obj);
extern int ent_Army_getCLID(ent_Army* obj);
extern void ent_Army_serialize(ent_Army* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Army_getSerializeSchema(ent_Army* obj);
extern void ent_Army_unserializeInit(ent_Army* obj);
extern void ent_Army_unserialize(ent_Army* obj, hxbit_Serializer* arg1);
extern EReason* ent_Army_setStance(ent_Army* obj, ent_ArmyStance* arg1, void* arg2);
extern bool ent_Army_rpcSetStance__impl(ent_Army* obj, ent_ArmyStance* arg1);
extern EReason* ent_Army_checkSetStance(ent_Army* obj, ent_ArmyStance* arg1);
extern bool ent_Army_canSetStance(ent_Army* obj, ent_ArmyStance* arg1);
extern EReason* ent_Army_addEquipment(ent_Army* obj, String* arg1, int arg2, void* arg3);
extern bool ent_Army_rpcAddEquipment__impl(ent_Army* obj, String* arg1, int arg2);
extern EReason* ent_Army_checkAddEquipment(ent_Army* obj, String* arg1, int arg2);
extern bool ent_Army_canAddEquipment(ent_Army* obj, String* arg1, int arg2);
extern EReason* ent_Army_removeEquipment(ent_Army* obj, String* arg1, void* arg2);
extern bool ent_Army_rpcRemoveEquipment__impl(ent_Army* obj, String* arg1);
extern EReason* ent_Army_checkRemoveEquipment(ent_Army* obj, String* arg1);
extern bool ent_Army_canRemoveEquipment(ent_Army* obj, String* arg1);
extern String* ent_Army___net_mark_customName(ent_Army* obj, String* arg1);
extern String* ent_Army_set_customName(ent_Army* obj, String* arg1);
extern int ent_Army_get_networkPropCustomName(ent_Army* obj);
extern int ent_Army___net_mark_bannerIndex(ent_Army* obj, int arg1);
extern int ent_Army_set_bannerIndex(ent_Army* obj, int arg1);
extern int ent_Army_get_networkPropBannerIndex(ent_Army* obj);
extern double ent_Army___net_mark_overloadedXp(ent_Army* obj, double arg1);
extern double ent_Army_set_overloadedXp(ent_Army* obj, double arg1);
extern int ent_Army_get_networkPropOverloadedXp(ent_Army* obj);
extern logic_state_Raid* ent_Army___net_mark_raid(ent_Army* obj, logic_state_Raid* arg1);
extern int ent_Army_get_networkPropRaid(ent_Army* obj);
extern int ent_Army___net_mark_combatAttackCount(ent_Army* obj, int arg1);
extern int ent_Army_set_combatAttackCount(ent_Army* obj, int arg1);
extern int ent_Army_get_networkPropCombatAttackCount(ent_Army* obj);
extern bool ent_Army___net_mark_isMilitia(ent_Army* obj, bool arg1);
extern bool ent_Army_set_isMilitia(ent_Army* obj, bool arg1);
extern int ent_Army_get_networkPropIsMilitia(ent_Army* obj);
extern bool ent_Army___net_mark_engagedMilitia(ent_Army* obj, bool arg1);
extern bool ent_Army_set_engagedMilitia(ent_Army* obj, bool arg1);
extern int ent_Army_get_networkPropEngagedMilitia(ent_Army* obj);
extern String* ent_Army___net_mark_copiedTrait(ent_Army* obj, String* arg1);
extern String* ent_Army_set_copiedTrait(ent_Army* obj, String* arg1);
extern int ent_Army_get_networkPropCopiedTrait(ent_Army* obj);
extern hxbit_ArrayProxyData* ent_Army___net_mark_equipment(ent_Army* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Army_set_equipment(ent_Army* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Army_get_networkPropEquipment(ent_Army* obj);
extern ent_ArmyStance* ent_Army___net_mark_stance(ent_Army* obj, ent_ArmyStance* arg1);
extern ent_ArmyStance* ent_Army_set_stance(ent_Army* obj, ent_ArmyStance* arg1);
extern int ent_Army_get_networkPropStance(ent_Army* obj);
extern void ent_Army_playSplitFeedback(ent_Army* obj, hl_types_ArrayObj* arg1);
extern void ent_Army_playExecuteFeedback(ent_Army* obj, ent_Entity* arg1);
extern void ent_Army_playDeathWorm(ent_Army* obj, ent_Sandworm* arg1);
extern void ent_Army_rpcSetStance(ent_Army* obj, ent_ArmyStance* arg1, void* arg2);
extern void ent_Army_rpcAddEquipment(ent_Army* obj, String* arg1, int arg2, void* arg3);
extern void ent_Army_rpcRemoveEquipment(ent_Army* obj, String* arg1, void* arg2);
extern void ent_Army_networkFlush(ent_Army* obj, hxbit_Serializer* arg1);
extern void ent_Army_networkSync(ent_Army* obj, hxbit_Serializer* arg1);
extern void ent_Army_networkInitProxys(ent_Army* obj);
extern bool ent_Army_networkRPC(ent_Army* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Army_networkGetName(ent_Army* obj, int arg1, void* arg2);


#endif // __gen_t_ent_Army_h__
