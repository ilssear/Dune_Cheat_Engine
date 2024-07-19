// gen time: 2024-07-14 16:16:27 UTC, pid: 0x000035FC (13820)

#ifndef __gen_t_ent_Structure_h__
#define __gen_t_ent_Structure_h__

#include <common.h>
#include <gen/t.ent.Entity.h>

typedef struct DisplayTarget DisplayTarget;
typedef struct EReason EReason;
typedef struct EScope EScope;
typedef struct ProductionBonusFilter ProductionBonusFilter;
typedef struct ProductionKind ProductionKind;
typedef struct String String;
typedef struct ent_Army ent_Army;
typedef struct ent_AttackKind ent_AttackKind;
typedef struct ent_AttackTargetKind ent_AttackTargetKind;
typedef struct ent_AttackType ent_AttackType;
typedef struct ent_BaseBuilding ent_BaseBuilding;
typedef struct ent_DeathReason ent_DeathReason;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Headquarter ent_Headquarter;
typedef struct ent_LocalSietch ent_LocalSietch;
typedef struct ent_MainBaseHeadquarter ent_MainBaseHeadquarter;
typedef struct ent_Object ent_Object;
typedef struct ent_RecruitType ent_RecruitType;
typedef struct ent_Refinery ent_Refinery;
typedef struct ent_ResourcesGenerator ent_ResourcesGenerator;
typedef struct ent_SpawnMode ent_SpawnMode;
typedef struct ent_StabilityStatus ent_StabilityStatus;
typedef struct ent_Structure ent_Structure;
typedef struct ent_StructureModel ent_StructureModel;
typedef struct ent_Unit ent_Unit;
typedef struct ent_comp_CaptureComponent ent_comp_CaptureComponent;
typedef struct ent_comp_OccupierKind ent_comp_OccupierKind;
typedef struct ent_comp_SiegeComponent ent_comp_SiegeComponent;
typedef struct ent_comp_SietchComponent ent_comp_SietchComponent;
typedef struct ent_comp_WorldEventComponent ent_comp_WorldEventComponent;
typedef struct h2d_Object h2d_Object;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct h3d_VectorImpl h3d_VectorImpl;
typedef struct h3d_col_Collider h3d_col_Collider;
typedef struct h3d_scene_Object h3d_scene_Object;
typedef struct hl_Class hl_Class;
typedef struct hl_types_ArrayBytes_Float hl_types_ArrayBytes_Float;
typedef struct hl_types_ArrayBytes_Int hl_types_ArrayBytes_Int;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hrt_prefab_Resource hrt_prefab_Resource;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_Event lib_Event;
typedef struct logic_Application logic_Application;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct logic_EFlowSource logic_EFlowSource;
typedef struct logic_state_Raid logic_state_Raid;
typedef struct prefab_FXAnimation prefab_FXAnimation;


// type: ent.Structure, kind: HOBJ, pType: 0x01EC714D0DF8
struct ent_Structure {
  // super: ent.Entity
  ent_Entity                super;

  // cls: ent.Structure, begin_offset: 0x0358
  hxbit_ArrayProxyData*     recruitments;       // +0358: HOBJ hxbit.ArrayProxyData
  String*                   kind;               // +0360: HOBJ String
  ent_ResourcesGenerator*   resourcesGen;       // +0368: HOBJ ent.ResourcesGenerator
  hxbit_MapData*            factionData;        // +0370: HOBJ hxbit.MapData
  String*                   placeName;          // +0378: HOBJ String
  ent_StabilityStatus*      stabilityStatus;    // +0380: HENUM ent.StabilityStatus
  double                    positiveWaterStart; // +0388
  double                    unrestStart;        // +0390
  double                    captureTime;        // +0398
  hxbit_ArrayProxyData*     villageTraits;      // +03A0: HOBJ hxbit.ArrayProxyData
  double                    originalRecruitPointX; // +03A8
  double                    originalRecruitPointY; // +03B0
  void*                     inf;                // +03B8: HVIRTUAL
  ent_StructureModel*       structureModel;     // +03C0: HOBJ ent.StructureModel
  double                    criticalStabilityRebelSpawnTimer; // +03C8
  double                    fremenArmySpawn;    // +03D0
  logic_state_Raid*         rebellingRaid;      // +03D8: HOBJ logic.state.Raid
  ent_Headquarter*          headquarter;        // +03E0: HOBJ ent.Headquarter
  ent_MainBaseHeadquarter*  mainBaseHeadquarter; // +03E8: HOBJ ent.MainBaseHeadquarter
  ent_LocalSietch*          localSietch;        // +03F0: HOBJ ent.LocalSietch
  bool                      initialMB;          // +03F8
  hxbit_ArrayProxyData*     buildings;          // +0400: HOBJ hxbit.ArrayProxyData
  bool                      localHQView;        // +0408
  bool                      localMBHQView;      // +0409
  bool                      localSietchView;    // +040A
  hl_types_ArrayBytes_Int*  districtSlotsTypes; // +0410: HOBJ hl.types.ArrayBytes_Int
  hl_types_ArrayBytes_Float* cachedResNetProd;  // +0418: HOBJ hl.types.ArrayBytes_Float
  hl_types_ArrayObj*        structureComponents; // +0420: HOBJ hl.types.ArrayObj
  ent_comp_WorldEventComponent* worldEvent;     // +0428: HOBJ ent.comp.WorldEventComponent
  ent_comp_SietchComponent* sietch;             // +0430: HOBJ ent.comp.SietchComponent
  ent_comp_CaptureComponent* capture;           // +0438: HOBJ ent.comp.CaptureComponent
  ent_comp_SiegeComponent*  siege;              // +0440: HOBJ ent.comp.SiegeComponent
  void*                     infCache;           // +0448: HVIRTUAL
  DisplayTarget*            abilityDisplayTgt;  // +0450: HENUM DisplayTarget
  bool                      isProdCacheValid;   // +0458
  ent_StabilityStatus*      prevStatus;         // +0460: HENUM ent.StabilityStatus
  prefab_FXAnimation*       stabFx;             // +0468: HOBJ prefab.FXAnimation
  hl_types_ArrayObj*        neuralNodeFxs;      // +0470: HOBJ hl.types.ArrayObj
  h3d_scene_Object*         pivotVerniusBase;   // +0478: HOBJ h3d.scene.Object
  int                       cachedWorkingBuildings; // +0480
  // total_size: 0x0484
}; // ent_Structure (ent.Structure)

