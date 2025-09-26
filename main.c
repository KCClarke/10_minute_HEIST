/* main.c */

#include "tests/tests.h"
#include "random/random.h"
#include "terminal_io/terminal_io.h"
#include "game/game.h"

int main()
{
    seed_random();
    
    all_tests();
    
    game_t * game = get_game();
    print_a_card(game);
    
}