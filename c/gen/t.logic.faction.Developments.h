// gen time: 2024-07-21 07:22:47 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Developments_h__
#define __gen_t_logic_faction_Developments_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct ent_Player ent_Player;
typedef struct haxe_ds_StringMap haxe_ds_StringMap;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_ObjProxy_776f5107696a4b8bd1414fc6e33056a6 hxbit_ObjProxy_776f5107696a4b8bd1414fc6e33056a6;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Development logic_faction_Development;
typedef struct logic_faction_Developments logic_faction_Developments;


// type: logic.faction.Developments, kind: HOBJ, pType: 0x02A76E337438
struct logic_faction_Developments {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.Developments, begin_offset: 0x00B0
  hxbit_ArrayProxyData*     apps;               // +00B0: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     proxyApps;          // +00B8: HOBJ hxbit.ArrayProxyData
  logic_faction_Development* researched;        // +00C0: HOBJ logic.faction.Development
  hxbit_ArrayProxyData*     researchQueue;      // +00C8: HOBJ hxbit.ArrayProxyData
  hxbit_MapData*            inProgressDevPerKind; // +00D0: HOBJ hxbit.MapData
  hxbit_ArrayProxyData*     patented;           // +00D8: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     boughtPatents;      // +00E0: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     blackedOut;         // +00E8: HOBJ hxbit.ArrayProxyData
  haxe_ds_StringMap*        replacements;       // +00F0: HOBJ haxe.ds.StringMap
  haxe_ds_StringMap*        invReplacements;    // +00F8: HOBJ haxe.ds.StringMap
  hl_types_ArrayObj*        factionDevs;        // +0100: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        completedSeen;      // +0108: HOBJ hl.types.ArrayObj
  hl_types_ArrayObj*        tmpRet;             // +0110: HOBJ hl.types.ArrayObj
  // total_size: 0x0118
}; // logic_faction_Developments (logic.faction.Developments)

_Static_assert(sizeof(logic_faction_Developments) == 0x0118, "cls logic.faction.Developments has wrong size");


