/* test_powers.c */

#include "test_powers.h"

#include "game/game.h"
#include "cards/cards.h"
#include "players/players.h"

#include <stdio.h>
#include <stddef.h>
#include <assert.h>

static inline void test_love_potion();

void test_powers()
{
    test_love_potion();

    printf("%s passed.\n", __func__);
}

static inline void test_love_potion()
{
    game_t *  game = get_game();
    const card_t * card_list = get_master_card_list();
    assert(NULL != card_list);

    const int index = game->current_player;
    assert(0 == index);
    
    player_t * player_list = game-> player_list;

    assert(0 == player_list[index].num_threes);

    card_t card = card_list[0];
    card.power(&card, game);

    assert(1 == player_list[index].num_threes);
}