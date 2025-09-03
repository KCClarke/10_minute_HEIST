/* test_copying.c */

#include "test_copying.h"
#include "cards/cards.h"
#include "players/players.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
 * Checking to see if we can copy the pointer to the card to the player's haul.
 */
void test_copying()
{
    const card_t * card = get_master_card_list();
    player_t * player = get_player_list();

    assert(NULL == player[0].haul[0]);

    player[0].haul[0] = (card_t *) card; // We cast because we are ignoring the const.
    
    assert(0 == strcmp("Love Potion #8", player[0].haul[0]->name));
    assert(3 == player[0].haul[0]->value);
    assert(POTION == player[0].haul[0]->suit);

    printf("%s passed.\n", __func__);
}