extern int logic_faction_Developments_patentedCount(logic_faction_Developments* obj);
extern int logic_faction_Developments_blackedOutCount(logic_faction_Developments* obj);
extern bool logic_faction_Developments_isLocked(logic_faction_Developments* obj);
extern void logic_faction_Developments_getAllResearchedKinds(logic_faction_Developments* obj, hl_types_ArrayObj* arg1);
extern void logic_faction_Developments_init(logic_faction_Developments* obj);
extern void logic_faction_Developments_onReady(logic_faction_Developments* obj);
extern void logic_faction_Developments_reload(logic_faction_Developments* obj);
extern void logic_faction_Developments_updateCurrent(logic_faction_Developments* obj, double arg1);
extern void logic_faction_Developments_regularUpdate(logic_faction_Developments* obj, double arg1);
extern void logic_faction_Developments_onOwnerDefeated(logic_faction_Developments* obj);
extern bool logic_faction_Developments_canStartNewResearch(logic_faction_Developments* obj);
extern void logic_faction_Developments_resetSeen(logic_faction_Developments* obj);
extern bool logic_faction_Developments_sharesAny(logic_faction_Developments* obj);
extern hl_types_ArrayObj* logic_faction_Developments_getSharingPlayers(logic_faction_Developments* obj);
extern void logic_faction_Developments_refreshProxiedDevelopments(logic_faction_Developments* obj);
extern void logic_faction_Developments_refreshProxies(logic_faction_Developments* obj);
extern bool logic_faction_Developments_areDevelopmentsBlocked(logic_faction_Developments* obj);
extern logic_faction_Development* logic_faction_Developments_getResearched(logic_faction_Developments* obj);
extern bool logic_faction_Developments_isSearching(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_isBasicUnlocked(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_isUnlocked(logic_faction_Developments* obj, String* arg1, void* arg2);
extern int logic_faction_Developments_countIgnoredRequirements(logic_faction_Developments* obj, void* arg1);
extern int logic_faction_Developments_maxIgnorableRequirements(logic_faction_Developments* obj);
extern int logic_faction_Developments_remainingIgnorableRequirements(logic_faction_Developments* obj, void* arg1);
extern bool logic_faction_Developments_isRequirementInQueue(logic_faction_Developments* obj, String* arg1, void* arg2, void* arg3);
extern bool logic_faction_Developments_canUpgrade(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_isQueued(logic_faction_Developments* obj, String* arg1);
extern int logic_faction_Developments_getResearchQueueIndex(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_getQueueReason(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_isQueueEnabled(logic_faction_Developments* obj);
extern bool logic_faction_Developments_has(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_hasSelf(logic_faction_Developments* obj, String* arg1);
extern hxbit_ObjProxy_776f5107696a4b8bd1414fc6e33056a6* logic_faction_Developments_getSelf(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_hasProxy(logic_faction_Developments* obj, String* arg1);
extern hxbit_ObjProxy_776f5107696a4b8bd1414fc6e33056a6* logic_faction_Developments_getProxy(logic_faction_Developments* obj, String* arg1);
extern hl_types_ArrayObj* logic_faction_Developments_getAllOwned(logic_faction_Developments* obj, String* arg1);
extern void* logic_faction_Developments_getRandomResearchableDev(logic_faction_Developments* obj, String* arg1);
extern hl_types_ArrayObj* logic_faction_Developments_getResearchableDevs(logic_faction_Developments* obj, String* arg1);
extern void* logic_faction_Developments_getRandomMissingDev(logic_faction_Developments* obj, String* arg1);
extern hl_types_ArrayObj* logic_faction_Developments_getMissingDevs(logic_faction_Developments* obj, String* arg1);
extern hl_types_ArrayObj* logic_faction_Developments_getRemainingResearchedDevs(logic_faction_Developments* obj, String* arg1);
extern double logic_faction_Developments_getDevProgress(logic_faction_Developments* obj, String* arg1);
extern double logic_faction_Developments_getDevCurrentValue(logic_faction_Developments* obj, String* arg1);
extern double logic_faction_Developments_getDevelopmentRemainingDays(logic_faction_Developments* obj, String* arg1);
extern double logic_faction_Developments_getProgressSpeed(logic_faction_Developments* obj, void* arg1);
extern bool logic_faction_Developments_isDiplomaticallyBoosted(logic_faction_Developments* obj, String* arg1);
extern double logic_faction_Developments_getDevelopmentDuration(logic_faction_Developments* obj, String* arg1);
extern double logic_faction_Developments_getDevelopmentCostById(logic_faction_Developments* obj, String* arg1);
extern double logic_faction_Developments_getStepForDev(logic_faction_Developments* obj, String* arg1);
extern int logic_faction_Developments_get_ownedCount(logic_faction_Developments* obj);
extern int logic_faction_Developments_get_boughtPatentsCount(logic_faction_Developments* obj);
extern double logic_faction_Developments_get_totalResearchedSteps(logic_faction_Developments* obj);
extern double logic_faction_Developments_getStepFactor(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_implStartResearch(logic_faction_Developments* obj, String* arg1);
extern void logic_faction_Developments_doStartResearch(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_implCancelResearch(logic_faction_Developments* obj);
extern void logic_faction_Developments_addToQueue(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_implRemoveFromQueue(logic_faction_Developments* obj, String* arg1);
extern void logic_faction_Developments_fillDevsToRemoveFromQueue(logic_faction_Developments* obj, String* arg1, int arg2);
extern void logic_faction_Developments_addDaysToRandomResearchableDev(logic_faction_Developments* obj, double arg1, String* arg2);
extern logic_faction_Development* logic_faction_Developments_addDevKnowledge(logic_faction_Developments* obj, String* arg1, void* arg2);
extern void logic_faction_Developments_addDevDays(logic_faction_Developments* obj, String* arg1, double arg2);
extern logic_faction_Development* logic_faction_Developments_acquireDevelopment(logic_faction_Developments* obj, String* arg1);
extern logic_faction_Development* logic_faction_Developments_acquireUnlinkedDevelopment(logic_faction_Developments* obj, String* arg1);
extern hxbit_ObjProxy_776f5107696a4b8bd1414fc6e33056a6* logic_faction_Developments_doAcquireDevelopment(logic_faction_Developments* obj, logic_faction_Development* arg1, void* arg2);
extern void logic_faction_Developments_acquireDevelopmentFeedback__impl(logic_faction_Developments* obj, logic_faction_Development* arg1);
extern hxbit_ObjProxy_776f5107696a4b8bd1414fc6e33056a6* logic_faction_Developments_addDevelopment(logic_faction_Developments* obj, String* arg1, void* arg2);
extern bool logic_faction_Developments_addProxyDevelopment(logic_faction_Developments* obj, String* arg1, hl_types_ArrayObj* arg2);
extern bool logic_faction_Developments_removeProxyDevelopment(logic_faction_Developments* obj, String* arg1);
extern hl_types_ArrayObj* logic_faction_Developments_getPatentCost(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_isPatentedAvailable(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_hasPatentOn(logic_faction_Developments* obj, String* arg1);
extern ent_Player* logic_faction_Developments_getPatentOwner(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_implPatentDev(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_implBuyPatent(logic_faction_Developments* obj, String* arg1);
extern void logic_faction_Developments_onNewPatent(logic_faction_Developments* obj, String* arg1, ent_Faction* arg2);
extern ent_Player* logic_faction_Developments_getBlackoutOwner(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_implBlackoutDev(logic_faction_Developments* obj, String* arg1);
extern void logic_faction_Developments_onBlackout(logic_faction_Developments* obj, String* arg1, ent_Faction* arg2);
extern String* logic_faction_Developments_getValidDevelopmentKind(logic_faction_Developments* obj, String* arg1);
extern hl_types_ArrayObj* logic_faction_Developments_getTree(logic_faction_Developments* obj);
extern void* logic_faction_Developments_getTreeItem(logic_faction_Developments* obj, String* arg1);
extern String* logic_faction_Developments_getDevOrigin(logic_faction_Developments* obj, String* arg1);
extern String* logic_faction_Developments_getDevReplacement(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_treeContains(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_startResearch(logic_faction_Developments* obj, String* arg1, void* arg2);
extern bool logic_faction_Developments_rpcStartResearch__impl(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_checkStartResearch(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_canStartResearch(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_cancelResearch(logic_faction_Developments* obj, void* arg1);
extern bool logic_faction_Developments_rpcCancelResearch__impl(logic_faction_Developments* obj);
extern EReason* logic_faction_Developments_checkCancelResearch(logic_faction_Developments* obj);
extern bool logic_faction_Developments_canCancelResearch(logic_faction_Developments* obj);
extern EReason* logic_faction_Developments_removeFromQueue(logic_faction_Developments* obj, String* arg1, void* arg2);
extern bool logic_faction_Developments_rpcRemoveFromQueue__impl(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_checkRemoveFromQueue(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_canRemoveFromQueue(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_patentDev(logic_faction_Developments* obj, String* arg1, void* arg2);
extern bool logic_faction_Developments_rpcPatentDev__impl(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_checkPatentDev(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_canPatentDev(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_buyPatent(logic_faction_Developments* obj, String* arg1, void* arg2);
extern bool logic_faction_Developments_rpcBuyPatent__impl(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_checkBuyPatent(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_canBuyPatent(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_blackoutDev(logic_faction_Developments* obj, String* arg1, void* arg2);
extern bool logic_faction_Developments_rpcBlackoutDev__impl(logic_faction_Developments* obj, String* arg1);
extern EReason* logic_faction_Developments_checkBlackoutDev(logic_faction_Developments* obj, String* arg1);
extern bool logic_faction_Developments_canBlackoutDev(logic_faction_Developments* obj, String* arg1);
extern hxbit_ArrayProxyData* logic_faction_Developments___net_mark_apps(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Developments_set_apps(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Developments_get_networkPropApps(logic_faction_Developments* obj);
extern hxbit_ArrayProxyData* logic_faction_Developments___net_mark_proxyApps(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Developments_set_proxyApps(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Developments_get_networkPropProxyApps(logic_faction_Developments* obj);
extern logic_faction_Development* logic_faction_Developments___net_mark_researched(logic_faction_Developments* obj, logic_faction_Development* arg1);
extern logic_faction_Development* logic_faction_Developments_set_researched(logic_faction_Developments* obj, logic_faction_Development* arg1);
extern int logic_faction_Developments_get_networkPropResearched(logic_faction_Developments* obj);
extern hxbit_ArrayProxyData* logic_faction_Developments___net_mark_researchQueue(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Developments_set_researchQueue(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Developments_get_networkPropResearchQueue(logic_faction_Developments* obj);
extern hxbit_MapData* logic_faction_Developments___net_mark_inProgressDevPerKind(logic_faction_Developments* obj, hxbit_MapData* arg1);
extern hxbit_MapData* logic_faction_Developments_set_inProgressDevPerKind(logic_faction_Developments* obj, hxbit_MapData* arg1);
extern int logic_faction_Developments_get_networkPropInProgressDevPerKind(logic_faction_Developments* obj);
extern hxbit_ArrayProxyData* logic_faction_Developments___net_mark_patented(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Developments_set_patented(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Developments_get_networkPropPatented(logic_faction_Developments* obj);
extern hxbit_ArrayProxyData* logic_faction_Developments___net_mark_boughtPatents(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Developments_set_boughtPatents(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Developments_get_networkPropBoughtPatents(logic_faction_Developments* obj);
extern hxbit_ArrayProxyData* logic_faction_Developments___net_mark_blackedOut(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Developments_set_blackedOut(logic_faction_Developments* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Developments_get_networkPropBlackedOut(logic_faction_Developments* obj);
extern void logic_faction_Developments_acquireDevelopmentFeedback(logic_faction_Developments* obj, logic_faction_Development* arg1);
extern void logic_faction_Developments_rpcStartResearch(logic_faction_Developments* obj, String* arg1, void* arg2);
extern void logic_faction_Developments_rpcCancelResearch(logic_faction_Developments* obj, void* arg1);
extern void logic_faction_Developments_rpcRemoveFromQueue(logic_faction_Developments* obj, String* arg1, void* arg2);
extern void logic_faction_Developments_rpcPatentDev(logic_faction_Developments* obj, String* arg1, void* arg2);
extern void logic_faction_Developments_rpcBuyPatent(logic_faction_Developments* obj, String* arg1, void* arg2);
extern void logic_faction_Developments_rpcBlackoutDev(logic_faction_Developments* obj, String* arg1, void* arg2);
extern void logic_faction_Developments_networkFlush(logic_faction_Developments* obj, hxbit_Serializer* arg1);
extern void logic_faction_Developments_networkSync(logic_faction_Developments* obj, hxbit_Serializer* arg1);
extern void logic_faction_Developments_networkInitProxys(logic_faction_Developments* obj);
extern bool logic_faction_Developments_networkRPC(logic_faction_Developments* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_faction_Developments_networkGetName(logic_faction_Developments* obj, int arg1, void* arg2);
extern int logic_faction_Developments_getCLID(logic_faction_Developments* obj);
extern void logic_faction_Developments_serialize(logic_faction_Developments* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_Developments_getSerializeSchema(logic_faction_Developments* obj);
extern void logic_faction_Developments_unserializeInit(logic_faction_Developments* obj);
extern void logic_faction_Developments_unserialize(logic_faction_Developments* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_Developments_h__
