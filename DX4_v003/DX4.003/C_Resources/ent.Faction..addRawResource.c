/**
 * @file ent.Faction..addRawResource.c
 * @brief Module for modifying raw resource addition to factions in the game.
 *        For player factions, it significantly increases the resources added.
 */

#include <common.h>
#include <gen/t.ent.Faction.h>
#include <helper_functions.h>

/**
 * @brief Structure to hold resource modification data.
 */
typedef struct {
  double multiplier;
  double addition;
} ResourceModificationData;

/**
 * @brief Externally used data for resource modification.
 */
ResourceModificationData ent_Faction_resource_mod_data = { 10.0, 10.0 };
#define resourceData ent_Faction_resource_mod_data

/**
 * @brief Original function to add raw resources to a faction.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Faction_addRawResource_new.
 *
 * @param fac Pointer to the faction object.
 * @param idStr Pointer to the resource identifier string.
 * @param delta The amount of resource to add.
 * @param arg3 Additional arguments.
 * @param arg4 Additional arguments.
 * @return The resulting amount of resources added.
 */
extern
double ent_Faction_addRawResource_org(ent_Faction* fac, String* idStr, double delta, void* arg3, void* arg4);

/**
 * @brief New function to add raw resources to a faction with custom logic.
 *
 * This function modifies the resource addition based on whether the faction is controlled
 * by a player or AI. Player factions receive a significant boost.
 *
 * @param fac Pointer to the faction object.
 * @param idStr Pointer to the resource identifier string.
 * @param delta The amount of resource to add.
 * @param arg3 Additional arguments.
 * @param arg4 Additional arguments.
 * @return The resulting amount of resources added.
 */
double ent_Faction_addRawResource_new(ent_Faction* fac, String* idStr, double delta, void* arg3, void* arg4) {

  double multiplier = 1.0, addition = 0.0;
  if (isPlayer(fac)) {
    if (delta > 0.0) {
      multiplier = resourceData.multiplier;
      addition = resourceData.addition;
    } else if (delta < 0.0) {
      multiplier = 0;
      addition = resourceData.addition;
    }
  }

  return ent_Faction_addRawResource_org(fac, idStr, multiplier * delta + addition, arg3, arg4);
}
