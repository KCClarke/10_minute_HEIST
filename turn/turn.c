/* turn.c */

#include "turn.h"

#include "game/game.h"
#include "players/players.h"


bool get_bot_turn(turn_t * turn, game_t * game)
{
    room_t * tower = game->tower;
    turn->location.room = '1';
    for(;;)
    {
        turn->location.floor = get_bot_floor(game);

        if (turn->location.floor > 'h')
        {
            turn->exited = true;
            break;
        }

        for (int index = 0; index < TOWER_WIDTH; ++index)
        {
            to_index(&turn->location);
            if (has_card_no_player(tower[turn->location.index]))
            {
                break;
            }
            turn->location.room++;
        }

    }
    return (true);
}

void initialize_turn(turn_t * turn)
{
    turn->valid = false;
    turn->exited = false;
    turn->success = false;
}

void take_turn(turn_t * turn, game_t * game)
{
    turn->location.floor = 'a';
    turn->location.room = '1';
    turn->exited = false;

}

bool did_not_move_up(const location_t * location, const player_t * player)
{
    return (true);
}
