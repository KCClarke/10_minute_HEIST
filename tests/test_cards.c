/* test_cards.c */

#include "test_cards.h"
#include "cards/cards.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>

static inline void test_love_potion();


void test_cards()
{
    test_love_potion();

    printf("%s passed.\n", __func__);

}


static inline void test_love_potion()
{
    const card_t * master_card_list = get_master_card_list();

    assert(0 == strcmp("Love Potion #8", master_card_list[0].name));
    assert(3 == master_card_list[0].value);
    assert(POTION == master_card_list[0].suit);

}
