/**
 * @file ent.Structure..addReconProgress.c
 * @brief Module for adding recon progress to structures in the game.
 *        For player factions, it significantly increases the recon progress rate.
 */

#include <common.h>
#include <gen/t.ent.Structure.h>
#include <helper_functions.h>

/**
 * @brief Original function to add recon progress to a structure.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Structure_addReconProgress_new.
 *
 * @param obj Pointer to the structure object.
 * @param fac Pointer to the faction object.
 * @param delta The time delta for the recon progress update.
 * @return true if the recon progress was successfully added, false otherwise.
 */
extern
bool ent_Structure_addReconProgress_org(ent_Structure* obj, ent_Faction* fac, double delta);

/**
 * @brief New function to add recon progress to a structure with custom logic.
 *
 * This function checks if the faction belongs to a player and significantly increases
 * the recon progress rate if true. Otherwise, it uses the original rate.
 *
 * @param obj Pointer to the structure object.
 * @param fac Pointer to the faction object.
 * @param delta The time delta for the recon progress update.
 * @return true if the recon progress was successfully added, false otherwise.
 */
bool ent_Structure_addReconProgress_new(ent_Structure* obj, ent_Faction* fac, double delta) {

  double multiplier = 1.0;
  if (isPlayer(fac)) {
    multiplier = 100.0;
  }

  return ent_Structure_addReconProgress_org(obj, fac, multiplier * delta);
}
