/* test_powers.c */

#include "test_powers.h"

#include "game/game.h"
#include "cards/cards.h"

#include <stdio.h>
#include <stddef.h>
#include <assert.h>

void test_powers()
{
    game_t * game = get_game();
    const card_t * card_list = get_master_card_list();
    assert(NULL != card_list);

    card_list[0].power(game);

    printf("%s passed.\n", __func__);
}