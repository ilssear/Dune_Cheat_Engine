/**
 * @file ent.Unit..canBeWormTarget.c
 * @brief Module for determining if a unit can be a sandworm target in the game.
 *        It changes the normal behavior by shielding the player from sandworm attacks.
 */

#include <common.h>
#include <gen/t.ent.Unit.h>
#include <helper_functions.h>

/**
 * @brief Original function to check if a unit can be a sandworm target.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Unit_canBeWormTarget_new.
 *
 * @param obj Pointer to the unit object.
 * @param arg1 Additional arguments (usage depends on the game logic).
 * @return true if the unit can be a sandworm target, false otherwise.
 */
extern
bool ent_Unit_canBeWormTarget_org(ent_Unit* obj, void* arg1);

/**
 * @brief New function to check if a unit can be a sandworm target with custom logic.
 *
 * This function checks if the unit belongs to a player and returns false if true.
 * Otherwise, it calls the original function to determine if the unit can be a sandworm target.
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
