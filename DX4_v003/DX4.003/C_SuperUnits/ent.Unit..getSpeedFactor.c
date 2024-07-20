
/**
 * @file ent.Unit..getSpeedFactor.c
 * @brief Module for calculating the speed factor of units in the game.
 *        Adjusts speed based on whether the unit belongs to a player or AI.
 */

#include <common.h>
#include <gen/t.ent.Unit.h>
#include <helper_functions.h>

/**
 * @brief Structure to hold speed factor data.
 */
typedef struct {
  double _player_units_speed_factor;        // 0x00
  double _player_ornithopter_speed_factor;  // 0x08
  double _player_harvester_speed_factor;    // 0x10
} data_speed;

/**
 * @brief Externally used data for speed factors.
 */
data_speed ent_Entity_speedup_data = { 10.0, 5.0, 1.0 };
#define data ent_Entity_speedup_data

/**
 * @brief Original function to get the speed factor of a unit.
 *
 * This function is provided by the original game code and is overridden
 * by ent_Unit_getSpeedFactor_new.
 *
 * @param obj Pointer to the unit object.
 * @return The original speed factor of the unit.
 */
extern
double ent_Unit_getSpeedFactor_org(ent_Unit* obj);

/**
 * @brief New function to get the speed factor of a unit with custom logic.
 *
 * This function adjusts the speed factor based on whether the unit belongs to
 * a player or AI. Player units get a speed multiplier.
 *
 * @param obj Pointer to the unit object.
 * @return The adjusted speed factor of the unit.
 */
double ent_Unit_getSpeedFactor_new(ent_Unit* obj) {
  ent_Faction* unit_faction = ent_Entity_get_owner(obj);
  bool isPlayerFaction = isPlayer(unit_faction);

  double baseSpeedFactor = ent_Unit_getSpeedFactor_org(obj);
  double speedMultiplier = 1.0; // Default multiplier for AI and other units (e.g., villagers)

  if (isPlayerFaction) {
    bool isOrnithopter = ent_Unit_isOrni(obj);    // Unit is an Ornithopter
    bool isHarvester = ent_Unit_isHarvester(obj); // Unit is a Harvester

    if (isOrnithopter) {
      speedMultiplier = data._player_ornithopter_speed_factor;
    } else if (isHarvester) {
      speedMultiplier = data._player_harvester_speed_factor;
    } else {
      speedMultiplier = data._player_units_speed_factor;
    }
  }

  return speedMultiplier * baseSpeedFactor;
}
