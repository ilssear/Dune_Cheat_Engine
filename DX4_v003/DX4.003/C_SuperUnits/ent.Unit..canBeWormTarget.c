
#include <common.h>
#include <gen/t.ent.Unit.h>

extern
bool ent_Unit_canBeWormTarget_org(ent_Unit* obj, void* arg1);
bool ent_Unit_canBeWormTarget_new(ent_Unit* obj, void* arg1) {
  ent_Faction* unit_faction = ent_Entity_get_owner(obj);
  bool isPlayer = unit_faction && !(unit_faction->isAI);
  
  if (isPlayer) {
	  return false;
  } 
  else
    return ent_Unit_canBeWormTarget_org(obj, arg1);
}