_Static_assert(sizeof(ent_Structure) == 0x0488, "cls ent.Structure has wrong size");


extern bool ent_Structure_set_initialMB(ent_Structure* obj, bool arg1);
extern ent_Refinery* ent_Structure_get_refinery(ent_Structure* obj);
extern ent_BaseBuilding* ent_Structure_getBuilding(ent_Structure* obj, hl_Class* arg1);
extern ent_BaseBuilding* ent_Structure_getBuildingByUid(ent_Structure* obj, int arg1);
extern hl_types_ArrayObj* ent_Structure_getConstructingBuildings(ent_Structure* obj);
extern hl_types_ArrayBytes_Int* ent_Structure_get_districtSlotsTypes(ent_Structure* obj);
extern ent_comp_OccupierKind* ent_Structure_get_occupier(ent_Structure* obj);
extern bool ent_Structure_isOccupied(ent_Structure* obj);
extern bool ent_Structure_isActivelyOccupied(ent_Structure* obj);
extern ent_Faction* ent_Structure_getOccupierFaction(ent_Structure* obj);
extern hl_types_ArrayObj* ent_Structure_getAvailableOccupationActions(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isUnderRenegadeControl(ent_Structure* obj);
extern void* ent_Structure_get_stats(ent_Structure* obj);
extern void ent_Structure_init(ent_Structure* obj);
extern void ent_Structure_setupComponents(ent_Structure* obj);
extern void ent_Structure_patchEntity(ent_Structure* obj, int arg1);
extern void ent_Structure_applySpecificVisibility(ent_Structure* obj);
extern void ent_Structure_finalize(ent_Structure* obj);
extern void ent_Structure_applyCustomCollision(ent_Structure* obj);
extern bool ent_Structure_hasAttacks(ent_Structure* obj);
extern void ent_Structure_makeAttackComponents(ent_Structure* obj);
extern hl_types_ArrayObj* ent_Structure_getAttackCombos(ent_Structure* obj, hl_types_ArrayObj* arg1);
extern h3d_VectorImpl* ent_Structure_getAttackProjectileDirection(ent_Structure* obj, h3d_scene_Object* arg1, h2d_col_PointImpl* arg2);
extern double ent_Structure_getMaxLifeAdditiveModifier(ent_Structure* obj);
extern double ent_Structure_getMaxLifeMultModifier(ent_Structure* obj);
extern double ent_Structure_getExpectedMissileRange(ent_Structure* obj, double arg1);
extern ent_Faction* ent_Structure_set_owner(ent_Structure* obj, ent_Faction* arg1);
extern String* ent_Structure_set_kind(ent_Structure* obj, String* arg1);
extern String* ent_Structure_get_name(ent_Structure* obj);
extern bool ent_Structure_isCulled(ent_Structure* obj);
extern bool ent_Structure_isControllable(ent_Structure* obj);
extern bool ent_Structure_isSiegeable(ent_Structure* obj);
extern bool ent_Structure_isWorldEvent(ent_Structure* obj);
extern bool ent_Structure_isRegularWorldEvent(ent_Structure* obj);
extern void* ent_Structure_getWorldEventGroup(ent_Structure* obj);
extern bool ent_Structure_isNaturalResource(ent_Structure* obj);
extern bool ent_Structure_isPoI(ent_Structure* obj);
extern void ent_Structure_initStartProperties(ent_Structure* obj);
extern hl_types_ArrayObj* ent_Structure_forceSpawnUnits(ent_Structure* obj, hl_types_ArrayObj* arg1, ent_Faction* arg2);
extern hl_types_ArrayObj* ent_Structure_spawnUnits(ent_Structure* obj, hl_types_ArrayObj* arg1);
extern double ent_Structure_getAdditivePowerModifier(ent_Structure* obj);
extern double ent_Structure_getMultiplicativePowerModifier(ent_Structure* obj);
extern void ent_Structure_addVillageTrait(ent_Structure* obj, hl_types_ArrayObj* arg1);
extern void ent_Structure_initTraits(ent_Structure* obj, int arg1);
extern String* ent_Structure_getExposedName(ent_Structure* obj);
extern String* ent_Structure_getBannerName(ent_Structure* obj);
extern String* ent_Structure_getPlaceName(ent_Structure* obj);
extern String* ent_Structure_getUIClassName(ent_Structure* obj);
extern int ent_Structure_get_size(ent_Structure* obj);
extern int ent_Structure_getCompletedDistrictCount(ent_Structure* obj);
extern void* ent_Structure_getMaxResStock(ent_Structure* obj, String* arg1);
extern bool ent_Structure_get_refundable(ent_Structure* obj);
extern hl_types_ArrayObj* ent_Structure_getRefund(ent_Structure* obj);
extern hl_types_ArrayObj* ent_Structure_getNoRefund(ent_Structure* obj);
extern String* ent_Structure_getRefundTitle(ent_Structure* obj, void* arg1);
extern String* ent_Structure_getRefundDesc(ent_Structure* obj);
extern EReason* ent_Structure_getNoRefundReason(ent_Structure* obj);
extern void ent_Structure_doRequestRefund(ent_Structure* obj);
extern double ent_Structure_getBaseRefundRate(ent_Structure* obj);
extern logic_AttributeApplication* ent_Structure_addAttributeRaw(ent_Structure* obj, int arg1, void* arg2);
extern void ent_Structure_propagateClearAtbCache(ent_Structure* obj, int arg1, EScope* arg2, void* arg3, logic_AttributeApplication* arg4);
extern bool ent_Structure_removeAttribute(ent_Structure* obj, int arg1);
extern double ent_Structure_getSietchProduction(ent_Structure* obj, int arg1, ent_Faction* arg2);
extern double ent_Structure_getTotalResourceProduction(ent_Structure* obj);
extern bool ent_Structure_additionalProductionIsVisible(ent_Structure* obj, ent_Faction* arg1);
extern ent_Object* ent_Structure_getTransactionReceiver(ent_Structure* obj);
extern double ent_Structure_getBaseResourceProduction(ent_Structure* obj, String* arg1);
extern double ent_Structure_getResourceProduction(ent_Structure* obj, int arg1, void* arg2, ProductionKind* arg3, void* arg4, void* arg5);
extern double ent_Structure_getTransactionableResourceProduction(ent_Structure* obj, String* arg1, ProductionKind* arg2, void* arg3, void* arg4);
extern double ent_Structure_getLocalProd(ent_Structure* obj, int arg1, ProductionBonusFilter* arg2, void* arg3, void* arg4);
extern hl_types_ArrayObj* ent_Structure_getLocalProdTotal(ent_Structure* obj, void* arg1, ProductionBonusFilter* arg2, void* arg3, void* arg4);
extern double ent_Structure_getResourceRemainingStorage(ent_Structure* obj, String* arg1);
extern int ent_Structure_getUpgradeCount(ent_Structure* obj);
extern int ent_Structure_getOccupiedOutpostSlots(ent_Structure* obj, void* arg1);
extern int ent_Structure_getEmptyOutpostSlots(ent_Structure* obj);
extern int ent_Structure_getMaxOutpostSlots(ent_Structure* obj, void* arg1);
extern int ent_Structure_getTotalOutpostSlots(ent_Structure* obj);
extern bool ent_Structure_isMainBaseFull(ent_Structure* obj, void* arg1);
extern bool ent_Structure_canProgressUpgrades(ent_Structure* obj);
extern EReason* ent_Structure_getProgressReason(ent_Structure* obj);
extern bool ent_Structure_isSietch(ent_Structure* obj);
extern bool ent_Structure_isRenegadeBase(ent_Structure* obj);
extern bool ent_Structure_isVillage(ent_Structure* obj);
extern bool ent_Structure_isGenericUWHeadquarters(ent_Structure* obj);
extern bool ent_Structure_isUWHeadquarters(ent_Structure* obj);
extern bool ent_Structure_isMBUWHeadquarters(ent_Structure* obj);
extern bool ent_Structure_isLocalSietch(ent_Structure* obj);
extern bool ent_Structure_isHostileSietch(ent_Structure* obj);
extern bool ent_Structure_get_isMainBase(ent_Structure* obj);
extern bool ent_Structure_get_isActiveMainBase(ent_Structure* obj);
extern bool ent_Structure_get_isDeadMainBase(ent_Structure* obj);
extern bool ent_Structure_get_selected(ent_Structure* obj);
extern void ent_Structure_onSelect(ent_Structure* obj, void* arg1);
extern void ent_Structure_onRightSelect(ent_Structure* obj);
extern void ent_Structure_onOver(ent_Structure* obj);
extern void ent_Structure_onOut(ent_Structure* obj);
extern void* ent_Structure_getOverInfo(ent_Structure* obj);
extern h2d_Object* ent_Structure_getTipContent(ent_Structure* obj);
extern void ent_Structure_selectFeedback(ent_Structure* obj, void* arg1);
extern void ent_Structure_onUnselect(ent_Structure* obj);
extern void ent_Structure_doRemove(ent_Structure* obj);
extern void ent_Structure_onUpgrade(ent_Structure* obj, void* arg1);
extern void ent_Structure_onCancelUpgrade(ent_Structure* obj, void* arg1);
extern void ent_Structure_onRemoveUpgrade(ent_Structure* obj, void* arg1);
extern void ent_Structure_onTraitStart(ent_Structure* obj, logic_Application* arg1);
extern void ent_Structure_onTraitEnd(ent_Structure* obj, logic_Application* arg1, bool arg2);
extern void ent_Structure_onEvent(ent_Structure* obj, lib_Event* arg1);
extern void ent_Structure_onReceiveDamage(ent_Structure* obj, ent_Entity* arg1, double arg2, ent_AttackKind* arg3, ent_AttackType* arg4);
extern bool ent_Structure_hasUWHeadquarters(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_hasMBUWHeadquarters(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_hasLocalSietch(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_hasOutpost(ent_Structure* obj);
extern bool ent_Structure_hasEcazPride(ent_Structure* obj);
extern bool ent_Structure_isSanctuary(ent_Structure* obj);
extern bool ent_Structure_isOnNeuralGrid(ent_Structure* obj);
extern bool ent_Structure_canTakeCommands(ent_Structure* obj);
extern void ent_Structure_removeOutpost(ent_Structure* obj);
extern void ent_Structure_removeOutpostSpecificTraits(ent_Structure* obj);
extern EReason* ent_Structure_implAbandon(ent_Structure* obj);
extern void ent_Structure_changeToNeutral(ent_Structure* obj, void* arg1);
extern void ent_Structure_rpcChangeOwner__impl(ent_Structure* obj, ent_Faction* arg1, void* arg2, void* arg3);
extern void ent_Structure_changeOwner(ent_Structure* obj, ent_Faction* arg1, void* arg2, void* arg3);
extern void ent_Structure_rpcSetModelFaction__impl(ent_Structure* obj, String* arg1);
extern bool ent_Structure_hasAirfield(ent_Structure* obj);
extern double ent_Structure_getAirfieldRangeFactor(ent_Structure* obj);
extern double ent_Structure_getAirfieldRange(ent_Structure* obj);
extern bool ent_Structure_canSupply(ent_Structure* obj, ent_Unit* arg1);
extern bool ent_Structure_canSupplyFaction(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isStandardSupplyZoneForFaction(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isDefaultSupplyZone(ent_Structure* obj);
extern bool ent_Structure_isInSupplyRange(ent_Structure* obj, ent_Entity* arg1);
extern bool ent_Structure_isPointInSupplyRange(ent_Structure* obj, h2d_col_PointImpl* arg1);
extern hl_types_ArrayObj* ent_Structure_getAirfieldRangePolys(ent_Structure* obj, void* arg1);
extern hl_types_ArrayObj* ent_Structure_getMissileBatteriesRangePolys(ent_Structure* obj, void* arg1);
extern hl_types_ArrayObj* ent_Structure_getResupplyRangePolys(ent_Structure* obj, void* arg1);
extern bool ent_Structure_hasWorkingHarvester(ent_Structure* obj);
extern double ent_Structure_getFlagOffset(ent_Structure* obj);
extern bool ent_Structure_isReconned(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isReconnable(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_setReconned(ent_Structure* obj, ent_Faction* arg1, void* arg2);
extern void ent_Structure_setFactionReconned(ent_Structure* obj, ent_Faction* arg1, void* arg2);
extern void ent_Structure_updateAttributes(ent_Structure* obj, double arg1);
extern bool ent_Structure_isUnlocked(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isSpecialPoI(ent_Structure* obj);
extern void ent_Structure_setUnlocked(ent_Structure* obj, ent_Faction* arg1, void* arg2);
extern void ent_Structure_addReveal(ent_Structure* obj, ent_Faction* arg1, double arg2);
extern double ent_Structure_getRevealThreshold(ent_Structure* obj);
extern ent_Army* ent_Structure_getDefendingArmy(ent_Structure* obj);
extern bool ent_Structure_canDetectEntity(ent_Structure* obj, ent_Entity* arg1);
extern bool ent_Structure_isGameplayVisibleForFaction(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isModelVisibleForFaction(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isFlagVisible(ent_Structure* obj);
extern bool ent_Structure_useStaticFlag(ent_Structure* obj);
extern void ent_Structure_syncVisibility(ent_Structure* obj);
extern void ent_Structure_onReady(ent_Structure* obj);
extern void ent_Structure_initVisual(ent_Structure* obj);
extern h3d_col_Collider* ent_Structure_makeInteractiveCollider(ent_Structure* obj);
extern void ent_Structure_initInteractive(ent_Structure* obj);
extern bool ent_Structure_canShowAlignment(ent_Structure* obj);
extern h3d_VectorImpl* ent_Structure_getTilePos(ent_Structure* obj, String* arg1);
extern void ent_Structure_die(ent_Structure* obj, void* arg1);
extern void ent_Structure_onDeath(ent_Structure* obj, ent_DeathReason* arg1);
extern bool ent_Structure_isDead(ent_Structure* obj);
extern bool ent_Structure_isNeutralised(ent_Structure* obj);
extern bool ent_Structure_canBeAutoAttacked(ent_Structure* obj);
extern bool ent_Structure_isDamageableEntity(ent_Structure* obj);
extern bool ent_Structure_canDieFromDamage(ent_Structure* obj);
extern ent_AttackTargetKind* ent_Structure_getAssociatedTargetType(ent_Structure* obj);
extern bool ent_Structure_isActivelyFighting(ent_Structure* obj);
extern bool ent_Structure_isFighting(ent_Structure* obj);
extern bool ent_Structure_hasCombatEnded(ent_Structure* obj, void* arg1);
extern double ent_Structure_getBasePower(ent_Structure* obj);
extern double ent_Structure_getBaseMaxLife(ent_Structure* obj);
extern double ent_Structure_getBaseArmor(ent_Structure* obj);
extern double ent_Structure_getBaseAttackRange(ent_Structure* obj);
extern double ent_Structure_getAttackRangeFactor(ent_Structure* obj);
extern double ent_Structure_getDailyLifeRegen(ent_Structure* obj);
extern void ent_Structure_doDevastation(ent_Structure* obj);
extern hl_types_ArrayObj* ent_Structure_concatAnnexationCostDetails(ent_Structure* obj, hl_types_ArrayObj* arg1, ent_Faction* arg2);
extern void ent_Structure_regularUpdate(ent_Structure* obj, double arg1);
extern double ent_Structure_getMultiplicativeUpkeepFactor(ent_Structure* obj, int arg1);
extern hl_types_ArrayObj* ent_Structure_concatAnnexationUpkeepDetails(ent_Structure* obj, hl_types_ArrayObj* arg1, ent_Faction* arg2);
extern logic_EFlowSource* ent_Structure_getBuildingUpkeepSource(ent_Structure* obj, int arg1, void* arg2);
extern double ent_Structure_doGetUpkeepDetail(ent_Structure* obj, int arg1, void* arg2);
extern EReason* ent_Structure_implStartRebellion(ent_Structure* obj, String* arg1);
extern void ent_Structure_endRebellion(ent_Structure* obj);
extern bool ent_Structure_isRebelling(ent_Structure* obj);
extern bool ent_Structure_isImpairedByStability(ent_Structure* obj);
extern void ent_Structure_reduceStability(ent_Structure* obj);
extern void ent_Structure_updateFx(ent_Structure* obj);
extern void ent_Structure_updateNeuralNodeFxs(ent_Structure* obj);
extern prefab_FXAnimation* ent_Structure_playTraitsFx(ent_Structure* obj, hrt_prefab_Resource* arg1, String* arg2, void* arg3, void* arg4, void* arg5, int arg6, hl_types_ArrayObj* arg7);
extern void ent_Structure_updateStability(ent_Structure* obj, double arg1);
extern hl_types_ArrayObj* ent_Structure_getNearbyArmies(ent_Structure* obj);
extern bool ent_Structure_addReconProgress(ent_Structure* obj, ent_Faction* arg1, double arg2);
extern void ent_Structure_updateProgresses(ent_Structure* obj);
extern bool ent_Structure_surveyedBy(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_investigatedBy(ent_Structure* obj, ent_Faction* arg1);
extern ent_Faction* ent_Structure_visibleInvestigatingFaction(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_annexedBy(ent_Structure* obj, ent_Faction* arg1);
extern double ent_Structure_getReconToReach(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_canFactionSeeInfiltrationCell(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_canFactionInvestigateInfiltrationCell(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_isMineInfiltrationCell(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_startInvestigation(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_stopInvestigation(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_completeInvestigation(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_detectHeadquarter(ent_Structure* obj, ent_Faction* arg1);
extern bool ent_Structure_canAssignUnitKind(ent_Structure* obj, String* arg1);
extern void ent_Structure_tryDeliverAgentsToFaction(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_constructHeadquarter(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_constructMainBaseHeadquarter(ent_Structure* obj, ent_Faction* arg1);
extern void ent_Structure_constructLocalSietch(ent_Structure* obj, ent_Faction* arg1);
extern hl_types_ArrayObj* ent_Structure_getRecruiting(ent_Structure* obj, String* arg1);
extern double ent_Structure_getUnitRecruitmentTimeModifier(ent_Structure* obj, void* arg1, void* arg2, void* arg3);
extern double ent_Structure_getRecruitingSpeedFactor(ent_Structure* obj, void* arg1);
extern void* ent_Structure_getPerfectedRecruitDetails(ent_Structure* obj);
extern bool ent_Structure_isPerfectedRecruitAllowed(ent_Structure* obj, String* arg1);
extern EReason* ent_Structure_checkPerfectedRecruit(ent_Structure* obj, String* arg1, void* arg2);
extern bool ent_Structure_canPerfectedRecruit(ent_Structure* obj, String* arg1, void* arg2);
extern void ent_Structure_perfectedRecruit(ent_Structure* obj, String* arg1, void* arg2);
extern EReason* ent_Structure_implRecruit(ent_Structure* obj, String* arg1, void* arg2, ent_RecruitType* arg3, ent_Faction* arg4, void* arg5, void* arg6, void* arg7, hl_types_ArrayObj* arg8, void* arg9, void* arg10);
extern EReason* ent_Structure_implCancelRecruitmentAt(ent_Structure* obj, int arg1);
extern EReason* ent_Structure_implCancelRecruitment(ent_Structure* obj, void* arg1);
extern hl_types_ArrayObj* ent_Structure_getRecruitmentRefundAt(ent_Structure* obj, int arg1);
extern hl_types_ArrayObj* ent_Structure_getRecruitmentRefund(ent_Structure* obj, void* arg1);
extern void ent_Structure_updateRecruitment(ent_Structure* obj, double arg1);
extern h2d_col_PointImpl* ent_Structure_findSpawnPoint(ent_Structure* obj, double arg1);
extern h2d_col_PointImpl* ent_Structure_findBottomSpawnPoint(ent_Structure* obj);
extern ent_Unit* ent_Structure_recruitUnit(ent_Structure* obj, String* arg1, ent_Faction* arg2, void* arg3, ent_SpawnMode* arg4, void* arg5, void* arg6);
extern void ent_Structure_requestRecruitShuttle(ent_Structure* obj, ent_Unit* arg1, h2d_col_PointImpl* arg2);
extern void ent_Structure_playFremenUnitSpawn__impl(ent_Structure* obj, ent_Entity* arg1);
extern void ent_Structure_embarkArmyOnShuttle(ent_Structure* obj, ent_Army* arg1, h2d_col_PointImpl* arg2);
extern void ent_Structure_updateJob(ent_Structure* obj, double arg1);
extern void ent_Structure_update(ent_Structure* obj, double arg1);
extern void ent_Structure_frameUpdate(ent_Structure* obj, double arg1);
extern void ent_Structure_frameRegularUpdate(ent_Structure* obj, double arg1);
extern void ent_Structure_dailyUpdate(ent_Structure* obj);
extern bool ent_Structure_canBeRaidedBy(ent_Structure* obj, String* arg1);
extern void ent_Structure_setRelation(ent_Structure* obj, ent_Faction* arg1, double arg2);
extern void ent_Structure_addRelation(ent_Structure* obj, ent_Faction* arg1, double arg2, void* arg3);
extern void ent_Structure_checkForPossibleAllianceChange(ent_Structure* obj, ent_Faction* arg1);
extern double ent_Structure_getRelation(ent_Structure* obj, ent_Faction* arg1);
extern double ent_Structure_get_gridSnapScale(ent_Structure* obj);
extern h2d_col_PointImpl* ent_Structure_snapToGrid(ent_Structure* obj, double arg1, double arg2);
extern hl_types_ArrayObj* ent_Structure_getGridPtsFromRange(ent_Structure* obj, double arg1, double arg2, int arg3);
extern h2d_col_PointImpl* ent_Structure_getValidPosPoint(ent_Structure* obj, double arg1, double arg2, int arg3);
extern h3d_VectorImpl* ent_Structure_getBuildingPos(ent_Structure* obj, String* arg1);
extern bool ent_Structure_checkPlacement(ent_Structure* obj, String* arg1, int arg2, double arg3, double arg4);
extern bool ent_Structure_isBonusPlacement(ent_Structure* obj, String* arg1, double arg2, double arg3);
extern EReason* ent_Structure_checkCanPlace(ent_Structure* obj, String* arg1, double arg2, double arg3, void* arg4);
extern EReason* ent_Structure_implAddBuilding(ent_Structure* obj, String* arg1, double arg2, double arg3, void* arg4, void* arg5, void* arg6);
extern EReason* ent_Structure_checkCells(ent_Structure* obj, h2d_col_PointImpl* arg1, void* arg2);
extern EReason* ent_Structure_checkCanPlaceMainBase(ent_Structure* obj, String* arg1, double arg2, double arg3);
extern void ent_Structure_createBuilding(ent_Structure* obj, void* arg1);
extern void ent_Structure_removeBuilding(ent_Structure* obj, void* arg1);
extern int ent_Structure_workingBuildingsCount(ent_Structure* obj);
extern void ent_Structure_debugFullBuild(ent_Structure* obj, void* arg1);
extern String* ent_Structure_getIdStr(ent_Structure* obj);
extern int ent_Structure_getCLID(ent_Structure* obj);
extern void ent_Structure_serialize(ent_Structure* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Structure_getSerializeSchema(ent_Structure* obj);
extern void ent_Structure_unserializeInit(ent_Structure* obj);
extern void ent_Structure_unserialize(ent_Structure* obj, hxbit_Serializer* arg1);
extern EReason* ent_Structure_abandon(ent_Structure* obj, void* arg1);
extern bool ent_Structure_rpcAbandon__impl(ent_Structure* obj);
extern EReason* ent_Structure_checkAbandon(ent_Structure* obj);
extern bool ent_Structure_canAbandon(ent_Structure* obj);
extern EReason* ent_Structure_startRebellion(ent_Structure* obj, String* arg1, void* arg2);
extern bool ent_Structure_rpcStartRebellion__impl(ent_Structure* obj, String* arg1);
extern EReason* ent_Structure_checkStartRebellion(ent_Structure* obj, String* arg1);
extern bool ent_Structure_canStartRebellion(ent_Structure* obj, String* arg1);
extern EReason* ent_Structure_recruit(ent_Structure* obj, String* arg1, void* arg2, ent_RecruitType* arg3, ent_Faction* arg4, void* arg5, void* arg6, void* arg7, hl_types_ArrayObj* arg8, void* arg9, void* arg10, void* arg11);
extern bool ent_Structure_rpcRecruit__impl(ent_Structure* obj, String* arg1, void* arg2, ent_RecruitType* arg3, ent_Faction* arg4, void* arg5, void* arg6, void* arg7, hl_types_ArrayObj* arg8, void* arg9, void* arg10);
extern EReason* ent_Structure_checkRecruit(ent_Structure* obj, String* arg1, void* arg2, ent_RecruitType* arg3, ent_Faction* arg4, void* arg5, void* arg6, void* arg7, hl_types_ArrayObj* arg8, void* arg9, void* arg10);
extern bool ent_Structure_canRecruit(ent_Structure* obj, String* arg1, void* arg2, ent_RecruitType* arg3, ent_Faction* arg4, void* arg5, void* arg6, void* arg7, hl_types_ArrayObj* arg8, void* arg9, void* arg10);
extern EReason* ent_Structure_cancelRecruitmentAt(ent_Structure* obj, int arg1, void* arg2);
extern bool ent_Structure_rpcCancelRecruitmentAt__impl(ent_Structure* obj, int arg1);
extern EReason* ent_Structure_checkCancelRecruitmentAt(ent_Structure* obj, int arg1);
extern bool ent_Structure_canCancelRecruitmentAt(ent_Structure* obj, int arg1);
extern EReason* ent_Structure_cancelRecruitment(ent_Structure* obj, void* arg1, void* arg2);
extern bool ent_Structure_rpcCancelRecruitment__impl(ent_Structure* obj, void* arg1);
extern EReason* ent_Structure_checkCancelRecruitment(ent_Structure* obj, void* arg1);
extern bool ent_Structure_canCancelRecruitment(ent_Structure* obj, void* arg1);
extern EReason* ent_Structure_addBuilding(ent_Structure* obj, String* arg1, double arg2, double arg3, void* arg4, void* arg5, void* arg6, void* arg7);
extern bool ent_Structure_rpcAddBuilding__impl(ent_Structure* obj, String* arg1, double arg2, double arg3, void* arg4, void* arg5, void* arg6);
extern EReason* ent_Structure_checkAddBuilding(ent_Structure* obj, String* arg1, double arg2, double arg3, void* arg4, void* arg5, void* arg6);
extern bool ent_Structure_canAddBuilding(ent_Structure* obj, String* arg1, double arg2, double arg3, void* arg4, void* arg5, void* arg6);
extern hxbit_ArrayProxyData* ent_Structure___net_mark_recruitments(ent_Structure* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Structure_set_recruitments(ent_Structure* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Structure_get_networkPropRecruitments(ent_Structure* obj);
extern String* ent_Structure___net_mark_kind(ent_Structure* obj, String* arg1);
extern int ent_Structure_get_networkPropKind(ent_Structure* obj);
extern ent_ResourcesGenerator* ent_Structure___net_mark_resourcesGen(ent_Structure* obj, ent_ResourcesGenerator* arg1);
extern ent_ResourcesGenerator* ent_Structure_set_resourcesGen(ent_Structure* obj, ent_ResourcesGenerator* arg1);
extern int ent_Structure_get_networkPropResourcesGen(ent_Structure* obj);
extern hxbit_MapData* ent_Structure___net_mark_factionData(ent_Structure* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_Structure_set_factionData(ent_Structure* obj, hxbit_MapData* arg1);
extern int ent_Structure_get_networkPropFactionData(ent_Structure* obj);
extern String* ent_Structure___net_mark_placeName(ent_Structure* obj, String* arg1);
extern String* ent_Structure_set_placeName(ent_Structure* obj, String* arg1);
extern int ent_Structure_get_networkPropPlaceName(ent_Structure* obj);
extern ent_StabilityStatus* ent_Structure___net_mark_stabilityStatus(ent_Structure* obj, ent_StabilityStatus* arg1);
extern ent_StabilityStatus* ent_Structure_set_stabilityStatus(ent_Structure* obj, ent_StabilityStatus* arg1);
extern int ent_Structure_get_networkPropStabilityStatus(ent_Structure* obj);
extern double ent_Structure___net_mark_positiveWaterStart(ent_Structure* obj, double arg1);
extern double ent_Structure_set_positiveWaterStart(ent_Structure* obj, double arg1);
extern int ent_Structure_get_networkPropPositiveWaterStart(ent_Structure* obj);
extern double ent_Structure___net_mark_unrestStart(ent_Structure* obj, double arg1);
extern double ent_Structure_set_unrestStart(ent_Structure* obj, double arg1);
extern int ent_Structure_get_networkPropUnrestStart(ent_Structure* obj);
extern double ent_Structure___net_mark_captureTime(ent_Structure* obj, double arg1);
extern double ent_Structure_set_captureTime(ent_Structure* obj, double arg1);
extern int ent_Structure_get_networkPropCaptureTime(ent_Structure* obj);
extern hxbit_ArrayProxyData* ent_Structure___net_mark_villageTraits(ent_Structure* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Structure_set_villageTraits(ent_Structure* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Structure_get_networkPropVillageTraits(ent_Structure* obj);
extern double ent_Structure___net_mark_originalRecruitPointX(ent_Structure* obj, double arg1);
extern double ent_Structure_set_originalRecruitPointX(ent_Structure* obj, double arg1);
extern int ent_Structure_get_networkPropOriginalRecruitPointX(ent_Structure* obj);
extern double ent_Structure___net_mark_originalRecruitPointY(ent_Structure* obj, double arg1);
extern double ent_Structure_set_originalRecruitPointY(ent_Structure* obj, double arg1);
extern int ent_Structure_get_networkPropOriginalRecruitPointY(ent_Structure* obj);
extern double ent_Structure___net_mark_criticalStabilityRebelSpawnTimer(ent_Structure* obj, double arg1);
extern double ent_Structure_set_criticalStabilityRebelSpawnTimer(ent_Structure* obj, double arg1);
extern int ent_Structure_get_networkPropCriticalStabilityRebelSpawnTimer(ent_Structure* obj);
extern double ent_Structure___net_mark_fremenArmySpawn(ent_Structure* obj, double arg1);
extern double ent_Structure_set_fremenArmySpawn(ent_Structure* obj, double arg1);
extern int ent_Structure_get_networkPropFremenArmySpawn(ent_Structure* obj);
extern logic_state_Raid* ent_Structure___net_mark_rebellingRaid(ent_Structure* obj, logic_state_Raid* arg1);
extern logic_state_Raid* ent_Structure_set_rebellingRaid(ent_Structure* obj, logic_state_Raid* arg1);
extern int ent_Structure_get_networkPropRebellingRaid(ent_Structure* obj);
extern ent_Headquarter* ent_Structure___net_mark_headquarter(ent_Structure* obj, ent_Headquarter* arg1);
extern ent_Headquarter* ent_Structure_set_headquarter(ent_Structure* obj, ent_Headquarter* arg1);
extern int ent_Structure_get_networkPropHeadquarter(ent_Structure* obj);
extern ent_MainBaseHeadquarter* ent_Structure___net_mark_mainBaseHeadquarter(ent_Structure* obj, ent_MainBaseHeadquarter* arg1);
extern ent_MainBaseHeadquarter* ent_Structure_set_mainBaseHeadquarter(ent_Structure* obj, ent_MainBaseHeadquarter* arg1);
extern int ent_Structure_get_networkPropMainBaseHeadquarter(ent_Structure* obj);
extern ent_LocalSietch* ent_Structure___net_mark_localSietch(ent_Structure* obj, ent_LocalSietch* arg1);
extern ent_LocalSietch* ent_Structure_set_localSietch(ent_Structure* obj, ent_LocalSietch* arg1);
extern int ent_Structure_get_networkPropLocalSietch(ent_Structure* obj);
extern bool ent_Structure___net_mark_initialMB(ent_Structure* obj, bool arg1);
extern int ent_Structure_get_networkPropInitialMB(ent_Structure* obj);
extern hxbit_ArrayProxyData* ent_Structure___net_mark_buildings(ent_Structure* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Structure_set_buildings(ent_Structure* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Structure_get_networkPropBuildings(ent_Structure* obj);
extern void ent_Structure_rpcChangeOwner(ent_Structure* obj, ent_Faction* arg1, void* arg2, void* arg3);
extern void ent_Structure_rpcSetModelFaction(ent_Structure* obj, String* arg1);
extern void ent_Structure_playFremenUnitSpawn(ent_Structure* obj, ent_Entity* arg1);
extern void ent_Structure_rpcAbandon(ent_Structure* obj, void* arg1);
extern void ent_Structure_rpcStartRebellion(ent_Structure* obj, String* arg1, void* arg2);
extern void ent_Structure_rpcRecruit(ent_Structure* obj, String* arg1, void* arg2, ent_RecruitType* arg3, ent_Faction* arg4, void* arg5, void* arg6, void* arg7, hl_types_ArrayObj* arg8, void* arg9, void* arg10, void* arg11);
extern void ent_Structure_rpcCancelRecruitmentAt(ent_Structure* obj, int arg1, void* arg2);
extern void ent_Structure_rpcCancelRecruitment(ent_Structure* obj, void* arg1, void* arg2);
extern void ent_Structure_rpcAddBuilding(ent_Structure* obj, String* arg1, double arg2, double arg3, void* arg4, void* arg5, void* arg6, void* arg7);
extern void ent_Structure_networkFlush(ent_Structure* obj, hxbit_Serializer* arg1);
extern void ent_Structure_networkSync(ent_Structure* obj, hxbit_Serializer* arg1);
extern void ent_Structure_networkInitProxys(ent_Structure* obj);
extern bool ent_Structure_networkRPC(ent_Structure* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Structure_networkGetName(ent_Structure* obj, int arg1, void* arg2);


#endif // __gen_t_ent_Structure_h__
