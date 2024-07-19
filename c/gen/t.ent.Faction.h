// gen time: 2024-07-14 04:39:45 UTC, pid: 0x000035C4 (13764)

#ifndef __gen_t_ent_Faction_h__
#define __gen_t_ent_Faction_h__

#include <common.h>
#include <gen/t.ent.Entity.h>

typedef struct DiplomacySource DiplomacySource;
typedef struct EReason EReason;
typedef struct EScope EScope;
typedef struct ProductionKind ProductionKind;
typedef struct String String;
typedef struct ent_EHostileActionType ent_EHostileActionType;
typedef struct ent_Faction ent_Faction;
typedef struct ent_HegemonyData ent_HegemonyData;
typedef struct ent_NuclearSilo ent_NuclearSilo;
typedef struct ent_RecyclingPlant ent_RecyclingPlant;
typedef struct ent_SpacingGuildBranch ent_SpacingGuildBranch;
typedef struct ent_Structure ent_Structure;
typedef struct ent_Unit ent_Unit;
typedef struct ent_Zone ent_Zone;
typedef struct ent_ZoneCell ent_ZoneCell;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct hl_Class hl_Class;
typedef struct hl_types_ArrayBytes_Float hl_types_ArrayBytes_Float;
typedef struct hl_types_ArrayBytes_Int hl_types_ArrayBytes_Int;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_ObjProxy_4a95719587202e1febd0b8ee4507b4f9 hxbit_ObjProxy_4a95719587202e1febd0b8ee4507b4f9;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_Event lib_Event;
typedef struct logic_Application logic_Application;
typedef struct logic_AttributeApplication logic_AttributeApplication;
typedef struct logic_FogOfWar logic_FogOfWar;
typedef struct logic_ai_AIController logic_ai_AIController;
typedef struct logic_ai_AIControllerData logic_ai_AIControllerData;
typedef struct logic_faction_AbilityManager logic_faction_AbilityManager;
typedef struct logic_faction_Airfield logic_faction_Airfield;
typedef struct logic_faction_AlertsManager logic_faction_AlertsManager;
typedef struct logic_faction_Contract logic_faction_Contract;
typedef struct logic_faction_Contracts logic_faction_Contracts;
typedef struct logic_faction_ControlGroups logic_faction_ControlGroups;
typedef struct logic_faction_Developments logic_faction_Developments;
typedef struct logic_faction_Equipments logic_faction_Equipments;
typedef struct logic_faction_Interactions logic_faction_Interactions;
typedef struct logic_faction_MissionManager logic_faction_MissionManager;
typedef struct logic_faction_NeuralGrid logic_faction_NeuralGrid;
typedef struct logic_faction_Objectives logic_faction_Objectives;
typedef struct logic_faction_Quests logic_faction_Quests;
typedef struct logic_faction_SpyManager logic_faction_SpyManager;
typedef struct logic_faction_SupplyLines logic_faction_SupplyLines;
typedef struct logic_faction_TutorialManager logic_faction_TutorialManager;
typedef struct logic_faction_WormRiding logic_faction_WormRiding;
typedef struct logic_state_CancelType logic_state_CancelType;
typedef struct logic_state_FactionStateData logic_state_FactionStateData;
typedef struct prefab_FXAnimation prefab_FXAnimation;
typedef struct world_PathGrid world_PathGrid;


// type: ent.Faction, kind: HOBJ, pType: 0x02748E3E48D8
struct ent_Faction {
  // super: ent.Entity
  ent_Entity                super;

