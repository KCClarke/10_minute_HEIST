/* test_game.c */

#include "test_game.h"
#include "game/game.h"

#include <stdio.h>
#include <assert.h>
#include <stddef.h>

void test_game()
{
    game_t * game = get_game();
    assert(NULL != game);

    printf("%s passed.\n", __func__);

}