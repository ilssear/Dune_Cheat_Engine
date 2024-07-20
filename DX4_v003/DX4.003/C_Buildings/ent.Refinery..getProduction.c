
/**
 * @file  ent.Refinery..getProduction.c
 * @brief Module to increase Refinery Production for player factions in the game.
 *        AI factions have no change.
 */

#include <common.h>
#include <gen/t.ent.Refinery.h>
#include <helper_functions.h>

/**
 * @brief Original function to get refinery production.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Refinery_getProduction_new.
 *
 * @param obj Pointer to the refinery object.
 * @return The production value of the refinery.
 */
extern
double ent_Refinery_getProduction(ent_Refinery* obj);

/**
 * @brief New function to get refinery production with custom logic.
 *
 * This function increases refinery production for player factions.
 * AI factions are not affected.
 *
 * @param obj Pointer to the refinery object.
 * @return The modified production value of the refinery.
 */
double ent_Refinery_getProduction_new(ent_Refinery* obj) {
  ent_Faction* faction = ent_Refinery_get_factionOwner(obj);
  
  double multiplier = 1.0;

  // Use isPlayer function to check if the faction is controlled by a player
  if (isPlayer(faction)) {
    multiplier = 100.0;
  }

  return multiplier * ent_Refinery_getProduction(obj);
}
