/**
 * @file ent.Faction..getCachedResNetProd.c
 * @brief Module for modifying cached resource net production for factions in the game.
 *        Player factions receive significant boosts for certain resources.
 */

#include <common.h>
#include <gen/t.ent.Faction.h>
#include <helper_functions.h>

/**
 * @brief Structure to hold resource modification data.
 */
typedef struct {
  double plus[320];
} ResourcePlusData;

/**
 * @brief Externally used data for resource modification.
 */
ResourcePlusData ent_Faction_getCachedResNetProd_data = {
  {
    0,       // [000] - 0x00 - Stockpile spice (does nothing?)
    10000,   // [001] - 0x08 - Solari
    1000,    // [002] - 0x10 - Plascrete
    10000,   // [003] - 0x18 - Manpower
    1000,    // [004] - 0x20 - Fuel Cell
    1000,    // [005] - 0x28 - Water
    10000,   // [006] - 0x30 - Authority
    0,       // [007] - 0x38 - Hegemony
    1000,    // [008] - 0x40 - Landsraad Standing
    100000,  // [009] - 0x48 - Knowledge
    10000,   // [010] - 0x50 - Influence
    0,       // [011] - 0x58 - Unknown
    10000,   // [012] - 0x60 - Votes
    200,     // [013] - 0x68 - Command Points (limits military size)
    13,      // [014] - 0x70 - Military slots (max trainable troops)
    0,       // [015] - 0x78 - Unknown
    0, 0,    // [016]..[017] - 0x80..0x88 - Unknown
    0,       // [018] - 0x90 - Spaceship Parts (Fremen only) 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // [019]..[031] - 0x98..0xF8 - Unknown
    0, 0, 0, 0, 0, 0, 0, 0, // [032]..[039] - 0x100..0x138 - Unknown
    208,    // [040] - 0x140
    555,    // [041] - 0x148 - Intel
    210     // [042] - 0x150
  }
};

#define resourcePlusData ent_Faction_getCachedResNetProd_data

/**
 * @brief Original function to get cached resource net production.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Faction_getCachedResNetProd_new.
 *
 * @param fac Pointer to the faction object.
 * @param id Resource identifier.
 * @return The cached net production value for the specified resource.
 */
extern
double ent_Faction_getCachedResNetProd_org(ent_Faction* fac, int id);

/**
 * @brief New function to get cached resource net production with custom logic.
 *
 * This function modifies the net production value based on whether the faction
 * is controlled by a player or AI. Player factions receive significant boosts.
 *
 * @param fac Pointer to the faction object.
 * @param id Resource identifier.
 * @return The modified cached net production value for the specified resource.
 */
double ent_Faction_getCachedResNetProd_new(ent_Faction* fac, int id) {
  double result = ent_Faction_getCachedResNetProd_org(fac, id);

  if (isPlayer(fac)) {
    if (id < sizeof(resourcePlusData.plus) / sizeof(resourcePlusData.plus[0])) {
      result += (double)resourcePlusData.plus[id];
    }
  }

  return result;
}

/**
 * @brief Original function to get cached resource production.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Faction_getCachedResProd_new.
 *
 * @param fac Pointer to the faction object.
 * @param id Resource identifier.
 * @return The cached production value for the specified resource.
 */
extern
double ent_Faction_getCachedResProd_org(ent_Faction* fac, int id);

/**
 * @brief New function to get cached resource production with custom logic.
 *
 * This function modifies the production value based on whether the faction
 * is controlled by a player or AI. Player factions receive significant boosts.
 *
 * @param fac Pointer to the faction object.
 * @param id Resource identifier.
 * @return The modified cached production value for the specified resource.
 */
double ent_Faction_getCachedResProd_new(ent_Faction* fac, int id) {
  double result = ent_Faction_getCachedResNetProd_org(fac, id);

  if (isPlayer(fac)) {
    if (id < sizeof(resourcePlusData.plus) / sizeof(resourcePlusData.plus[0])) {
      result += (double)resourcePlusData.plus[id];
    }
  }

  return result;
}
