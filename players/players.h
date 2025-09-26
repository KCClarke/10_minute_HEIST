/* players.h */

#ifndef PLAYERS_H
#define PLAYERS_H

#include "constants.h"

#include "cards/cards.h"
#include "location/location.h"
#include "turn/turn.h"

#include <stdbool.h>

typedef struct player_s player_t;
typedef struct game_s game_t;

struct player_s
{
    int num_values[NUM_VALUES];
    int num_curses;
    suit_t num_suits[NUM_BASIC_SUITS];
    card_t * haul[MAX_HAUL];
    bool first_card_revealed;

    bool in_tower;
    location_t location;

    int exit_number;
    bool has_exited;
    
    int cards_in_haul;
    
    int points;
    bool awards[NUM_SCORING_TILES];

    bool is_you;
    
};

player_t * get_player_list();

#endif