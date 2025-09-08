/* test_powers.c */

#include "test_powers.h"

#include "game/game.h"
#include "cards/cards.h"

#include <stdio.h>
#include <stddef.h>
#include <assert.h>

void test_powers()
{
    const card_t * card_list = get_master_card_list();
    assert(NULL != card_list);

    printf("%s passed.\n", __func__);
}