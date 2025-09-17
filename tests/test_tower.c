/* test_tower.c */

#include "test_tower.h"
#include "tower/tower.h"
#include "cards/cards.h"
#include "players/players.h"
#include "constants.h"

#include <stdio.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

static inline void moving_love_potion_around();
static inline void test_has_card_no_player();

void test_tower()
{
    room_t * tower = get_tower();
    assert(NULL != tower);

    moving_love_potion_around();

    test_has_card_no_player();

    printf("%s passed.\n", __func__);

}

static inline void test_has_card_no_player()
{
    room_t * tower = get_tower();
    assert(NULL != tower);
    const card_t * card_list = get_master_card_list();
    assert(NULL != card_list);

}

static inline void moving_love_potion_around()
{
    room_t * tower = get_tower();
    const card_t * card_list = get_master_card_list();
    const card_t * card = &card_list[LOVE_POTION_8];

    tower[0].p_card = (card_t *) card;

    assert(3 == tower[0].p_card->value);
    assert(0 == strcmp("Love Potion #8", tower[0].p_card->name));
    assert(POTION == tower[0].p_card->suit);

    player_t * players = get_player_list();
    players[PLAYER_1].haul[0] = tower[0].p_card;
    tower[0].p_card = NULL;
    tower[0].p_player = &players[PLAYER_1];

    assert(3 == players[PLAYER_1].haul[0]->value);
    assert(0 == strcmp("Love Potion #8", players[PLAYER_1].haul[0]->name));
    assert(POTION == players[PLAYER_1].haul[0]->suit);

    assert(NULL == tower[0].p_card);
    assert(&players[PLAYER_1] == tower[0].p_player);

}