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
    bool valid;
    bool exited;
    bool success;

};


bool get_turn(turn_t * turn, game_t * game);
void initialize_turn(turn_t * turn);
void take_turn(turn_t * turn, game_t * game);
bool did_not_move_up(const location_t * location, const player_t * player);

#endif