// gen time: 2024-07-21 07:22:25 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_Airfield_h__
#define __gen_t_logic_faction_Airfield_h__

#include <common.h>
#include <gen/t.logic.faction.FactionManager.h>

typedef struct ent_Ornithopter ent_Ornithopter;
typedef struct hl_types_ArrayObj hl_types_ArrayObj;
typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_Airfield logic_faction_Airfield;


// type: logic.faction.Airfield, kind: HOBJ, pType: 0x02A76E33E4B8
struct logic_faction_Airfield {
  // super: logic.faction.FactionManager
  logic_faction_FactionManager super;

  // cls: logic.faction.Airfield, begin_offset: 0x00B0
  // total_size: 0x00B0
}; // logic_faction_Airfield (logic.faction.Airfield)

_Static_assert(sizeof(logic_faction_Airfield) == 0x00B0, "cls logic.faction.Airfield has wrong size");


extern hl_types_ArrayObj* logic_faction_Airfield_getAvailableOrnithopters(logic_faction_Airfield* obj);
extern ent_Ornithopter* logic_faction_Airfield_getBestAvailableOrnithopter(logic_faction_Airfield* obj);
extern void logic_faction_Airfield_networkFlush(logic_faction_Airfield* obj, hxbit_Serializer* arg1);
extern void logic_faction_Airfield_networkSync(logic_faction_Airfield* obj, hxbit_Serializer* arg1);
extern int logic_faction_Airfield_getCLID(logic_faction_Airfield* obj);


#endif // __gen_t_logic_faction_Airfield_h__