  // cls: ent.Faction, begin_offset: 0x0358
  bool                      isAI;               // +0358
  hxbit_ArrayProxyData*     structures;         // +0360: HOBJ hxbit.ArrayProxyData
  String*                   kind;               // +0368: HOBJ String
  int64                     tfaction;           // +0370
  logic_FogOfWar*           fog;                // +0378: HOBJ logic.FogOfWar
  hxbit_ArrayProxyData*     zones;              // +0380: HOBJ hxbit.ArrayProxyData
  hl_types_ArrayObj*        captures;           // +0388: HOBJ hl.types.ArrayObj
  hxbit_ArrayProxyData*     occupations;        // +0390: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     armies;             // +0398: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     units;              // +03A0: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     lentUnits;          // +03A8: HOBJ hxbit.ArrayProxyData
  hl_types_ArrayObj*        probes;             // +03B0: HOBJ hl.types.ArrayObj
  hxbit_ArrayProxyData*     councilors;         // +03B8: HOBJ hxbit.ArrayProxyData
  logic_state_FactionStateData* stateData;      // +03C0: HOBJ logic.state.FactionStateData
  logic_ai_AIController*    aiController;       // +03C8: HOBJ logic.ai.AIController
  logic_ai_AIControllerData* aiControllerData;  // +03D0: HOBJ logic.ai.AIControllerData
  hxbit_ObjProxy_4a95719587202e1febd0b8ee4507b4f9* endGameData; // +03D8: HOBJ hxbit.ObjProxy_4a95719587202e1febd0b8ee4507b4f9
  hxbit_ArrayProxyData*     logics;             // +03E0: HOBJ hxbit.ArrayProxyData
  logic_faction_TutorialManager* tutorialManager; // +03E8: HOBJ logic.faction.TutorialManager
  void*                     cacheData;          // +03F0: HVIRTUAL
  hl_types_ArrayObj*        entities;           // +03F8: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        mainBases;          // +0400: HOBJ hl.types.ArrayObj
  void*                     recruitPointX;      // +0408: HNULL
  void*                     recruitPointY;      // +0410: HNULL
  bool                      rallyPointChanged;  // +0418
  h2d_col_PointImpl*        tempRallypoint;     // +0420: HOBJ h2d.col.PointImpl
  prefab_FXAnimation*       fxRallyPoint;       // +0428: HOBJ prefab.FXAnimation
  hxbit_ArrayProxyData*     tradingSietches;    // +0430: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     allySietches;       // +0438: HOBJ hxbit.ArrayProxyData
  ent_SpacingGuildBranch*   guildBranch;        // +0440: HOBJ ent.SpacingGuildBranch
  ent_RecyclingPlant*       recyclingPlant;     // +0448: HOBJ ent.RecyclingPlant
  ent_NuclearSilo*          nuclearSilo;        // +0450: HOBJ ent.NuclearSilo
  hl_types_ArrayBytes_Int*  discoveredCells;    // +0458: HOBJ hl.types.ArrayBytes_Int
  hl_types_ArrayBytes_Int*  fullyVisibleCells;  // +0460: HOBJ hl.types.ArrayBytes_Int
  hl_types_ArrayBytes_Int*  teamDiscoveredCells; // +0468: HOBJ hl.types.ArrayBytes_Int
  hl_types_ArrayBytes_Int*  teamVisibleCells;   // +0470: HOBJ hl.types.ArrayBytes_Int
  hxbit_MapData*            targetingScores;    // +0478: HOBJ hxbit.MapData
  world_PathGrid*           pathGrid;           // +0480: HOBJ world.PathGrid
  hl_types_ArrayObj*        treatyBreakAttempts; // +0488: HOBJ hl.types.ArrayObj
  void*                     config;             // +0490: HVIRTUAL
  bool                      initialSpiceReconned; // +0498
  hxbit_ArrayProxyData*     conquestBonuses;    // +04A0: HOBJ hxbit.ArrayProxyData
  hl_types_ArrayBytes_Float* lastResUpdate;     // +04A8: HOBJ hl.types.ArrayBytes_Float
  int                       lastResUpdateIdx;   // +04B0
  int                       currentHegemonyBonus; // +04B4
  hl_types_ArrayObj*        tmpEntities;        // +04B8: HOBJ hl.types.ArrayObj
  ent_Structure*            latestDestroyedBase; // +04C0: HOBJ ent.Structure
  hl_types_ArrayObj*        tmpRelationData;    // +04C8: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        tmpTradables;       // +04D0: HOBJ hl.types.ArrayObj
  hxbit_MapData*            nextDonationStamps; // +04D8: HOBJ hxbit.MapData
  hxbit_MapData*            nextRaidStamps;     // +04E0: HOBJ hxbit.MapData
  double                    time;               // +04E8
  bool                      inResourceUpdate;   // +04F0
  double                    lastPauseUpdate;    // +04F8
  hl_types_ArrayBytes_Int*  newVisibleCells;    // +0500: HOBJ hl.types.ArrayBytes_Int
  hl_types_ArrayBytes_Int*  keptVisibilityCells; // +0508: HOBJ hl.types.ArrayBytes_Int
  bool                      visibilityDirty;    // +0510
  void*                     HVIRTUAL_0x0518;    // +0518: HVIRTUAL
  // total_size: 0x0520
}; // ent_Faction (ent.Faction)

_Static_assert(sizeof(ent_Faction) == 0x0520, "cls ent.Faction has wrong size");


