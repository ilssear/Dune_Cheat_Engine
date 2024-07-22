// gen time: 2024-07-21 07:31:36 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Interactions_h__
#define __gen_t_logic_faction_Interactions_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct EReason EReason;
typedef struct String String;
typedef struct ent_Player ent_Player;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_MapData hxbit_MapData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Interactions logic_faction_Interactions;


// type: logic.faction.Interactions, kind: HOBJ, pType: 0x02A76E337C98
struct logic_faction_Interactions {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.Interactions, begin_offset: 0x00B0
  void*                     pendingInteraction; // +00B0: HVIRTUAL
  double                    triggerValue;       // +00B8
  hxbit_ArrayProxyData*     interactionData;    // +00C0: HOBJ hxbit.ArrayProxyData
  hxbit_MapData*            interactionDataHistory; // +00C8: HOBJ hxbit.MapData
  int                       historyEntriesCount; // +00D0
  double                    lastInteractionTime; // +00D8
  hxbit_ArrayProxyData*     cooldowns;          // +00E0: HOBJ hxbit.ArrayProxyData
  void*                     onRefresh;          // +00E8: HFUN
  // total_size: 0x00F0
}; // logic_faction_Interactions (logic.faction.Interactions)

_Static_assert(sizeof(logic_faction_Interactions) == 0x00F0, "cls logic.faction.Interactions has wrong size");


extern void logic_faction_Interactions_finalize(logic_faction_Interactions* obj);
extern bool logic_faction_Interactions_canUpdate(logic_faction_Interactions* obj);
extern void logic_faction_Interactions_regularUpdate(logic_faction_Interactions* obj, double arg1);
extern void logic_faction_Interactions_dailyUpdate(logic_faction_Interactions* obj);
extern void logic_faction_Interactions_removePending(logic_faction_Interactions* obj, void* arg1);
extern bool logic_faction_Interactions_solveInteraction(logic_faction_Interactions* obj, void* arg1, void* arg2);
extern EReason* logic_faction_Interactions_tryInteraction(logic_faction_Interactions* obj, ent_Player* arg1);
extern void logic_faction_Interactions_interact(logic_faction_Interactions* obj, void* arg1);
extern void logic_faction_Interactions_refreshTriggerValue(logic_faction_Interactions* obj, void* arg1);
extern void logic_faction_Interactions_changeData(logic_faction_Interactions* obj, ent_Player* arg1, double arg2);
extern double logic_faction_Interactions_getTotalValues(logic_faction_Interactions* obj);
extern void* logic_faction_Interactions_getData(logic_faction_Interactions* obj, ent_Player* arg1);
extern void logic_faction_Interactions_recordNeeds(logic_faction_Interactions* obj);
extern void logic_faction_Interactions_increaseScore(logic_faction_Interactions* obj);
extern void* logic_faction_Interactions___net_mark_pendingInteraction(logic_faction_Interactions* obj, void* arg1);
extern void* logic_faction_Interactions_set_pendingInteraction(logic_faction_Interactions* obj, void* arg1);
extern int logic_faction_Interactions_get_networkPropPendingInteraction(logic_faction_Interactions* obj);
extern double logic_faction_Interactions___net_mark_triggerValue(logic_faction_Interactions* obj, double arg1);
extern double logic_faction_Interactions_set_triggerValue(logic_faction_Interactions* obj, double arg1);
extern int logic_faction_Interactions_get_networkPropTriggerValue(logic_faction_Interactions* obj);
extern hxbit_ArrayProxyData* logic_faction_Interactions___net_mark_interactionData(logic_faction_Interactions* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Interactions_set_interactionData(logic_faction_Interactions* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Interactions_get_networkPropInteractionData(logic_faction_Interactions* obj);
extern hxbit_MapData* logic_faction_Interactions___net_mark_interactionDataHistory(logic_faction_Interactions* obj, hxbit_MapData* arg1);
extern hxbit_MapData* logic_faction_Interactions_set_interactionDataHistory(logic_faction_Interactions* obj, hxbit_MapData* arg1);
extern int logic_faction_Interactions_get_networkPropInteractionDataHistory(logic_faction_Interactions* obj);
extern double logic_faction_Interactions___net_mark_lastInteractionTime(logic_faction_Interactions* obj, double arg1);
extern double logic_faction_Interactions_set_lastInteractionTime(logic_faction_Interactions* obj, double arg1);
extern int logic_faction_Interactions_get_networkPropLastInteractionTime(logic_faction_Interactions* obj);
extern hxbit_ArrayProxyData* logic_faction_Interactions___net_mark_cooldowns(logic_faction_Interactions* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Interactions_set_cooldowns(logic_faction_Interactions* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Interactions_get_networkPropCooldowns(logic_faction_Interactions* obj);
extern void logic_faction_Interactions_networkFlush(logic_faction_Interactions* obj, hxbit_Serializer* arg1);
extern void logic_faction_Interactions_networkSync(logic_faction_Interactions* obj, hxbit_Serializer* arg1);
extern void logic_faction_Interactions_networkInitProxys(logic_faction_Interactions* obj);
extern String* logic_faction_Interactions_networkGetName(logic_faction_Interactions* obj, int arg1, void* arg2);
extern int logic_faction_Interactions_getCLID(logic_faction_Interactions* obj);
extern void logic_faction_Interactions_serialize(logic_faction_Interactions* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_Interactions_getSerializeSchema(logic_faction_Interactions* obj);
extern void logic_faction_Interactions_unserializeInit(logic_faction_Interactions* obj);
extern void logic_faction_Interactions_unserialize(logic_faction_Interactions* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_Interactions_h__
