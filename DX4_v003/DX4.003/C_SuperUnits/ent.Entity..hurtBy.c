
/**
 * @file ent.Entity..hurtBy.c
 * @brief Module for handling damage between entities in the game.
 *        It adjusts the damage based on the types of the attacker and defender.
 */

#include <common.h>
#include <gen/t.ent.Entity.h>
#include <helper_functions.h>

/**
 * @brief Structure to hold damage factor data.
 */
typedef struct {
  double _player_attacker_damage_factor;  // 0x00
  double _player_defender_damage_factor;  // 0x08
  double _ai_to_village_damage_factor;    // 0x10
  double _village_to_ai_damage_factor;    // 0x18
} data_damage;

/**
 * @brief Externally used data for damage factors.
 */
data_damage ent_Entity_hurtBy_data = { 100.0, 0.01, 1.0, 1.0 };
#define data ent_Entity_hurtBy_data

/**
 * @brief Original function to handle entity damage.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Entity_hurtBy_new.
 *
 * @param d Pointer to the defender entity.
 * @param a Pointer to the attacker entity.
 * @param v Damage value to be applied.
 * @param fb Additional flag or feedback (usage depends on the game logic).
 */
extern
void ent_Entity_hurtBy_org(ent_Entity* d, ent_Entity* a, double v, bool* fb);

/**
 * @brief New function to handle entity damage with custom logic.
 *
 * This function adjusts the damage based on the types of the attacker and defender.
 *
 * @param d Pointer to the defender entity.
 * @param a Pointer to the attacker entity.
 * @param v Damage value to be applied.
 * @param fb Additional flag or feedback (usage depends on the game logic).
 */
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
