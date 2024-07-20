/**
 * @file super_units.c
 * @brief Super module for various unit functionalities in the game.
 *        Includes updating unit life, handling entity damage, checking worm target eligibility,
 *        and calculating speed factors.
 */

#include <common.h>
#include <gen/t.ent.Unit.h>
#include <gen/t.ent.Entity.h>
#include <helper_functions.h>

/** 
 * ent_unit_life_update.c content 
 */

/**
 * @brief Module for updating a unit's life in the game.
 *        For players, it updates the life to its maximum value immediately.
 */

/**
 * @brief Original function to update the life of a unit.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Unit_updateLife_new.
 *
 * @param obj Pointer to the unit object.
 * @param arg1 The life value to be updated.
 */
extern
void ent_Unit_updateLife_org(ent_Unit* obj, double arg1);

/**
 * @brief New function to update the life of a unit with custom logic.
 *
 * This function checks if the unit belongs to a player and sets the life value
 * to the base max life if true. Otherwise, it uses the provided life value.
 *
 * @param obj Pointer to the unit object.
 * @param arg1 The life value to be updated.
 */
void ent_Unit_updateLife_new(ent_Unit* obj, double arg1) {
  ent_Faction* unit_faction = ent_Entity_get_owner(obj); // get unit faction

  if (isPlayer(unit_faction)) {
    arg1 = ent_Unit_getBaseMaxLife(obj);
  }

  ent_Unit_updateLife_org(obj, arg1);
}

/** 
 * ent_entity_hurt_by.c content 
 */

/**
 * @brief Module for handling damage between entities in the game.
 *        It adjusts the damage based on the types of the attacker and defender.
 */

/**
 * @brief Structure to hold damage factor data.
 */
typedef struct {
  double player_attacker_damage_factor;
  double player_defender_damage_factor;
  double ai_to_village_damage_factor;
  double village_to_ai_damage_factor;
} DamageFactorData;

/**
 * @brief Externally used data for damage factors.
 */
DamageFactorData ent_Entity_hurtBy_data = { 100.0, 0.01, 0.2, 2.0 };
#define damageData ent_Entity_hurtBy_data

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

  double multiplier = 1.0;

  if (isPlayer(defender_faction)) {
    multiplier = damageData.player_defender_damage_factor;
  } else if (isPlayer(attacker_faction)) {
    multiplier = damageData.player_attacker_damage_factor;
  } else if (isVillage(defender_faction) && isAI(attacker_faction)) {
    multiplier = damageData.ai_to_village_damage_factor;
  } else if (isAI(defender_faction) && isVillage(attacker_faction)) {
    multiplier = damageData.village_to_ai_damage_factor;
  }

  ent_Entity_hurtBy_org(d, a, multiplier * v, fb);
}

/** 
 * ent_unit_can_be_worm_target.c content 
 */

/**
 * @brief Module for determining if a unit can be a sandworm target in the game.
 *        It changes the normal behavior by shielding the player from sandworm attacks.
 */

/**
 * @brief Original function to check if a unit can be a worm target.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Unit_canBeWormTarget_new.
 *
 * @param obj Pointer to the unit object.
 * @param arg1 Additional arguments (usage depends on the game logic).
 * @return true if the unit can be a worm target, false otherwise.
 */
extern
bool ent_Unit_canBeWormTarget_org(ent_Unit* obj, void* arg1);

/**
 * @brief New function to check if a unit can be a worm target with custom logic.
 *
 * This function checks if the unit belongs to a player and returns false if true.
 * Otherwise, it calls the original function to determine if the unit can be a worm target.
 *
 * @param obj Pointer to the unit object.
 * @param arg1 Additional arguments (usage depends on the game logic).
 * @return false if the unit belongs to a player, otherwise calls the original function.
 */
bool ent_Unit_canBeWormTarget_new(ent_Unit* obj, void* arg1) {
  ent_Faction* unit_faction = ent_Entity_get_owner(obj);

  if (isPlayer(unit_faction)) {
    return false;
  } else {
    return ent_Unit_canBeWormTarget_org(obj, arg1);
  }
}

/** 
 * ent_unit_get_speed_factor.c content 
 */

/**
 * @brief Module for calculating the speed factor of units in the game.
 *        Adjusts speed based on whether the unit belongs to a player or AI.
 */

/**
 * @brief Structure to hold speed factor data.
 */
typedef struct {
  double player_units_speed_factor;
  double player_ornithopter_speed_factor;
  double player_harvester_speed_factor;
} SpeedFactorData;

/**
 * @brief Externally used data for speed factors.
 */
SpeedFactorData ent_Entity_speedup_data = { 10.0, 5.0, 1.0 };
#define speedData ent_Entity_speedup_data

/**
 * @brief Original function to get the speed factor of a unit.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Unit_getSpeedFactor_new.
 *
 * @param obj Pointer to the unit object.
 * @return The original speed factor of the unit.
 */
extern
double ent_Unit_getSpeedFactor_org(ent_Unit* obj);

/**
 * @brief New function to get the speed factor of a unit with custom logic.
 *
 * This function adjusts the speed factor based on whether the unit belongs to
 * a player or AI. Player units get a speed multiplier.
 *
 * @param obj Pointer to the unit object.
 * @return The adjusted speed factor of the unit.
 */
double ent_Unit_getSpeedFactor_new(ent_Unit* obj) {
  ent_Faction* unit_faction = ent_Entity_get_owner(obj);
  bool isPlayerFaction = isPlayer(unit_faction);

  double baseSpeedFactor = ent_Unit_getSpeedFactor_org(obj);
  double speedMultiplier = 1.0; // Default multiplier for AI and other units (e.g., villagers)

  if (isPlayerFaction) {
    bool isOrnithopter = ent_Unit_isOrni(obj);    // Unit is an Ornithopter
    bool isHarvester = ent_Unit_isHarvester(obj); // Unit is a Harvester

    if (isOrnithopter) {
      speedMultiplier = speedData.player_ornithopter_speed_factor;
    } else if (isHarvester) {
      speedMultiplier = speedData.player_harvester_speed_factor;
    } else {
      speedMultiplier = speedData.player_units_speed_factor;
    }
  }

  return speedMultiplier * baseSpeedFactor;
}
