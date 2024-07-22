// gen time: 2024-07-21 07:23:50 UTC, pid: 0x00005670 (22128)

#ifndef __gen_t_logic_faction_SupplyLines_h__
#define __gen_t_logic_faction_SupplyLines_h__

#include <common.h>
#include <gen/t.logic.Logic.h>

typedef struct hxbit_Serializer hxbit_Serializer;
typedef struct logic_faction_SupplyLines logic_faction_SupplyLines;


// type: logic.faction.SupplyLines, kind: HOBJ, pType: 0x02A76E392478
struct logic_faction_SupplyLines {
  // super: logic.Logic
  logic_Logic               super;

  // cls: logic.faction.SupplyLines, begin_offset: 0x0090
  // total_size: 0x0090
}; // logic_faction_SupplyLines (logic.faction.SupplyLines)

_Static_assert(sizeof(logic_faction_SupplyLines) == 0x0090, "cls logic.faction.SupplyLines has wrong size");


extern int logic_faction_SupplyLines_getCLID(logic_faction_SupplyLines* obj);
extern void logic_faction_SupplyLines_networkFlush(logic_faction_SupplyLines* obj, hxbit_Serializer* arg1);
extern void logic_faction_SupplyLines_networkSync(logic_faction_SupplyLines* obj, hxbit_Serializer* arg1);


#endif // __gen_t_logic_faction_SupplyLines_h__
