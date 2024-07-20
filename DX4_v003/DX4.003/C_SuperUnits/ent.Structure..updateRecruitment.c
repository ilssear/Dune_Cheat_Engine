/**
 * @file ent.Structure..updateRecruitment.c
 * @brief Module for updating the recruitment rate of structures in the game.
 *        For player structures, it significantly increases the recruitment rate.
 */

#include <common.h>
#include <gen/t.ent.Structure.h>
#include <helper_functions.h>

/**
 * @brief Original function to update the recruitment rate of a structure.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Structure_updateRecruitment_new.
 *
 * @param obj Pointer to the structure object.
 * @param delta The time delta for the recruitment update.
 */
extern
void ent_Structure_updateRecruitment_org(ent_Structure* obj, double delta);

/**
 * @brief New function to update the recruitment rate of a structure with custom logic.
 *
 * This function checks if the structure belongs to a player and significantly increases
 * the recruitment rate if true. Otherwise, it uses the original rate.
 *
 * @param structure Pointer to the structure object.
 * @param delta The time delta for the recruitment update.
 */
void ent_Structure_updateRecruitment_new(ent_Structure* structure, double delta) {
  ent_Faction* structure_faction = ent_Entity_get_owner(structure);

  double multiplier = 1.0;
  if (isPlayer(structure_faction)) {
    multiplier = 100.0;
  }

  ent_Structure_updateRecruitment_org(structure, multiplier * delta);
}
