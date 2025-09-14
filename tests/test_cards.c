/* test_cards.c */

#include "test_cards.h"
#include "cards/cards.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

static inline void test_love_potion();


void test_cards()
{
    test_love_potion();

    printf("%s passed.\n", __func__);

}


static inline void test_love_potion()
{
    const card_t * master_card_list = get_master_card_list();
    
    const card_t card = master_card_list[LOVE_POTION_8];    

    assert(0 == strcmp("Love Potion #8", card.name));
    assert(3 ==                          card.value);
    assert(POTION ==                     card.suit);
    assert(0 ==                          card.curse);
    assert(NULL !=                       card.power);

}
