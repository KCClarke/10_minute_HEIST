/** @file game.h
 *
 * @brief To define the struct that keeps track of the game state.
 *
 * @par
 * Written July 26 2025 Kasey Clarke
 */

#ifndef GAME_H
#define GAME_H

#define COMMAND_LENGTH 2
#define TOWER_WIDTH 5
#define TOWER_DEPTH 8

#include "cards/cards.h"
#include "players/players.h"

typedef struct
{
    player_ID_t occupant;

} room_t;

typedef struct
{
    char command[COMMAND_LENGTH]; 
    
    room_t tower[TOWER_DEPTH][TOWER_WIDTH];

} game_t;


#endif /* GAME_H */

/*** end of file ***/