#include <common.h>
#include <gen/t.ent.Entity.h>

typedef struct {
  double _player_attacker_damage_factor;
  double _player_defender_damage_factor;
  double _ai_to_village_damage_factor;
  double _village_to_ai_damage_factor;
} data_t;

data_t ent_Entity_hurtBy_data = { 100.0, 0.01, 0.2, 2.0 };
#define data ent_Entity_hurtBy_data

extern
void ent_Entity_hurtBy_org(ent_Entity* d, ent_Entity* a, double v, bool* fb);

bool isPlayer(ent_Faction* faction) {
  return faction && !faction->isAI;
}

bool isAI(ent_Faction* faction) {
  return faction && faction->isAI;
}

bool isVillage(ent_Faction* faction) {
  return !faction;
}

void ent_Entity_hurtBy_new(ent_Entity* d, ent_Entity* a, double v, bool* fb) {

  ent_Faction* defender_faction = ent_Entity_get_owner(d);
  ent_Faction* attacker_faction = ent_Entity_get_owner(a);

  double m = 1.0;

  if (isPlayer(defender_faction)) {
    m = data._player_defender_damage_factor;
  } else if (isPlayer(attacker_faction)) {
    m = data._player_attacker_damage_factor;
  } else if (isVillage(defender_faction) && isAI(attacker_faction)) {
    m = data._ai_to_village_damage_factor;
  } else if (isAI(defender_faction) && isVillage(attacker_faction)) {
    m = data._village_to_ai_damage_factor;
  }

  ent_Entity_hurtBy_org(d, a, m * v, fb);
}
