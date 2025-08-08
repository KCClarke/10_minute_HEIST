/** @file players.h
 *
 * @brief To define what a player is.
 *
 * @par
 * Written July 24 2025 Kasey Clarke
 */

#ifndef PLAYERS_H
#define PLAYERS_H

#define MAX_PLAYERS 5
#define LOCATION_LENGTH 2

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    no_player,
    player_1,
    player_2,
    player_3,
    player_4,
    player_5,
    all_players

} player_ID_t;

typedef struct
{
    bool is_you;
    player_ID_t player_ID;
    bool is_in_tower;
    uint8_t location[LOCATION_LENGTH];

} player_t;

#endif /* PLAYERS_H */

/*** end of file ***/