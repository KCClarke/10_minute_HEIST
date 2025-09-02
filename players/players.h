/* players.h */

#ifndef PLAYERS_H
#define PLAYERS_H

#define MAX_PLAYERS 5

typedef struct player_s
{
    int num_threes;

} player_t;

player_t * get_player_list();

#endif