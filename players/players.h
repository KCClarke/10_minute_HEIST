/* players.h */

#ifndef PLAYERS_H
#define PLAYERS_H

#define MAX_PLAYERS 5
#define MAX_HAUL 40

typedef struct card_s card_t;

typedef struct player_s
{
    int num_threes;
    card_t * haul[MAX_HAUL];

} player_t;

player_t * get_player_list();

#endif