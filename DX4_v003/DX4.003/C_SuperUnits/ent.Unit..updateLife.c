

#include <common.h>
#include <gen/t.ent.Unit.h>

// Other functions to use:
// extern double ent_Unit_getBaseMaxLife(ent_Unit* obj);
// extern double ent_Unit_getMaxLifeAdditiveModifier(ent_Unit* obj);

bool isPlayer(ent_Faction* faction) {
  return faction && !faction->isAI;
}

extern
void ent_Unit_updateLife_org(ent_Unit* obj, double arg1);

void ent_Unit_updateLife_new(ent_Unit* obj, double arg1) {
  ent_Faction* fac = ent_Entity_get_owner(obj); // get unit faction

  if (isPlayer(fac)) {
    arg1 = ent_Unit_getBaseMaxLife(obj);
  }

  ent_Unit_updateLife_org(obj, arg1);
}
