/* players.h */

#ifndef PLAYERS_H
#define PLAYERS_H

#include "constants.h"

typedef struct card_s card_t;

typedef struct player_s
{
    int num_threes;
    suit_t num_suits[UNIQUE_SUITS];
    card_t * haul[MAX_HAUL];

} player_t;

player_t * get_player_list();

#endif