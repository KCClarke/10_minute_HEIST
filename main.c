/* main.c */

#include "tests/tests.h"
#include "random/random.h"
#include "game/game.h"

#include <stdio.h>

int main()
{
    seed_random();
    all_tests();

    for (int test_index = 0; test_index < 100; ++test_index)
    {
        game_t * game = get_game();

        for (int index = 0; index < game->num_players; ++index)
        {
            char * card_name = game->player_list[index].haul[0]->name;
            printf("haul: %s\n", card_name);
        }

        for (int index = 0; index < TOWER_WIDTH; ++index)
        {
            char * card_name = game->tower[index].p_card->name;
            printf("tower: %s\n", card_name);
        }
        printf("\n\n");

    }
    
}