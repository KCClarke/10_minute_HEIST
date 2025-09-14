/* test_game.c */

#include "test_game.h"
#include "game/game.h"


#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

static inline void test_haul_initialization();

void test_game()
{
    game_t * game = get_game();
    assert(NULL != game);

    test_haul_initialization();

    printf("%s passed.\n", __func__);
    
}

static inline void test_haul_initialization()
{
    game_t * game = get_game();
    
    for (int index = 0; index < game->num_players; ++index)
    {
        assert(NULL != game->player_list[index].haul[0]);
    }
}