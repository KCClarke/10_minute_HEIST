/* test_turn.c */

#include "test_turn.h"

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#include "constants.h"
#include "cards/cards.h"
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
    assert(0 == game->players_exited);
    assert(0 == game->current_player);
    assert(NULL != players);
    assert(NULL != tower);

    initialize_turn(&turn);
    assert(false == turn.card_found);
    assert(false == turn.exited);
    assert(false == turn.success);
    
    assert(true == game_running());

    while(game_running())
    {
        player_t * player  = &players[game->current_player];
        assert(NULL != player);

        initialize_turn(&turn);

        if (player->has_exited == false)
        {   // TODO: get what the player wants to do for their turn.
            get_bot_turn(&turn, game);
        }
        else
        {   // Skip them, they've exited.
            turn.success = true;
        }

        if (turn.exited)
        {
            printf(" turn exited\n");
            exit_player();
            turn.success = true;
        }

        if (turn.card_found)
        {   

            collect_card(&turn, game);
            move_player(&turn, game);
            turn.success = true;
        }

        if (turn.success)
        {
            next_player();
        }
    }

    assert(false == game_running());
    return (game);

}

void print_mock_game(const game_t * game)
{
    printf("\n");
    for (int index = 0; index < game->num_players; ++index)
    {
        player_t * player = &game->player_list[index];
        const char ** suit_names = get_suit_names();

        printf("player %d:\n", 1 + index);
        for (int num_cards = 0; num_cards < player->cards_in_haul; ++num_cards)
        {
            const card_t * card = player->haul[num_cards];
            printf("\t%d ", card->value);
            printf("%-9s ", suit_names[card->suit]);
            printf("%s\n", card->name);
        }
        
        printf("\tthrees:%d  fours:%d fives:%d\n", player->num_threes, player->num_fours, player->num_fives);
        
        for (int index = 0; index < NUM_BASIC_SUITS; ++index)
        {
            printf("\t%-9s ", suit_names[index]);
            printf("%d\n", player->num_suits[index]);
        }

        printf("\texited:%d\n", player->exit_number);
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
        turn.card_found = false;
        
        if (player->has_exited == false)
        {
            take_turn(&turn, game);
            
            to_index(&turn.location);
            assert(0 == turn.location.index);

            turn.card_found = has_card_no_player(tower[turn.location.index]);

            assert(true == turn.card_found);

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

        if (turn.card_found )
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