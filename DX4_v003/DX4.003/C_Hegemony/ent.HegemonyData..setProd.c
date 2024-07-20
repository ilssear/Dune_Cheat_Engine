/**
 * @file  ent.HegemonyData..setProd.c
 * @brief Module for modifying production values in the game.
 *        Player factions receive significant boosts for certain production types.
 */

#include <common.h>
#include <gen/t.ent.HegemonyData.h>
#include <gen/t.String.h>
#include <helper_functions.h>

/**
 * @brief Structure to hold production modification data.
 */
typedef struct {
  double multiplier;  // 0x00
  double addition;    // 0x08
} ProductionModificationData;

/**
 * @brief Externally used data for production modification.
 */
ProductionModificationData ent_HegemonyData_setProd_data = { 1.0, 1000.0 };
#define prodModData ent_HegemonyData_setProd_data

/**
 * @brief Original function to set production values.
 *
 * This function is provided by the original game code and is overridden
 * by ent_HegemonyData_setProd_new.
 *
 * @param obj Pointer to the HegemonyData object.
 * @param idStr Pointer to the identifier string.
 * @param v The production value.
 * @param arg3 Additional arguments.
 */
extern
void ent_HegemonyData_setProd_org(ent_HegemonyData* obj, String* idStr, double v, int* arg3);

/**
 * @brief New function to set production values with custom logic.
 *
 * This function modifies the production values based on whether the faction
 * is controlled by a player or AI. Player factions receive significant boosts
 * for certain production types.
 *
 * @param obj Pointer to the HegemonyData object.
 * @param idStr Pointer to the identifier string.
 * @param v The production value.
 * @param arg3 Additional arguments.
 */
void ent_HegemonyData_setProd_new(ent_HegemonyData* obj, String* idStr, double v, int* arg3) {
  ent_Faction* faction = obj ? obj->faction : 0;

  if (isPlayer(faction)) {
    // We don't want to add the same value multiple times, so check the idStr first
    int idLength = idStr ? idStr->length : 0;
    qword* idQW = idStr ? (qword*)idStr->bytes : 0;

    // One common idStr value is "Developments", so check the length and first 4 bytes if they match
    bool isDevelopments = (idLength == 12) && (idQW ? (*idQW == 0x0065007600650044) : false);

    if (isDevelopments) {
      v *= prodModData.multiplier;
      v += prodModData.addition;
    }
  }

  ent_HegemonyData_setProd_org(obj, idStr, v, arg3);
}
