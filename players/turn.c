/* turn.c */

#include "turn.h"

#include "game/game.h"

void take_turn(turn_t * turn, game_t * game)
{
    turn->location.floor = 'a';
    turn->location.room = '1';
    turn->exited = false;

}
