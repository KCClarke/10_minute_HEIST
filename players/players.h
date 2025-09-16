/* players.h */

#ifndef PLAYERS_H
#define PLAYERS_H

#include "constants.h"

#include "cards/cards.h"

#include <stdbool.h>

typedef struct player_s player_t;

struct player_s
{
    int num_threes;
    int num_fours;
    int num_fives;
    int num_curses;
    suit_t num_suits[NUM_BASIC_SUITS];
    card_t * haul[MAX_HAUL];
    bool in_tower;

};

player_t * get_player_list();

#endif