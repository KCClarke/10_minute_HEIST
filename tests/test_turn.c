/* test_turn.c */

#include "test_turn.h"

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#include "players/players.h"

static inline void mock_turn();

void test_turn()
{
    mock_turn();
    mock_game();

    printf("%s passed.\n", __func__);
}

game_t * mock_game()
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
            get_bot_turn(&turn, game);
            turn.success = true;
        }
        else
        {
            // Skip them, they've exited.
            turn.success = true;
        }

        if (turn.exited)
        {
            // TODO: exit_player();
            exit_player();
            turn.success = true;
        }
        else
        {
            // TODO: collect_card(turn.location.index);
            
            collect_card(&turn, game);
            move_player(&turn, game);
            turn.success = true;
        }

        if (turn.success)
        {
            next_player();
        }
    }

    //assert(false == game_running());
    
    return (game);
}

void print_mock_game(const game_t * game)
{
    printf("\n");
    for (int index = 0; index < game->num_players; ++index)
    {
        player_t * player = &game->player_list[index];

        printf("player %d:\n", 1 + index);
        for (int num_cards = 0; num_cards < player->cards_in_haul; ++num_cards)
        {
            printf("\t%s\n", player->haul[num_cards]->name);
        }

    }

    printf("\n");
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