/* game.h */

#ifndef GAME_H
#define GAME_H

#include "constants.h"

#include "tower/tower.h"
#include "players/players.h"

typedef struct game_s
{
    int num_players;
    player_ID_t current_player;
    player_t * player_list;

    room_t * tower;

} game_t;

game_t * get_game();

#endif