#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <common.h>
#include <gen/t.ent.Faction.h>

/**
 * @brief Checks if the given faction is a player.
 *
 * @param faction Pointer to the faction to check.
 * @return true if the faction is a player, false otherwise.
 */
bool isPlayer(ent_Faction* faction) {
  return faction && !faction->isAI;
}

/**
 * @brief Checks if the given faction is AI.
 *
 * @param faction Pointer to the faction to check.
 * @return true if the faction is AI, false otherwise.
 */
bool isAI(ent_Faction* faction) {
  return faction && faction->isAI;
}

/**
 * @brief Checks if the given faction is a village.
 *
 * @param faction Pointer to the faction to check.
 * @return true if the faction is a village, false otherwise.
 */
bool isVillage(ent_Faction* faction) {
  return !faction;
}

#endif // HELPER_FUNCTIONS_H
