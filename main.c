/* main.c */

#include "tests/tests.h"
#include "random/random.h"
#include "game/game.h"

#include <stdio.h>

int main()
{
    seed_random();
    all_tests();

    game_t * game = get_game();

    for (int index = 0; index < game->num_players; ++index)
    {
        printf("\nhello %s\n", game->player_list[index].haul[0]->name);
    }
    
}