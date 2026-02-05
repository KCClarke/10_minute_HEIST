/* turn.h */

#ifndef TURN_H
#define TURN_H

#include "location/location.h"
#include "players/players.h"

#include <stdbool.h>

typedef struct player_s player_t;
typedef struct turn_s turn_t;
typedef struct game_s game_t;

struct turn_s
{
    location_t location;
    bool print_menue;
    bool print_haul;
    bool card_found;
    bool exited;
    bool success;

};


void get_bot_turn(turn_t * turn, game_t * game);
void initialize_turn(turn_t * turn);
void get_player_turn(turn_t * turn, game_t * game);

void collect_card(turn_t * turn, game_t * game);
void move_player(turn_t * turn, game_t * game);

#endif