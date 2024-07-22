// gen time: 2024-07-21 07:22:47 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Contract_h__
#define __gen_t_logic_faction_Contract_h__

#include <common.h>
#include <gen/t.net.Serializable.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Faction ent_Faction;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_NetworkClient hxbit_NetworkClient;
typedef struct hxbit_NetworkSerializer hxbit_NetworkSerializer;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Contract logic_faction_Contract;


// type: logic.faction.Contract, kind: HOBJ, pType: 0x02A76E336918
struct logic_faction_Contract {
  // super: net.Serializable
  net_Serializable          super;

  // cls: logic.faction.Contract, begin_offset: 0x0038
  String*                   kind;               // +0038: HOBJ String
  ent_Faction*              owner;              // +0040: HOBJ ent.Faction
  int                       currentAmount;      // +0048
  int                       currentProdTax;     // +004C
  int                       lastAmount;         // +0050
  double                    spiceProdSinceContract; // +0058
  hxbit_ArrayProxyData*     payHistory;         // +0060: HOBJ hxbit.ArrayProxyData
  int                       currentLevel;       // +0068
  int                       scheduledLevel;     // +006C
  double                    levelChangeCooldown; // +0070
  void*                     inf;                // +0078: HVIRTUAL
  // total_size: 0x0080
}; // logic_faction_Contract (logic.faction.Contract)

_Static_assert(sizeof(logic_faction_Contract) == 0x0080, "cls logic.faction.Contract has wrong size");


