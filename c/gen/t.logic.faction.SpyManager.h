// gen time: 2024-07-21 07:23:49 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_SpyManager_h__
#define __gen_t_logic_faction_SpyManager_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct EAgentAssignment EAgentAssignment;
typedef struct EReason EReason;
typedef struct ProductionKind ProductionKind;
typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Zone ent_Zone;
typedef struct h2d_col_PointImpl h2d_col_PointImpl;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_ObjProxy_e511870af8747c85d9236828e5a713fe hxbit_ObjProxy_e511870af8747c85d9236828e5a713fe;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_Event lib_Event;
typedef struct logic_faction_Agent logic_faction_Agent;
typedef struct logic_faction_CounterintelWeightGoal logic_faction_CounterintelWeightGoal;
typedef struct logic_faction_SpyManager logic_faction_SpyManager;


// type: logic.faction.SpyManager, kind: HOBJ, pType: 0x02A76E31E758
struct logic_faction_SpyManager {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.SpyManager, begin_offset: 0x00B0
  hxbit_ArrayProxyData*     agents;             // +00B0: HOBJ hxbit.ArrayProxyData
  hxbit_MapData*            gainedSlots;        // +00B8: HOBJ hxbit.MapData
  hl_types_ArrayObj*        levels;             // +00C0: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        infoOnPlayers;      // +00C8: HOBJ hl.types.ArrayObj
  hxbit_ObjProxy_e511870af8747c85d9236828e5a713fe* assassination; // +00D0: HOBJ hxbit.ObjProxy_e511870af8747c85d9236828e5a713fe
  hxbit_MapData*            sacrificedAgentsOnMission; // +00D8: HOBJ hxbit.MapData
  int                       sacrificedAgents;   // +00E0
  hl_types_ArrayObj*        tmpApps;            // +00E8: HOBJ hl.types.ArrayObj
  logic_faction_Agent*      selectedAgent;      // +00F0: HOBJ logic.faction.Agent
  h2d_col_PointImpl*        selectedAgentPos;   // +00F8: HOBJ h2d.col.PointImpl
  double                    time;               // +0100
  // total_size: 0x0108
}; // logic_faction_SpyManager (logic.faction.SpyManager)

_Static_assert(sizeof(logic_faction_SpyManager) == 0x0108, "cls logic.faction.SpyManager has wrong size");


