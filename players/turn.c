/* turn.c */

#include "turn.h"

#include "game/game.h"

void take_turn(turn_t * turn, game_t * game)
{
    turn->location.floor = 'a';
    turn->location.room = '1';
    turn->exited = false;

}

bool did_not_move_up(const location_t * location, const game_t * game)
{
    return (true);
}
