// gen time: 2024-07-21 07:23:49 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Objectives_h__
#define __gen_t_logic_faction_Objectives_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct String String;
typedef struct hxbit_ArrayProxyData hxbit_ArrayProxyData;
typedef struct hxbit_Schema hxbit_Schema;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct lib_Event lib_Event;
typedef struct logic_faction_Objective logic_faction_Objective;
typedef struct logic_faction_Objectives logic_faction_Objectives;
typedef struct ui_comp_BaseElement ui_comp_BaseElement;


// type: logic.faction.Objectives, kind: HOBJ, pType: 0x02A76E335DF8
struct logic_faction_Objectives {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.Objectives, begin_offset: 0x00B0
  hxbit_ArrayProxyData*     activeObjectives;   // +00B0: HOBJ hxbit.ArrayProxyData
  hxbit_ArrayProxyData*     completedObjectives; // +00B8: HOBJ hxbit.ArrayProxyData
  // total_size: 0x00C0
}; // logic_faction_Objectives (logic.faction.Objectives)

_Static_assert(sizeof(logic_faction_Objectives) == 0x00C0, "cls logic.faction.Objectives has wrong size");


extern void logic_faction_Objectives_init(logic_faction_Objectives* obj);
extern void logic_faction_Objectives_onEvent(logic_faction_Objectives* obj, lib_Event* arg1);
extern logic_faction_Objective* logic_faction_Objectives_startObjective(logic_faction_Objectives* obj, String* arg1, ui_comp_BaseElement* arg2);
extern void logic_faction_Objectives_sortObjectives(logic_faction_Objectives* obj);
extern void logic_faction_Objectives_clear(logic_faction_Objectives* obj);
extern void logic_faction_Objectives_regularUpdate(logic_faction_Objectives* obj, double arg1);
extern hxbit_ArrayProxyData* logic_faction_Objectives___net_mark_activeObjectives(logic_faction_Objectives* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Objectives_set_activeObjectives(logic_faction_Objectives* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Objectives_get_networkPropActiveObjectives(logic_faction_Objectives* obj);
extern hxbit_ArrayProxyData* logic_faction_Objectives___net_mark_completedObjectives(logic_faction_Objectives* obj, hxbit_ArrayProxyData* arg1);
extern hxbit_ArrayProxyData* logic_faction_Objectives_set_completedObjectives(logic_faction_Objectives* obj, hxbit_ArrayProxyData* arg1);
extern int logic_faction_Objectives_get_networkPropCompletedObjectives(logic_faction_Objectives* obj);
extern void logic_faction_Objectives_networkFlush(logic_faction_Objectives* obj, hxbit_Serializer* arg1);
extern void logic_faction_Objectives_networkSync(logic_faction_Objectives* obj, hxbit_Serializer* arg1);
extern void logic_faction_Objectives_networkInitProxys(logic_faction_Objectives* obj);
extern String* logic_faction_Objectives_networkGetName(logic_faction_Objectives* obj, int arg1, void* arg2);
extern int logic_faction_Objectives_getCLID(logic_faction_Objectives* obj);
extern void logic_faction_Objectives_serialize(logic_faction_Objectives* obj, hxbit_Serializer* arg1);
extern hxbit_Schema* logic_faction_Objectives_getSerializeSchema(logic_faction_Objectives* obj);
extern void logic_faction_Objectives_unserialize(logic_faction_Objectives* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_Objectives_h__
