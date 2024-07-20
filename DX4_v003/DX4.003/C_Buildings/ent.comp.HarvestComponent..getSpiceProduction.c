/**
 * @file ent.comp.HarvestComponent..getSpiceProduction.c
 * @brief Module to increase Harvester Production for player factions in the game.
 *        AI factions have no change.
 */

#include <common.h>
#include <gen/t.ent.comp.HarvestComponent.h>
#include <gen/t.ent.comp.EntityComponent.h>
#include <helper_functions.h>

/**
 * @brief Original function to get harvester spice production.
 *
 * This function is provided by the original game code and is overridden
 * by ent_comp_HarvestComponent_getSpiceProduction_new.
 *
 * @param obj Pointer to the harvester component object.
 * @return The spice production value of the harvester.
 */
extern
double ent_comp_HarvestComponent_getSpiceProduction(ent_comp_HarvestComponent* obj);

/**
 * @brief New function to get harvester spice production with custom logic.
 *
 * This function increases harvester production for player factions.
 * AI factions are not affected.
 *
 * @param obj Pointer to the harvester component object.
 * @return The modified spice production value of the harvester.
 */
double ent_comp_HarvestComponent_getSpiceProduction_new(ent_comp_HarvestComponent* obj) {
  ent_Faction* faction = ent_comp_EntityComponent_get_owner(&obj->super);
  
  double multiplier = 1.0;

  // Use isPlayer function to check if the faction is controlled by a player
  if (isPlayer(faction)) {
    multiplier = 100.0;
  }

  return multiplier * ent_comp_HarvestComponent_getSpiceProduction(obj);
}
