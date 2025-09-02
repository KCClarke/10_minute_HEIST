/* tests.c */
#include "cards/master_card_list.h"

#include <assert.h>
#include <stdio.h>

static inline void verify_love_potion();

/*!
 * @brief all_tests is the primary function for this file, 
 * it is to be called by main and runs all other test code.
 */
void all_tests()
{
    verify_love_potion();

    printf("%s passed.\n", __func__);
}

static inline void verify_love_potion()
{
    const card_t * master_card_list = get_master_card_list();

    assert(3 == master_card_list[0].value);
    assert(POTION == master_card_list[0].suit);
}