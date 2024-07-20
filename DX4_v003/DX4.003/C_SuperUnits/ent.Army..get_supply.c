/**
 * @file ent.Army..get_supply.c
 * @brief Module to modify the supply value for player factions in the game.
 *        AI factions have no change.
 */

#include <common.h>
#include <gen/t.ent.Army.h>
#include <helper_functions.h>

/**
 * @brief Original function to get the supply value of an army.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Army_get_supply_new.
 *
 * @param obj Pointer to the army object.
 * @return The supply value of the army.
 */
extern double ent_Army_get_supply_org(ent_Army* obj);

/**
 * @brief Helper function to safely update the supply.
 *
 * This function safely updates the supply of an army object.
 *
 * @param obj Pointer to the army object.
 * @param arg1 The supply value to update.
 */
void safe_update_supply(ent_Army* obj, double arg1) {
    // Disabled to prevent crashing the game
    // if (ent_Army_updateSupply) {
    //     ent_Army_updateSupply(obj, arg1);
    // }
}

/**
 * @brief Helper function to safely get the maximum supply.
 *
 * This function safely gets the maximum supply value of an army object.
 *
 * @param obj Pointer to the army object.
 * @param arg1 The current supply value.
 * @return The maximum supply value of the army object.
 */
double safe_get_max_supply(ent_Army* obj, double arg1) {
    double max_supply = arg1 + 1000.0;
    // Disabled to prevent crashing the game
    if (ent_Army_get_maxSupply) {
        max_supply = ent_Army_get_maxSupply(obj);
        safe_update_supply(obj, max_supply);
    }
    return max_supply;
}

/**
 * @brief New function to get the supply value of an army with custom logic.
 *
 * This function modifies the supply value based on whether the faction
 * is controlled by a player or AI. Player factions receive significant boosts.
 *
 * @param obj Pointer to the army object.
 * @return The modified supply value of the army.
 */
double ent_Army_get_supply_new(ent_Army* obj) {
    ent_Faction* army_faction = ent_Entity_get_owner(obj);

    double supply = ent_Army_get_supply_org(obj);

    if (isPlayer(army_faction)) {
        supply = safe_get_max_supply(obj, supply);
    }

    return supply;
}
