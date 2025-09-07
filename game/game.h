/* game.h */

#ifndef GAME_H
#define GAME_H

#include "constants.h"

typedef struct game_s
{
    int num_players;
    player_ID_t current_player;

} game_t;

game_t * get_game();

#endif