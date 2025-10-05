/* main.c */

#include "tests/tests.h"
#include "random/random.h"
#include "terminal_io/terminal_io.h"
#include "game/game.h"
#include "turn/turn.h"
#include "scoring/scoring.h"

#include <assert.h>
#include <stddef.h>

int main()
{
    seed_random();
    
    all_tests();
    
    game_t   * game = get_game();
    player_t * players = game->player_list;
    room_t   * tower = game->tower;
    assert(NULL != tower);
    turn_t     turn;

    you_are_player(game);

    while(game_running())
    {
        player_t * player  = &players[game->current_player];

        initialize_turn(&turn);


        if (player->has_exited == false)
        {   
            if (player->is_you)
            {
                print_a_row_of_the_tower('a', game->tower);
                get_player_turn(&turn, game);
            }
            else
            {
                get_bot_turn(&turn, game);
            }
        }

        if (turn.exited)
        {
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

    print_all_hauls(game);
    score(game);
    print_score(game);

}