extern String* logic_faction_Contract_get_targetFaction(logic_faction_Contract* obj);
extern void logic_faction_Contract_alive(logic_faction_Contract* obj);
extern int logic_faction_Contract_getTotalCost(logic_faction_Contract* obj);
extern int logic_faction_Contract_getBaseAmount(logic_faction_Contract* obj);
extern double logic_faction_Contract_getCostMultiplier(logic_faction_Contract* obj);
extern void logic_faction_Contract_nextContract(logic_faction_Contract* obj, void* arg1);
extern void logic_faction_Contract_updateLastAmount(logic_faction_Contract* obj);
extern void logic_faction_Contract_doPaidEffects(logic_faction_Contract* obj);
extern void logic_faction_Contract_doUnpaidEffects(logic_faction_Contract* obj);
extern void logic_faction_Contract_startHostileRaid(logic_faction_Contract* obj, String* arg1);
extern bool logic_faction_Contract_hasLevels(logic_faction_Contract* obj);
extern hl_types_ArrayObj* logic_faction_Contract_getLevels(logic_faction_Contract* obj);
extern double logic_faction_Contract_getCurrentLevelCostMultiplier(logic_faction_Contract* obj);
extern EReason* logic_faction_Contract_implScheduleLevelChange(logic_faction_Contract* obj, int arg1);
extern void logic_faction_Contract_changeToScheduledLevel(logic_faction_Contract* obj);
extern void logic_faction_Contract_doChangeLevel(logic_faction_Contract* obj, int arg1);
extern hl_types_ArrayObj* logic_faction_Contract_getOtherFactionsAffectedByLevel(logic_faction_Contract* obj);
extern void logic_faction_Contract_applyLevelEffects(logic_faction_Contract* obj, int arg1);
extern void logic_faction_Contract_removeLevelEffects(logic_faction_Contract* obj, int arg1);
extern hl_types_ArrayObj* logic_faction_Contract_getLevelChangeResourcesGain(logic_faction_Contract* obj, int arg1, int arg2);
extern bool logic_faction_Contract_isLevelValid(logic_faction_Contract* obj, int arg1);
extern bool logic_faction_Contract_isLevelChangeInCooldown(logic_faction_Contract* obj);
extern bool logic_faction_Contract_isChangingToLevelAllowed(logic_faction_Contract* obj, int arg1);
extern EReason* logic_faction_Contract_scheduleLevelChange(logic_faction_Contract* obj, int arg1, void* arg2);
extern bool logic_faction_Contract_rpcScheduleLevelChange__impl(logic_faction_Contract* obj, int arg1);
extern EReason* logic_faction_Contract_checkScheduleLevelChange(logic_faction_Contract* obj, int arg1);
extern bool logic_faction_Contract_canScheduleLevelChange(logic_faction_Contract* obj, int arg1);
extern String* logic_faction_Contract___net_mark_kind(logic_faction_Contract* obj, String* arg1);
extern String* logic_faction_Contract_set_kind(logic_faction_Contract* obj, String* arg1);
extern int logic_faction_Contract_get_networkPropKind(logic_faction_Contract* obj);
extern ent_Faction* logic_faction_Contract___net_mark_owner(logic_faction_Contract* obj, ent_Faction* arg1);
extern ent_Faction* logic_faction_Contract_set_owner(logic_faction_Contract* obj, ent_Faction* arg1);
extern int logic_faction_Contract_get_networkPropOwner(logic_faction_Contract* obj);
extern int logic_faction_Contract___net_mark_currentAmount(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_set_currentAmount(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_get_networkPropCurrentAmount(logic_faction_Contract* obj);
extern int logic_faction_Contract___net_mark_currentProdTax(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_set_currentProdTax(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_get_networkPropCurrentProdTax(logic_faction_Contract* obj);
extern int logic_faction_Contract___net_mark_lastAmount(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_set_lastAmount(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_get_networkPropLastAmount(logic_faction_Contract* obj);
extern double logic_faction_Contract___net_mark_spiceProdSinceContract(logic_faction_Contract* obj, double arg1);
extern double logic_faction_Contract_set_spiceProdSinceContract(logic_faction_Contract* obj, double arg1);
extern int logic_faction_Contract_get_networkPropSpiceProdSinceContract(logic_faction_Contract* obj);
extern hxbit_ArrayProxyData* logic_faction_Contract___net_mark_payHistory(logic_faction_Contract* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Contract_set_payHistory(logic_faction_Contract* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Contract_get_networkPropPayHistory(logic_faction_Contract* obj);
extern int logic_faction_Contract___net_mark_currentLevel(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_set_currentLevel(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_get_networkPropCurrentLevel(logic_faction_Contract* obj);
extern int logic_faction_Contract___net_mark_scheduledLevel(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_set_scheduledLevel(logic_faction_Contract* obj, int arg1);
extern int logic_faction_Contract_get_networkPropScheduledLevel(logic_faction_Contract* obj);
extern double logic_faction_Contract___net_mark_levelChangeCooldown(logic_faction_Contract* obj, double arg1);
extern double logic_faction_Contract_set_levelChangeCooldown(logic_faction_Contract* obj, double arg1);
extern int logic_faction_Contract_get_networkPropLevelChangeCooldown(logic_faction_Contract* obj);
extern void logic_faction_Contract_rpcScheduleLevelChange(logic_faction_Contract* obj, int arg1, void* arg2);
extern void logic_faction_Contract_networkFlush(logic_faction_Contract* obj, hxbit_Serializer* arg1);
extern void logic_faction_Contract_networkSync(logic_faction_Contract* obj, hxbit_Serializer* arg1);
extern void logic_faction_Contract_networkInitProxys(logic_faction_Contract* obj);
extern bool logic_faction_Contract_networkRPC(logic_faction_Contract* obj, hxbit_NetworkSerializer* arg1, int arg2, hxbit_NetworkClient* arg3);
extern String* logic_faction_Contract_networkGetName(logic_faction_Contract* obj, int arg1, void* arg2);
extern int logic_faction_Contract_getCLID(logic_faction_Contract* obj);
extern void logic_faction_Contract_serialize(logic_faction_Contract* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_Contract_getSerializeSchema(logic_faction_Contract* obj);
extern void logic_faction_Contract_unserializeInit(logic_faction_Contract* obj);
extern void logic_faction_Contract_unserialize(logic_faction_Contract* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_Contract_h__
