/* turn.h */

#ifndef TURN_H
#define TURN_H

#include "location/location.h"

#include <stdbool.h>

typedef struct game_s game_t;
typedef struct turn_s turn_t;

struct turn_s
{
    location_t location;
    bool exited;
    bool success;

};

void take_turn(turn_t * turn, game_t * game);

#endif