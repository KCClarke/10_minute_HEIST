/* test_turn.c */

#include "test_turn.h"

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#include "game/game.h"
#include "players/players.h"

static inline void mock_turn();
static inline void mock_game();

void test_turn()
{
    mock_turn();
    mock_game();

    printf("%s passed.\n", __func__);
}

static inline void mock_game()
{
    game_t   * game = get_game();
    player_t * players = game->player_list;
    room_t   * tower = game->tower;
    turn_t     turn;

    assert(NULL != game);
    assert(NULL != players);
    assert(NULL != tower);

    initialize_turn(&turn);
    assert(false == turn.valid);
    assert(false == turn.exited);
    assert(false == turn.success);
    
    assert(true == game_running());

    while(game_running())
    {
        player_t * player  = &players[game->current_player];
        assert(NULL != player);

        initialize_turn(&turn);

        if (player->has_exited == false)
        {
            // TODO: get what the player wants to do for their turn.
            // turn.valid = get_turn(&turn, game);
        }
        else
        {
            // Skip them, they've exited.
            turn.success = true;
        }


        game->players_exited++; // TODO: move this inside if (turn.exited)
        
        if (turn.exited)
        {
            // TODO: exit_player();
            turn.success = true;
        }

        if (turn.valid)
        {
            // TODO: collect_card(turn.location.index);
            turn.success = true;
        }

        // TODO: uncomment the following if
        // if (turn.success)
        {
            next_player();
        }
    }

    assert(false == game_running());

}

static inline void mock_turn()
{
    game_t   * game = get_game();
    player_t * players = game->player_list;
    room_t   * tower = game->tower;
    turn_t     turn;

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
        turn.valid = false;
        
        if (player->has_exited == false)
        {

            take_turn(&turn, game);
            
            turn.valid =  did_not_move_up(&turn.location, player);
            to_index(&turn.location);
            turn.valid &= has_card_no_player(tower[turn.location.index]);

            assert(true == turn.valid);

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

        if (turn.valid)
        {
            room_t room = tower[turn.location.index];
            card_t * card = room.p_card;
            card->power(card, game);
            room.p_player = player;

            turn.success = true;
        }

        if (turn.success)
        {
            next_player();
        }

    }

}