extern bool ent_Faction_set_isAI(ent_Faction* obj, bool arg1);
extern bool ent_Faction_hasLentUnit(ent_Faction* obj, ent_Unit* arg1, ent_Faction* arg2);
extern void ent_Faction_addLentUnits(ent_Faction* obj, ent_Faction* arg1, hl_types_ArrayObj* arg2);
extern hl_types_ArrayObj* ent_Faction_removeLentUnits(ent_Faction* obj, ent_Faction* arg1, hl_types_ArrayObj* arg2);
extern String* ent_Faction_get_leader(ent_Faction* obj);
extern int ent_Faction_get_aiDifficulty(ent_Faction* obj);
extern int ent_Faction_set_aiDifficulty(ent_Faction* obj, int arg1);
extern String* ent_Faction_get_aiType(ent_Faction* obj);
extern String* ent_Faction_set_aiType(ent_Faction* obj, String* arg1);
extern void* ent_Faction_get_inf(ent_Faction* obj);
extern ent_Structure* ent_Faction_get_mainBase(ent_Faction* obj);
extern int ent_Faction_get_mainBaseMax(ent_Faction* obj);
extern void* ent_Faction_set_recruitPointX(ent_Faction* obj, void* arg1);
extern void* ent_Faction_set_recruitPointY(ent_Faction* obj, void* arg1);
extern h2d_col_PointImpl* ent_Faction_get_rallyPoint(ent_Faction* obj);
extern EReason* ent_Faction_implSetRallyPoint(ent_Faction* obj, double arg1, double arg2);
extern void ent_Faction_resetRallyPoint(ent_Faction* obj);
extern EReason* ent_Faction_implChooseHero(ent_Faction* obj, String* arg1);
extern String* ent_Faction_getChosenHero(ent_Faction* obj);
extern bool ent_Faction_hasChosenHero(ent_Faction* obj);
extern bool ent_Faction_isAllowedToChooseHero(ent_Faction* obj);
extern int ent_Faction_getHeroRecruitCount(ent_Faction* obj);
extern bool ent_Faction_isHeroAlive(ent_Faction* obj);
extern void ent_Faction_updateRallyPoint(ent_Faction* obj);
extern void ent_Faction_showRallyPoint(ent_Faction* obj);
extern void ent_Faction_removeRallyPointFeedback(ent_Faction* obj);
extern double ent_Faction_get_maxHegemonyValue(ent_Faction* obj);
extern logic_faction_Contract* ent_Faction_get_contract(ent_Faction* obj);
extern String* ent_Faction_getLogID(ent_Faction* obj);
extern void ent_Faction_tick(ent_Faction* obj, double arg1);
extern void ent_Faction_frameUpdate(ent_Faction* obj, double arg1);
extern logic_ai_AIController* ent_Faction_set_aiController(ent_Faction* obj, logic_ai_AIController* arg1);
extern void ent_Faction_init(ent_Faction* obj);
extern void ent_Faction_finalize(ent_Faction* obj);
extern void ent_Faction_onReady(ent_Faction* obj);
extern bool ent_Faction_canExchangeSpice(ent_Faction* obj);
extern bool ent_Faction_hasSpiceContractEnabled(ent_Faction* obj);
extern bool ent_Faction_isLandsraadLocked(ent_Faction* obj);
extern int ent_Faction_set_currentHegemonyBonus(ent_Faction* obj, int arg1);
extern String* ent_Faction_getExposedName(ent_Faction* obj);
extern String* ent_Faction_getExposedRichName(ent_Faction* obj);
extern hl_types_ArrayObj* ent_Faction_getAllies(ent_Faction* obj);
extern hl_types_ArrayObj* ent_Faction_getVillages(ent_Faction* obj);
extern hl_types_ArrayObj* ent_Faction_getBuildings(ent_Faction* obj);
extern ent_NuclearSilo* ent_Faction_findFirstActiveNuclearSilo(ent_Faction* obj);
extern ent_SpacingGuildBranch* ent_Faction_findFirstActiveGuildBranch(ent_Faction* obj);
extern void ent_Faction_loseGuildBranch(ent_Faction* obj, ent_SpacingGuildBranch* arg1);
extern void ent_Faction_loseRecyclingPlant(ent_Faction* obj, ent_RecyclingPlant* arg1);
extern bool ent_Faction_hasGameEnded(ent_Faction* obj, void* arg1);
extern void ent_Faction_pickRandomCouncilors(ent_Faction* obj);
extern void ent_Faction_assignCouncilor(ent_Faction* obj, String* arg1, int arg2, void* arg3);
extern void ent_Faction_removeCouncilor(ent_Faction* obj, String* arg1, void* arg2, void* arg3);
extern bool ent_Faction_isDead(ent_Faction* obj);
extern int ent_Faction_getUpgradeFactionCount(ent_Faction* obj, String* arg1, void* arg2);
extern bool ent_Faction_isDiscovered(ent_Faction* obj, ent_Faction* arg1);
extern void ent_Faction_discoverFaction(ent_Faction* obj, ent_Faction* arg1);
extern void ent_Faction_playReconnedFx__impl(ent_Faction* obj, ent_Entity* arg1);
extern void* ent_Faction_getMaxResStock(ent_Faction* obj, String* arg1);
extern bool ent_Faction_hasAccessToLandsraad(ent_Faction* obj);
extern bool ent_Faction_hasAutoSplitDistrict(ent_Faction* obj);
extern hl_types_ArrayObj* ent_Faction_getCouncilVoteOpeningResourcesGain(ent_Faction* obj, void* arg1);
extern hl_types_ArrayObj* ent_Faction_getCouncilVoteEndResourcesGain(ent_Faction* obj);
extern bool ent_Faction_canCancelResolution(ent_Faction* obj, logic_state_CancelType* arg1);
extern hl_types_ArrayObj* ent_Faction_getCancelResolutionCapabilities(ent_Faction* obj);
extern bool ent_Faction_hasAccessToUWHeadquarters(ent_Faction* obj);
extern bool ent_Faction_hasAccessToMBUWHeadquarters(ent_Faction* obj);
extern bool ent_Faction_hasAccessToLocalSietches(ent_Faction* obj);
extern bool ent_Faction_hasAccessToRes(ent_Faction* obj, int arg1);
extern bool ent_Faction_canUseCellSearch(ent_Faction* obj);
extern bool ent_Faction_isTargettedByAssassination(ent_Faction* obj, ent_Faction* arg1);
extern bool ent_Faction_isTargettedByAssassinationInProgress(ent_Faction* obj);
extern bool ent_Faction_resImplicatesProtection(ent_Faction* obj, int arg1);
extern bool ent_Faction_neverAccessToRes(ent_Faction* obj, int arg1);
extern double ent_Faction_addResource(ent_Faction* obj, String* arg1, double arg2, void* arg3, void* arg4);
extern double ent_Faction_addRawResource(ent_Faction* obj, String* arg1, double arg2, void* arg3, void* arg4);
extern double ent_Faction_getResource(ent_Faction* obj, int arg1);
extern bool ent_Faction_hasResource(ent_Faction* obj, int arg1, double arg2);
extern bool ent_Faction_hasResources(ent_Faction* obj, hl_types_ArrayObj* arg1);
extern bool ent_Faction_useResource(ent_Faction* obj, String* arg1, double arg2, void* arg3);
extern EReason* ent_Faction_implConvertResource(ent_Faction* obj, double arg1, String* arg2, String* arg3);
extern void ent_Faction_playResSpendFeedback__impl(ent_Faction* obj);
extern bool ent_Faction_removeAttribute(ent_Faction* obj, int arg1);
extern logic_AttributeApplication* ent_Faction_addAttributeRaw(ent_Faction* obj, int arg1, void* arg2);
extern hl_types_ArrayObj* ent_Faction_getAffectingAtbApps(ent_Faction* obj, int arg1, void* arg2, ent_Faction* arg3, hl_types_ArrayObj* arg4);
extern void ent_Faction_propagateClearAtbCache(ent_Faction* obj, int arg1, EScope* arg2, void* arg3, logic_AttributeApplication* arg4);
extern double ent_Faction_getSietchAllianceResUpkeep(ent_Faction* obj, int arg1);
extern hl_types_ArrayObj* ent_Faction_getSietchAllianceUpkeep(ent_Faction* obj);
extern hl_types_ArrayObj* ent_Faction_getRecruitableUnits(ent_Faction* obj);
extern int ent_Faction_getBaseUnitMax(ent_Faction* obj, String* arg1);
extern int ent_Faction_getUnitMax(ent_Faction* obj, String* arg1);
extern hl_types_ArrayObj* ent_Faction_getUnitRawImportCost(ent_Faction* obj, String* arg1, void* arg2, void* arg3);
extern hl_types_ArrayObj* ent_Faction_getUnitImportCost(ent_Faction* obj, String* arg1, void* arg2, void* arg3, void* arg4);
extern hl_types_ArrayObj* ent_Faction_getUnitReplacementImportCost(ent_Faction* obj, String* arg1, hl_types_ArrayObj* arg2);
extern hl_types_ArrayObj* ent_Faction_getUnitCostRatio(ent_Faction* obj, String* arg1, double arg2);
extern hl_types_ArrayObj* ent_Faction_getBaseUnitUpkeep(ent_Faction* obj, String* arg1, void* arg2, void* arg3);
extern hl_types_ArrayObj* ent_Faction_getUnitUpkeep(ent_Faction* obj, String* arg1, void* arg2, void* arg3);
extern double ent_Faction_getBaseUnitResUpkeep(ent_Faction* obj, void* arg1, int arg2);
extern double ent_Faction_getUnitResUpkeep(ent_Faction* obj, void* arg1, int arg2);
extern void ent_Faction_forUnitsOfType(ent_Faction* obj, hl_Class* arg1, void* arg2);
extern hl_types_ArrayObj* ent_Faction_getUnitsOfType(ent_Faction* obj, hl_Class* arg1);
extern hl_types_ArrayObj* ent_Faction_getUnits(ent_Faction* obj, String* arg1);
extern hl_types_ArrayObj* ent_Faction_getHarvestingUnits(ent_Faction* obj);
extern bool ent_Faction_hasOutpost(ent_Faction* obj, String* arg1);
extern bool ent_Faction_hasCharacter(ent_Faction* obj, String* arg1);
extern ent_Entity* ent_Faction_getClosestAirfieldInRange(ent_Faction* obj, h2d_col_PointImpl* arg1);
extern hl_types_ArrayObj* ent_Faction_getAirfields(ent_Faction* obj, void* arg1);
extern bool ent_Faction_isPosInAirfieldRange(ent_Faction* obj, h2d_col_PointImpl* arg1);
extern EReason* ent_Faction_getAirfieldPosNoUseReason(ent_Faction* obj, h2d_col_PointImpl* arg1, void* arg2, void* arg3);
extern ent_Faction* ent_Faction_getAirfieldFactionInRange(ent_Faction* obj, h2d_col_PointImpl* arg1);
extern hl_types_ArrayObj* ent_Faction_getOutposts(ent_Faction* obj);
extern ent_Structure* ent_Faction_getClosestMainBase(ent_Faction* obj, h2d_col_PointImpl* arg1);
extern void ent_Faction_createStartBase(ent_Faction* obj);
extern void ent_Faction_createConquestBases(ent_Faction* obj);
extern void ent_Faction_createBaseOnZone(ent_Faction* obj, ent_Zone* arg1, void* arg2, h2d_col_PointImpl* arg3);
extern void ent_Faction_onLoadingFinished(ent_Faction* obj, bool arg1);
extern void ent_Faction_playBaseSpawnEffects__impl(ent_Faction* obj, ent_Structure* arg1);
extern hl_types_ArrayObj* ent_Faction_getAllMainBases(ent_Faction* obj);
extern void ent_Faction_loseMainBase__impl(ent_Faction* obj, ent_Structure* arg1);
extern int ent_Faction_getEquipmentMaxSlot(ent_Faction* obj, String* arg1);
extern void ent_Faction_gainControl(ent_Faction* obj, ent_Structure* arg1);
extern void ent_Faction_gainControlAlert(ent_Faction* obj, ent_Structure* arg1);
extern void ent_Faction_loseControl(ent_Faction* obj, ent_Structure* arg1);
extern EReason* ent_Faction_implAddConquestBonus(ent_Faction* obj, String* arg1);
extern void ent_Faction_triggerPostConquestBonus(ent_Faction* obj, String* arg1);
extern EReason* ent_Faction_implRemoveConquestBonus(ent_Faction* obj, String* arg1);
extern void ent_Faction_rpcDisplayLoot__impl(ent_Faction* obj, hl_types_ArrayObj* arg1, void* arg2);
extern void ent_Faction_rpcGenerateProjectile__impl(ent_Faction* obj, String* arg1, void* arg2, void* arg3);
extern bool ent_Faction_canBuildInMainBase(ent_Faction* obj);
extern void ent_Faction_attackerImplications(ent_Faction* obj, ent_Entity* arg1);
extern int ent_Faction_getDiplomacyIndex(ent_Faction* obj, ent_Faction* arg1);
extern void ent_Faction_changeDiplomaticStatus(ent_Faction* obj, ent_Faction* arg1, String* arg2, void* arg3, void* arg4, void* arg5);
extern String* ent_Faction_getSelfDiplomaticStatus(ent_Faction* obj, ent_Faction* arg1);
extern String* ent_Faction_getOtherFactionDiplomaticStatus(ent_Faction* obj, ent_Faction* arg1);
extern bool ent_Faction_isDiplomaticStatusValid(ent_Faction* obj, ent_Faction* arg1, DiplomacySource* arg2);
extern EReason* ent_Faction_getDiplomaticReason(ent_Faction* obj, ent_Faction* arg1, DiplomacySource* arg2);
extern hl_types_ArrayObj* ent_Faction_getAllRelationshipData(ent_Faction* obj);
extern hl_types_ArrayObj* ent_Faction_getTradableResources(ent_Faction* obj, ent_Faction* arg1);
extern bool ent_Faction_canSpendProd(ent_Faction* obj, String* arg1, double arg2);
extern void ent_Faction_breakTruceWithAll(ent_Faction* obj, ent_EHostileActionType* arg1);
extern void ent_Faction_removeOnTreasonProtection(ent_Faction* obj);
extern void ent_Faction_onHostileAction__impl(ent_Faction* obj, ent_Faction* arg1, ent_EHostileActionType* arg2);
extern double ent_Faction_getHostileActionStandingLoss(ent_Faction* obj, ent_Faction* arg1, double arg2);
extern void ent_Faction_cycleBuilding(ent_Faction* obj, String* arg1);
extern void ent_Faction_cycleUnit(ent_Faction* obj, String* arg1);
extern void ent_Faction_computeCacheData(ent_Faction* obj);
extern void* ent_Faction_getActiveStandingIndex(ent_Faction* obj);
extern void* ent_Faction_getActiveStandingInfo(ent_Faction* obj);
extern void ent_Faction_update(ent_Faction* obj, double arg1);
extern void ent_Faction_frameRegularUpdate(ent_Faction* obj, double arg1);
extern void ent_Faction_serverFrameRegularUpdate(ent_Faction* obj, double arg1);
extern void ent_Faction_regularUpdate(ent_Faction* obj, double arg1);
extern void ent_Faction_clientRegularUpdate(ent_Faction* obj, double arg1);
extern void ent_Faction_dailyUpdate(ent_Faction* obj);
extern void ent_Faction_updateAttributes(ent_Faction* obj, double arg1);
extern void ent_Faction_updateReminderAlert(ent_Faction* obj);
extern void ent_Faction_updateResource(ent_Faction* obj, void* arg1, double arg2);
extern double ent_Faction_prodOutput(ent_Faction* obj, void* arg1, double arg2, double arg3);
extern void ent_Faction_resourcesUpdate(ent_Faction* obj, void* arg1);
extern double ent_Faction_getCachedResProd(ent_Faction* obj, int arg1);
extern double ent_Faction_getCachedResNetProd(ent_Faction* obj, int arg1);
extern double ent_Faction_getCachedResConso(ent_Faction* obj, int arg1);
extern double ent_Faction_getCachedRegenUpkeep(ent_Faction* obj, int arg1);
extern double ent_Faction_getDeficit(ent_Faction* obj, String* arg1);
extern double ent_Faction_getResourceProduction(ent_Faction* obj, int arg1, void* arg2, ProductionKind* arg3, void* arg4, void* arg5);
extern String* ent_Faction_getMarkRoot(ent_Faction* obj);
extern double ent_Faction_doGetResourceProductionDetail(ent_Faction* obj, int arg1, void* arg2, ProductionKind* arg3, void* arg4, void* arg5);
extern int ent_Faction_getChartersCount(ent_Faction* obj);
extern bool ent_Faction_hasCharter(ent_Faction* obj, String* arg1);
extern int ent_Faction_getOngoingAnnexationsCount(ent_Faction* obj);
extern double ent_Faction_getBaseProduction(ent_Faction* obj, String* arg1);
extern double ent_Faction_getResRegenRatio(ent_Faction* obj, String* arg1);
extern bool ent_Faction_hasDiscoveredCell(ent_Faction* obj, ent_ZoneCell* arg1);
extern bool ent_Faction_isInDiscoveredCell(ent_Faction* obj, ent_Entity* arg1);
extern bool ent_Faction_isCellVisible(ent_Faction* obj, ent_ZoneCell* arg1);
extern bool ent_Faction_isInVisibleCell(ent_Faction* obj, ent_Entity* arg1);
extern bool ent_Faction_isPointVisible(ent_Faction* obj, h2d_col_PointImpl* arg1);
extern void ent_Faction_applyVisibility(ent_Faction* obj, void* arg1);
extern void ent_Faction_discoverAll(ent_Faction* obj);
extern void ent_Faction_discoverZone(ent_Faction* obj, ent_Zone* arg1);
extern void ent_Faction_discoverCell(ent_Faction* obj, ent_ZoneCell* arg1);
extern void ent_Faction_markDiscoveredCells(ent_Faction* obj);
extern void ent_Faction_updateFactionsTerritories__impl(ent_Faction* obj, String* arg1);
extern void ent_Faction_onCellDiscover(ent_Faction* obj, int arg1);
extern void ent_Faction_onDiscover__impl(ent_Faction* obj, int arg1);
extern void ent_Faction_selectEntity__impl(ent_Faction* obj, ent_Entity* arg1);
extern void ent_Faction_onEntityCellChange(ent_Faction* obj, ent_Entity* arg1, ent_ZoneCell* arg2);
extern void ent_Faction_onEntityCreated(ent_Faction* obj, ent_Entity* arg1);
extern void ent_Faction_onEntityRemoved(ent_Faction* obj, ent_Entity* arg1);
extern void ent_Faction_onStructureReconned(ent_Faction* obj, ent_Structure* arg1);
extern void ent_Faction_onUnitDamaged(ent_Faction* obj, ent_Unit* arg1, ent_Entity* arg2);
extern void ent_Faction_applyLocalVisibility__impl(ent_Faction* obj);
extern void ent_Faction_doApplyLocalVisibility(ent_Faction* obj);
extern void ent_Faction_onZonesChanged(ent_Faction* obj);
extern void ent_Faction_onAirfieldsChanged(ent_Faction* obj);
extern void ent_Faction_onNeuralGridChanged(ent_Faction* obj);
extern void ent_Faction_onProjectilesChanged(ent_Faction* obj);
extern void ent_Faction_refreshWorldRanges__impl(ent_Faction* obj);
extern void ent_Faction_onTraitEnd(ent_Faction* obj, logic_Application* arg1, bool arg2);
extern bool ent_Faction_isUnitBuyable(ent_Faction* obj, String* arg1);
extern int ent_Faction_getMaxTrainingSlots(ent_Faction* obj);
extern int ent_Faction_getAvailableTrainingSlots(ent_Faction* obj);
extern double ent_Faction_getCurrentContractCost(ent_Faction* obj);
extern int ent_Faction_getHarvesterCount(ent_Faction* obj);
extern void ent_Faction_onEvent(ent_Faction* obj, lib_Event* arg1);
extern void ent_Faction_playSound(ent_Faction* obj, String* arg1, String* arg2);
extern void ent_Faction_onTreatyBreakAttempt(ent_Faction* obj, void* arg1);
extern void ent_Faction_addSietchReveal(ent_Faction* obj, double arg1);
extern void ent_Faction_doRemove(ent_Faction* obj);
extern void ent_Faction_patchEntity(ent_Faction* obj, int arg1);
extern String* ent_Faction_getIdStr(ent_Faction* obj);
extern int ent_Faction_getCLID(ent_Faction* obj);
extern void ent_Faction_serialize(ent_Faction* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* ent_Faction_getSerializeSchema(ent_Faction* obj);
extern void ent_Faction_unserializeInit(ent_Faction* obj);
extern void ent_Faction_unserialize(ent_Faction* obj, hxbit_Serializer* arg1);
extern EReason* ent_Faction_setRallyPoint(ent_Faction* obj, double arg1, double arg2, void* arg3);
extern bool ent_Faction_rpcSetRallyPoint__impl(ent_Faction* obj, double arg1, double arg2);
extern EReason* ent_Faction_checkSetRallyPoint(ent_Faction* obj, double arg1, double arg2);
extern bool ent_Faction_canSetRallyPoint(ent_Faction* obj, double arg1, double arg2);
extern EReason* ent_Faction_chooseHero(ent_Faction* obj, String* arg1, void* arg2);
extern bool ent_Faction_rpcChooseHero__impl(ent_Faction* obj, String* arg1);
extern EReason* ent_Faction_checkChooseHero(ent_Faction* obj, String* arg1);
extern bool ent_Faction_canChooseHero(ent_Faction* obj, String* arg1);
extern EReason* ent_Faction_convertResource(ent_Faction* obj, double arg1, String* arg2, String* arg3, void* arg4);
extern bool ent_Faction_rpcConvertResource__impl(ent_Faction* obj, double arg1, String* arg2, String* arg3);
extern EReason* ent_Faction_checkConvertResource(ent_Faction* obj, double arg1, String* arg2, String* arg3);
extern bool ent_Faction_canConvertResource(ent_Faction* obj, double arg1, String* arg2, String* arg3);
extern EReason* ent_Faction_addConquestBonus(ent_Faction* obj, String* arg1, void* arg2);
extern bool ent_Faction_rpcAddConquestBonus__impl(ent_Faction* obj, String* arg1);
extern EReason* ent_Faction_checkAddConquestBonus(ent_Faction* obj, String* arg1);
extern bool ent_Faction_canAddConquestBonus(ent_Faction* obj, String* arg1);
extern EReason* ent_Faction_removeConquestBonus(ent_Faction* obj, String* arg1, void* arg2);
extern bool ent_Faction_rpcRemoveConquestBonus__impl(ent_Faction* obj, String* arg1);
extern EReason* ent_Faction_checkRemoveConquestBonus(ent_Faction* obj, String* arg1);
extern bool ent_Faction_canRemoveConquestBonus(ent_Faction* obj, String* arg1);
extern bool ent_Faction___net_mark_isAI(ent_Faction* obj, bool arg1);
extern int ent_Faction_get_networkPropIsAI(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_structures(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_structures(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropStructures(ent_Faction* obj);
extern String* ent_Faction___net_mark_kind(ent_Faction* obj, String* arg1);
extern String* ent_Faction_set_kind(ent_Faction* obj, String* arg1);
extern int ent_Faction_get_networkPropKind(ent_Faction* obj);
extern logic_FogOfWar* ent_Faction___net_mark_fog(ent_Faction* obj, logic_FogOfWar* arg1);
extern logic_FogOfWar* ent_Faction_set_fog(ent_Faction* obj, logic_FogOfWar* arg1);
extern int ent_Faction_get_networkPropFog(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_zones(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_zones(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropZones(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_occupations(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_occupations(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropOccupations(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_armies(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_armies(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropArmies(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_units(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_units(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropUnits(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_lentUnits(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_lentUnits(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropLentUnits(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_councilors(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_councilors(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropCouncilors(ent_Faction* obj);
extern logic_state_FactionStateData* ent_Faction___net_mark_stateData(ent_Faction* obj, logic_state_FactionStateData* arg1);
extern logic_state_FactionStateData* ent_Faction_set_stateData(ent_Faction* obj, logic_state_FactionStateData* arg1);
extern int ent_Faction_get_networkPropStateData(ent_Faction* obj);
extern logic_ai_AIController* ent_Faction___net_mark_aiController(ent_Faction* obj, logic_ai_AIController* arg1);
extern int ent_Faction_get_networkPropAiController(ent_Faction* obj);
extern logic_ai_AIControllerData* ent_Faction___net_mark_aiControllerData(ent_Faction* obj, logic_ai_AIControllerData* arg1);
extern logic_ai_AIControllerData* ent_Faction_set_aiControllerData(ent_Faction* obj, logic_ai_AIControllerData* arg1);
extern int ent_Faction_get_networkPropAiControllerData(ent_Faction* obj);
extern hxbit_ObjProxy_4a95719587202e1febd0b8ee4507b4f9* ent_Faction___net_mark_endGameData(ent_Faction* obj, hxbit_ObjProxy_4a95719587202e1febd0b8ee4507b4f9* arg1);
extern hxbit_ObjProxy_4a95719587202e1febd0b8ee4507b4f9* ent_Faction_set_endGameData(ent_Faction* obj, hxbit_ObjProxy_4a95719587202e1febd0b8ee4507b4f9* arg1);
extern int ent_Faction_get_networkPropEndGameData(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_logics(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_logics(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropLogics(ent_Faction* obj);
extern logic_faction_TutorialManager* ent_Faction___net_mark_tutorialManager(ent_Faction* obj, logic_faction_TutorialManager* arg1);
extern logic_faction_TutorialManager* ent_Faction_set_tutorialManager(ent_Faction* obj, logic_faction_TutorialManager* arg1);
extern int ent_Faction_get_networkPropTutorialManager(ent_Faction* obj);
extern void* ent_Faction___net_mark_recruitPointX(ent_Faction* obj, void* arg1);
extern int ent_Faction_get_networkPropRecruitPointX(ent_Faction* obj);
extern void* ent_Faction___net_mark_recruitPointY(ent_Faction* obj, void* arg1);
extern int ent_Faction_get_networkPropRecruitPointY(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_tradingSietches(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_tradingSietches(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropTradingSietches(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_allySietches(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_allySietches(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropAllySietches(ent_Faction* obj);
extern hl_types_ArrayBytes_Int* ent_Faction___net_mark_discoveredCells(ent_Faction* obj, hl_types_ArrayBytes_Int* arg1);
extern hl_types_ArrayBytes_Int* ent_Faction_set_discoveredCells(ent_Faction* obj, hl_types_ArrayBytes_Int* arg1);
extern int ent_Faction_get_networkPropDiscoveredCells(ent_Faction* obj);
extern hl_types_ArrayBytes_Int* ent_Faction___net_mark_fullyVisibleCells(ent_Faction* obj, hl_types_ArrayBytes_Int* arg1);
extern hl_types_ArrayBytes_Int* ent_Faction_set_fullyVisibleCells(ent_Faction* obj, hl_types_ArrayBytes_Int* arg1);
extern int ent_Faction_get_networkPropFullyVisibleCells(ent_Faction* obj);
extern hxbit_MapData* ent_Faction___net_mark_targetingScores(ent_Faction* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_Faction_set_targetingScores(ent_Faction* obj, hxbit_MapData* arg1);
extern int ent_Faction_get_networkPropTargetingScores(ent_Faction* obj);
extern void* ent_Faction___net_mark_config(ent_Faction* obj, void* arg1);
extern void* ent_Faction_set_config(ent_Faction* obj, void* arg1);
extern int ent_Faction_get_networkPropConfig(ent_Faction* obj);
extern bool ent_Faction___net_mark_initialSpiceReconned(ent_Faction* obj, bool arg1);
extern bool ent_Faction_set_initialSpiceReconned(ent_Faction* obj, bool arg1);
extern int ent_Faction_get_networkPropInitialSpiceReconned(ent_Faction* obj);
extern hxbit_ArrayProxyData* ent_Faction___net_mark_conquestBonuses(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* ent_Faction_set_conquestBonuses(ent_Faction* obj, hxbit_ArrayProxyData* arg1);
extern int ent_Faction_get_networkPropConquestBonuses(ent_Faction* obj);
extern hxbit_MapData* ent_Faction___net_mark_nextDonationStamps(ent_Faction* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_Faction_set_nextDonationStamps(ent_Faction* obj, hxbit_MapData* arg1);
extern int ent_Faction_get_networkPropNextDonationStamps(ent_Faction* obj);
extern hxbit_MapData* ent_Faction___net_mark_nextRaidStamps(ent_Faction* obj, hxbit_MapData* arg1);
extern hxbit_MapData* ent_Faction_set_nextRaidStamps(ent_Faction* obj, hxbit_MapData* arg1);
extern int ent_Faction_get_networkPropNextRaidStamps(ent_Faction* obj);
extern void ent_Faction_playReconnedFx(ent_Faction* obj, ent_Entity* arg1);
extern void ent_Faction_playResSpendFeedback(ent_Faction* obj);
extern void ent_Faction_playBaseSpawnEffects(ent_Faction* obj, ent_Structure* arg1);
extern void ent_Faction_loseMainBase(ent_Faction* obj, ent_Structure* arg1);
extern void ent_Faction_rpcDisplayLoot(ent_Faction* obj, hl_types_ArrayObj* arg1, void* arg2);
extern void ent_Faction_rpcGenerateProjectile(ent_Faction* obj, String* arg1, void* arg2, void* arg3);
extern void ent_Faction_onHostileAction(ent_Faction* obj, ent_Faction* arg1, ent_EHostileActionType* arg2);
extern void ent_Faction_updateFactionsTerritories(ent_Faction* obj, String* arg1);
extern void ent_Faction_onDiscover(ent_Faction* obj, int arg1);
extern void ent_Faction_selectEntity(ent_Faction* obj, ent_Entity* arg1);
extern void ent_Faction_applyLocalVisibility(ent_Faction* obj);
extern void ent_Faction_refreshWorldRanges(ent_Faction* obj);
extern void ent_Faction_rpcSetRallyPoint(ent_Faction* obj, double arg1, double arg2, void* arg3);
extern void ent_Faction_rpcChooseHero(ent_Faction* obj, String* arg1, void* arg2);
extern void ent_Faction_rpcConvertResource(ent_Faction* obj, double arg1, String* arg2, String* arg3, void* arg4);
extern void ent_Faction_rpcAddConquestBonus(ent_Faction* obj, String* arg1, void* arg2);
extern void ent_Faction_rpcRemoveConquestBonus(ent_Faction* obj, String* arg1, void* arg2);
extern void ent_Faction_networkFlush(ent_Faction* obj, hxbit_Serializer* arg1);
extern void ent_Faction_networkSync(ent_Faction* obj, hxbit_Serializer* arg1);
extern void ent_Faction_networkInitProxys(ent_Faction* obj);
extern bool ent_Faction_networkRPC(ent_Faction* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* ent_Faction_networkGetName(ent_Faction* obj, int arg1, void* arg2);
extern ent_HegemonyData* ent_Faction_get_hegemonyData(ent_Faction* obj);
extern logic_faction_Developments* ent_Faction_get_developments(ent_Faction* obj);
extern logic_faction_AlertsManager* ent_Faction_get_alerts(ent_Faction* obj);
extern logic_faction_Contracts* ent_Faction_get_contractManager(ent_Faction* obj);
extern logic_faction_Quests* ent_Faction_get_quests(ent_Faction* obj);
extern logic_faction_Airfield* ent_Faction_get_airField(ent_Faction* obj);
extern logic_faction_MissionManager* ent_Faction_get_missionManager(ent_Faction* obj);
extern logic_faction_SpyManager* ent_Faction_get_spyManager(ent_Faction* obj);
extern logic_faction_SupplyLines* ent_Faction_get_supplyLines(ent_Faction* obj);
extern logic_faction_AbilityManager* ent_Faction_get_abilities(ent_Faction* obj);
extern logic_faction_Interactions* ent_Faction_get_interactions(ent_Faction* obj);
extern logic_faction_WormRiding* ent_Faction_get_wormRiding(ent_Faction* obj);
extern logic_faction_ControlGroups* ent_Faction_get_controlGroups(ent_Faction* obj);
extern logic_faction_Equipments* ent_Faction_get_equipments(ent_Faction* obj);
extern logic_faction_Objectives* ent_Faction_get_objectives(ent_Faction* obj);
extern logic_faction_NeuralGrid* ent_Faction_get_neuralGrid(ent_Faction* obj);


#endif // __gen_t_ent_Faction_h__
