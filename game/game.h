/* game.h */

#ifndef GAME_H
#define GAME_H

#include "constants.h"

#include "tower/tower.h"
#include "players/players.h"

#include <stdbool.h>

typedef struct game_s game_t;

struct game_s
{
    int num_players;
    player_ID_t current_player;
    player_t * player_list;
    room_t * tower;
    int players_exited;

};

game_t * get_game();

void exit_player();
void next_player();
bool game_running();

#endif