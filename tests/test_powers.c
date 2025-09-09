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

    const int curr_player = game->current_player;
    assert(0 == curr_player);
    assert(0 == game->player_list[curr_player].num_threes);

    card_t card = card_list[0];
    card.power(&card, game);



    printf("%s passed.\n", __func__);
}