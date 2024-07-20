
/**
 * @file  logic.Upgrades..regularUpdate.c
 * @brief Module for speeding up building construction for player factions in the game.
 *        AI factions have no speed change.
 */
// 2022-06-27 method update renamed to regularUpdate (in game v0.2.4.16135)

#include <common.h>
#include <gen/t.logic.Upgrades.h>
#include <helper_functions.h>

/**
 * @brief Original function to update upgrades regularly.
 *
 * This function is provided by the original game code and is overridden
 * by logic_Upgrades_regularUpdate_new.
 *
 * @param obj Pointer to the upgrades object.
 * @param delta The time delta for the update.
 */
extern
void logic_Upgrades_regularUpdate_org(logic_Upgrades* obj, double delta);

/**
 * @brief New function to update upgrades regularly with custom logic.
 *
 * This function speeds up the building construction for player factions.
 * AI factions are not affected.
 *
 * @param obj Pointer to the upgrades object.
 * @param delta The time delta for the update.
 */
void logic_Upgrades_regularUpdate_new(logic_Upgrades* obj, double delta) {
  ent_Faction* faction = logic_Upgrades_get_factionOwner(obj);

  // Use isPlayer function to check if the faction is controlled by a player
  if (isPlayer(faction)) {
    delta *= 100.0;
  }

  logic_Upgrades_regularUpdate_org(obj, delta);
}
