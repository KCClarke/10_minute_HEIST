/* main.c */

#include "tests/tests.h"
#include "random/random.h"
#include "game/game.h"

#include <stdio.h>

int main()
{
    seed_random();
    all_tests();

    for (int test_index = 0; test_index < 10; ++test_index)
    {
        game_t * game = get_game();

        for (int index = 0; index < game->num_players; ++index)
        {
            const player_t * player_list = game->player_list;
            const player_t * player = &player_list[index];
            const card_t * card = player->haul[0];
            
            printf("haul: %s\n", card->name);
            printf("\tcard value: %d\n", card->value);
            printf("threes:%d fours:%d fives:%d\n\n", player->num_threes, player->num_fours, player->num_fives);
            
        }
        
        printf("\n");

        for (int index = 0; index < TOWER_WIDTH; ++index)
        {
            // char * card_name = game->tower[index].p_card->name;
            // printf("tower: %s\n", card_name);
        }
        printf("\n");

    }
    
}