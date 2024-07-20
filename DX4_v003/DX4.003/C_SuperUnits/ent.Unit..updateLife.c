/**
 * @file ent.Unit..updateLife.c
 * @brief Module for updating a unit's life in the game.
 *        For players, it updates the life to its maximum value immediately.
 */

#include <common.h>
#include <gen/t.ent.Unit.h>
#include <helper_functions.h>

// Other functions to use:
// extern double ent_Unit_getBaseMaxLife(ent_Unit* unit);
// extern double ent_Unit_getMaxLifeAdditiveModifier(ent_Unit* unit);

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
 * @param unit Pointer to the unit object.
 * @param lifeValue The life value to be updated.
 */
void ent_Unit_updateLife_new(ent_Unit* obj, double arg1) {
  
  ent_Faction* unit_faction = ent_Entity_get_owner(obj); // get unit faction

  if (isPlayer(unit_faction)) {
    arg1 = ent_Unit_getBaseMaxLife(obj);
  }

  ent_Unit_updateLife_org(obj, arg1);
}
