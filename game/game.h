/** @file game.h
 *
 * @brief To define the struct that keeps track of the game state.
 *
 * @par
 * Written July 26 2025 Kasey Clarke
 */

#ifndef GAME_H
#define GAME_H

// Command length plantains to commands from the terminal.
#define COMMAND_LENGTH 2

#define NUM_FLOORS 8
#define NUM_ROOMS 5

#define FLOOR 0
#define ROOM  1

#include "cards/cards.h"
#include "players/players.h"

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    player_ID_t occupant;

} room_t;

typedef struct
{
    char     command[COMMAND_LENGTH];   // The command taken from the terminal. 
    uint8_t  location[COMMAND_LENGTH];  // The index location of a room in a tower.
    room_t   tower[NUM_FLOORS][NUM_ROOMS];

    uint8_t  total_players;
    uint8_t  current_player;
    player_t players[MAX_PLAYERS];

} game_t;

void initialize(game_t * p_game);
bool translate_command_to_location(game_t * p_game);
bool is_location_in_tower(game_t * game);
void advance_player(game_t * p_game);

#endif /* GAME_H */

/*** end of file ***/