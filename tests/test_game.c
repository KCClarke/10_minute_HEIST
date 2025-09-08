/* test_game.c */

#include "test_game.h"
#include "game/game.h"

#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

void test_game()
{
    game_t * game = get_game();
    assert(NULL != game);

    assert(0 == strcmp("Love Potion #8", game->tower[0].p_card->name));

    assert(NULL == game->player_list[PLAYER_1].haul[0]);
    assert(0 == game->player_list[PLAYER_1].num_threes);

    printf("%s passed.\n", __func__);

}