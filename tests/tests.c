/* tests.c */
#include "cards/master_card_list.h"
#include "players/players.h"

#include <assert.h>
#include <stdio.h>

static inline void verify_love_potion();
static inline void verify_player_initialization();

/*!
 * @brief all_tests is the primary function for this file, 
 * it is to be called by main and runs all other test code.
 */
void all_tests()
{
    verify_love_potion();
    verify_player_initialization();
    printf("%s passed.\n", __func__);
}

static inline void verify_player_initialization()
{
    player_t * players = get_player_list();

    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        assert(0 == players[index].num_threes);
    }
}

static inline void verify_love_potion()
{
    const card_t * master_card_list = get_master_card_list();

    assert(3 == master_card_list[0].value);
    assert(POTION == master_card_list[0].suit);
}