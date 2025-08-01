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
    char command[COMMAND_LENGTH];

    uint8_t location[COMMAND_LENGTH];
    room_t tower[NUM_FLOORS][NUM_ROOMS];

} game_t;

void initialize(game_t * p_game);
bool command_to_location(game_t * p_game);

#endif /* GAME_H */

/*** end of file ***/