extern void logic_faction_SpyManager_onReady(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_reload(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_addStartAgents(logic_faction_SpyManager* obj);
extern int logic_faction_SpyManager_getCurrentLevel(logic_faction_SpyManager* obj, EAgentAssignment* arg1, void* arg2);
extern void logic_faction_SpyManager_loseLevel(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern void logic_faction_SpyManager_gainLevel(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern double logic_faction_SpyManager_getMinForLevel(logic_faction_SpyManager* obj, int arg1);
extern double logic_faction_SpyManager_getMaxForLevel(logic_faction_SpyManager* obj, int arg1);
extern double logic_faction_SpyManager_getLevelProgress(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern double logic_faction_SpyManager_getInfiltrationIncrease(logic_faction_SpyManager* obj, EAgentAssignment* arg1, void* arg2, void* arg3);
extern int logic_faction_SpyManager_getLevelTarget(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern double logic_faction_SpyManager_getRawLevelCap(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern int logic_faction_SpyManager_getMinLevel(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern int logic_faction_SpyManager_getMaxLevel(logic_faction_SpyManager* obj);
extern void* logic_faction_SpyManager_getFactionInfo(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAllInformationsFor(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern bool logic_faction_SpyManager_canSacrificeAgentOnMission(logic_faction_SpyManager* obj, EAgentAssignment* arg1, void* arg2, void* arg3);
extern EReason* logic_faction_SpyManager_checkSacrificeAgentOnMission(logic_faction_SpyManager* obj, EAgentAssignment* arg1, void* arg2, void* arg3);
extern bool logic_faction_SpyManager_canSeeInformation(logic_faction_SpyManager* obj, String* arg1, ent_Faction* arg2);
extern void* logic_faction_SpyManager_getInfiltrationNeededLvl(logic_faction_SpyManager* obj, String* arg1, ent_Faction* arg2);
extern hl_types_ArrayObj* logic_faction_SpyManager_getInformationsForLvl(logic_faction_SpyManager* obj, int arg1, EAgentAssignment* arg2);
extern void logic_faction_SpyManager_gainExtraSlots(logic_faction_SpyManager* obj, String* arg1, int arg2);
extern int logic_faction_SpyManager_getNbSlots(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern int logic_faction_SpyManager_getNbSlotsMax(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern EReason* logic_faction_SpyManager_checkAssign(logic_faction_SpyManager* obj, EAgentAssignment* arg1, void* arg2);
extern logic_faction_Agent* logic_faction_SpyManager_createAgent(logic_faction_SpyManager* obj, void* arg1, hl_types_ArrayObj* arg2, void* arg3, ent_Faction* arg4);
extern hl_types_ArrayObj* logic_faction_SpyManager_getBuyableAgentTraits(logic_faction_SpyManager* obj);
extern hl_types_ArrayObj* logic_faction_SpyManager_getTraitCost(logic_faction_SpyManager* obj, void* arg1);
extern EReason* logic_faction_SpyManager_implBuyAgent(logic_faction_SpyManager* obj, String* arg1);
extern void logic_faction_SpyManager_removeAgent(logic_faction_SpyManager* obj, logic_faction_Agent* arg1);
extern bool logic_faction_SpyManager_agentSacrificeIsAllowed(logic_faction_SpyManager* obj);
extern bool logic_faction_SpyManager_regionSupervisionIsAllowed(logic_faction_SpyManager* obj, ent_Zone* arg1);
extern hl_types_ArrayObj* logic_faction_SpyManager_captureRandomAgent(logic_faction_SpyManager* obj, ent_Faction* arg1, void* arg2, void* arg3, void* arg4);
extern void logic_faction_SpyManager_freeRandomAgent(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern void logic_faction_SpyManager_onAgentCaptured(logic_faction_SpyManager* obj, logic_faction_Agent* arg1);
extern void logic_faction_SpyManager_stealAgent(logic_faction_SpyManager* obj, logic_faction_Agent* arg1, hl_types_ArrayObj* arg2);
extern int logic_faction_SpyManager_getCurrentAgentsNb(logic_faction_SpyManager* obj);
extern int logic_faction_SpyManager_getMaxAgentsNb(logic_faction_SpyManager* obj);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAgents(logic_faction_SpyManager* obj, void* arg1);
extern int logic_faction_SpyManager_nbAgents(logic_faction_SpyManager* obj, void* arg1);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAssignedAgents(logic_faction_SpyManager* obj);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAgentsUnassigned(logic_faction_SpyManager* obj);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAgentsAssignedOnInfiltration(logic_faction_SpyManager* obj);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAgentsAssignedOnFaction(logic_faction_SpyManager* obj, String* arg1, void* arg2);
extern int logic_faction_SpyManager_getNbAgentsAssignedOnFactionInfiltration(logic_faction_SpyManager* obj);
extern logic_faction_Agent* logic_faction_SpyManager_getUiAgentAssignedOnSlot(logic_faction_SpyManager* obj, EAgentAssignment* arg1, String* arg2, void* arg3);
extern hl_types_ArrayObj* logic_faction_SpyManager_getUiAgentsAssignedOnSlot(logic_faction_SpyManager* obj, EAgentAssignment* arg1, String* arg2);
extern logic_faction_Agent* logic_faction_SpyManager_getAgentAssignedOnSlot(logic_faction_SpyManager* obj, EAgentAssignment* arg1, void* arg2);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAgentsAssignedOnSlot(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern int logic_faction_SpyManager_getNbAgentsAssignedOnSlot(logic_faction_SpyManager* obj, EAgentAssignment* arg1);
extern hl_types_ArrayObj* logic_faction_SpyManager_getCounterIntelAgents(logic_faction_SpyManager* obj);
extern int logic_faction_SpyManager_getNbCounterIntelAgents(logic_faction_SpyManager* obj);
extern hl_types_ArrayObj* logic_faction_SpyManager_getCapturedEnemyAgents(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern hl_types_ArrayObj* logic_faction_SpyManager_getCapturedAgents(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern int logic_faction_SpyManager_getNbCapturedAgents(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAgentsActiveAtbApps(logic_faction_SpyManager* obj, int arg1, hl_types_ArrayObj* arg2);
extern double logic_faction_SpyManager_getAgentsActiveAtbVal(logic_faction_SpyManager* obj, int arg1);
extern double logic_faction_SpyManager_getCounterIntelAgentsNbWeighted(logic_faction_SpyManager* obj, logic_faction_CounterintelWeightGoal* arg1);
extern double logic_faction_SpyManager_getEnemyCounterIntelAgentsNbWeighted(logic_faction_SpyManager* obj, ent_Faction* arg1, logic_faction_CounterintelWeightGoal* arg2);
extern double logic_faction_SpyManager_doGetResourceProductionDetail(logic_faction_SpyManager* obj, int arg1, void* arg2, ProductionKind* arg3, void* arg4, void* arg5);
extern void logic_faction_SpyManager_updateNewAgents(logic_faction_SpyManager* obj, double arg1);
extern void logic_faction_SpyManager_updateInformationLevels(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_syncInformationVisual(logic_faction_SpyManager* obj, String* arg1);
extern void logic_faction_SpyManager_onOwnerDefeated(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_updateAgentTraits(logic_faction_SpyManager* obj);
extern hl_types_ArrayObj* logic_faction_SpyManager_getAssassinationUpkeep(logic_faction_SpyManager* obj);
extern double logic_faction_SpyManager_getAssassinationResUpkeep(logic_faction_SpyManager* obj, String* arg1, void* arg2);
extern double logic_faction_SpyManager_getAssassinationResUpkeepReplacements(logic_faction_SpyManager* obj, String* arg1, double arg2);
extern void logic_faction_SpyManager_updateAssassinations(logic_faction_SpyManager* obj, double arg1);
extern double logic_faction_SpyManager_getTargetDetectionChances(logic_faction_SpyManager* obj);
extern bool logic_faction_SpyManager_isAssassinatingTarget(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern bool logic_faction_SpyManager_isAssassinatingTargetDetected(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern bool logic_faction_SpyManager_isAssassinating(logic_faction_SpyManager* obj);
extern ent_Faction* logic_faction_SpyManager_getAssassinationTarget(logic_faction_SpyManager* obj);
extern double logic_faction_SpyManager_getAssassinationPercent(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern double logic_faction_SpyManager_getAssassinationFactor(logic_faction_SpyManager* obj);
extern double logic_faction_SpyManager_getAssassinationProgress(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern double logic_faction_SpyManager_getAssassinationEstimatedTime(logic_faction_SpyManager* obj);
extern double logic_faction_SpyManager_getAssassinationSpeedProgress(logic_faction_SpyManager* obj, double arg1);
extern double logic_faction_SpyManager_getAssassinationSpeedFromAgent(logic_faction_SpyManager* obj, double arg1);
extern double logic_faction_SpyManager_getAssassinationSpeedFromAgentPercent(logic_faction_SpyManager* obj, double arg1);
extern double logic_faction_SpyManager_getAssassinationSpeedProgressPercent(logic_faction_SpyManager* obj, double arg1);
extern int logic_faction_SpyManager_getAssassinationInfiltrationCellCount(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_updateAssassinationFactor(logic_faction_SpyManager* obj, double arg1);
extern void logic_faction_SpyManager_startAssassination(logic_faction_SpyManager* obj, ent_Faction* arg1, logic_faction_Agent* arg2);
extern void logic_faction_SpyManager_doCancelAssassination(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern EReason* logic_faction_SpyManager_implCancelAssassination(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern void logic_faction_SpyManager_assassinationDone(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_increaseUpkeepAssassination(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_resetFactorAssassination(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_assassinationTimeHasBeenIncreased(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_updateReminderAlert(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_regularUpdate(logic_faction_SpyManager* obj, double arg1);
extern void logic_faction_SpyManager_frameRegularUpdate(logic_faction_SpyManager* obj, double arg1);
extern void logic_faction_SpyManager_onAgentEscape(logic_faction_SpyManager* obj, logic_faction_Agent* arg1);
extern void logic_faction_SpyManager_updateAgentsEscape(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_onEvent(logic_faction_SpyManager* obj, lib_Event* arg1);
extern void logic_faction_SpyManager_checkSlots(logic_faction_SpyManager* obj, String* arg1);
extern void logic_faction_SpyManager_updateAgentsSteal(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_updateCaptureEnemyAgents(logic_faction_SpyManager* obj);
extern bool logic_faction_SpyManager_isSpyingLocked(logic_faction_SpyManager* obj);
extern EReason* logic_faction_SpyManager_buyAgent(logic_faction_SpyManager* obj, String* arg1, void* arg2);
extern bool logic_faction_SpyManager_rpcBuyAgent__impl(logic_faction_SpyManager* obj, String* arg1);
extern EReason* logic_faction_SpyManager_checkBuyAgent(logic_faction_SpyManager* obj, String* arg1);
extern bool logic_faction_SpyManager_canBuyAgent(logic_faction_SpyManager* obj, String* arg1);
extern EReason* logic_faction_SpyManager_cancelAssassination(logic_faction_SpyManager* obj, ent_Faction* arg1, void* arg2);
extern bool logic_faction_SpyManager_rpcCancelAssassination__impl(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern EReason* logic_faction_SpyManager_checkCancelAssassination(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern bool logic_faction_SpyManager_canCancelAssassination(logic_faction_SpyManager* obj, ent_Faction* arg1);
extern hxbit_ArrayProxyData* logic_faction_SpyManager___net_mark_agents(logic_faction_SpyManager* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_SpyManager_set_agents(logic_faction_SpyManager* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_SpyManager_get_networkPropAgents(logic_faction_SpyManager* obj);
extern hxbit_MapData* logic_faction_SpyManager___net_mark_gainedSlots(logic_faction_SpyManager* obj, hxbit_MapData* arg1);
extern hxbit_MapData* logic_faction_SpyManager_set_gainedSlots(logic_faction_SpyManager* obj, hxbit_MapData* arg1);
extern int logic_faction_SpyManager_get_networkPropGainedSlots(logic_faction_SpyManager* obj);
extern hxbit_ObjProxy_e511870af8747c85d9236828e5a713fe* logic_faction_SpyManager___net_mark_assassination(logic_faction_SpyManager* obj, hxbit_ObjProxy_e511870af8747c85d9236828e5a713fe* arg1);
extern hxbit_ObjProxy_e511870af8747c85d9236828e5a713fe* logic_faction_SpyManager_set_assassination(logic_faction_SpyManager* obj, hxbit_ObjProxy_e511870af8747c85d9236828e5a713fe* arg1);
extern int logic_faction_SpyManager_get_networkPropAssassination(logic_faction_SpyManager* obj);
extern hxbit_MapData* logic_faction_SpyManager___net_mark_sacrificedAgentsOnMission(logic_faction_SpyManager* obj, hxbit_MapData* arg1);
extern hxbit_MapData* logic_faction_SpyManager_set_sacrificedAgentsOnMission(logic_faction_SpyManager* obj, hxbit_MapData* arg1);
extern int logic_faction_SpyManager_get_networkPropSacrificedAgentsOnMission(logic_faction_SpyManager* obj);
extern int logic_faction_SpyManager___net_mark_sacrificedAgents(logic_faction_SpyManager* obj, int arg1);
extern int logic_faction_SpyManager_set_sacrificedAgents(logic_faction_SpyManager* obj, int arg1);
extern int logic_faction_SpyManager_get_networkPropSacrificedAgents(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_rpcBuyAgent(logic_faction_SpyManager* obj, String* arg1, void* arg2);
extern void logic_faction_SpyManager_rpcCancelAssassination(logic_faction_SpyManager* obj, ent_Faction* arg1, void* arg2);
extern void logic_faction_SpyManager_networkFlush(logic_faction_SpyManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_SpyManager_networkSync(logic_faction_SpyManager* obj, hxbit_Serializer* arg1);
extern void logic_faction_SpyManager_networkInitProxys(logic_faction_SpyManager* obj);
extern bool logic_faction_SpyManager_networkRPC(logic_faction_SpyManager* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_faction_SpyManager_networkGetName(logic_faction_SpyManager* obj, int arg1, void* arg2);
extern int logic_faction_SpyManager_getCLID(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_serialize(logic_faction_SpyManager* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_SpyManager_getSerializeSchema(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_unserializeInit(logic_faction_SpyManager* obj);
extern void logic_faction_SpyManager_unserialize(logic_faction_SpyManager* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_SpyManager_h__
