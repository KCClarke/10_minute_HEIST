/* test_turn.c */

#include "test_turn.h"

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#include "game/game.h"
#include "players/players.h"

static inline void mock_turn();

void test_turn()
{
    mock_turn();

    printf("%s passed.\n", __func__);
}

static inline void mock_turn()
{
    game_t * game = get_game();
    assert(NULL != game);

    player_t * players = game->player_list;
    assert(NULL != players);

    turn_t turn;
    assert(NULL != &turn);

    /* Main gameplay loop.
    *
    * Three things make a turn successful
    *   one) Player exits.
    *   two) An exited player is skipped.
    *   three) Player takes a card. 
    */
    {
        player_t * player = &players[game->current_player];
        turn.success = false;
        
        if (player->has_exited == false)
        {

            player->take_turn(&turn, game);
            // bool player_did_not_move_up()
            // bool has_card_no_player()

        }
        else
        {
            turn.success = true;
        }

        if (turn.exited)
        {
            // TODO: exit player
            game->players_exited++;
            player->exit_number = game->players_exited;

            turn.success = true;
        }

        if (/* location in tower is valid */ true)
        {
            

            turn.success = true;
        }

        if (turn.success)
        {
            // Next Player
        }

    }

}