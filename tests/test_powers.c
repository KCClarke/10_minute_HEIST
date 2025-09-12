/* test_powers.c */

#include "test_powers.h"

#include "constants.h"
#include "game/game.h"
#include "cards/cards.h"
#include "players/players.h"

#include <stdio.h>
#include <stddef.h>
#include <assert.h>

static inline void test_love_potion();
static inline void test_potion_of_strength();
static inline void test_tarot_cards();

void test_powers()
{
    test_love_potion();
    test_potion_of_strength();
    test_tarot_cards();

    printf("%s passed.\n", __func__);
}

static inline void test_tarot_cards()
{
    game_t * game = get_game();
    const card_t * card_list = get_master_card_list();
    const int index = game->current_player;
    player_t * player_list = game->player_list;

    card_t celestial = card_list[CELESTIAL_TAROT];
    assert(2 == celestial.value);
    assert(WILD == celestial.suit);
    assert(1 == celestial.curse);

    celestial.power(&celestial, game);
    assert(1 == player_list[index].num_curses);
    assert(2 == player_list[index].num_suits[POTION]);
    assert(2 == player_list[index].num_suits[FOSSIL]);
    assert(2 == player_list[index].num_suits[ARTIFACT]);
    assert(2 == player_list[index].num_suits[JEWEL]);
    assert(2 == player_list[index].num_suits[TOME]);

    card_t infernal = card_list[INFERNAL_TAROT];
    assert(2 == infernal.value);
    assert(WILD == infernal.suit);
    assert(1 == infernal.curse);

    infernal.power(&infernal, game);
    assert(2 == player_list[index].num_curses);
    assert(4 == player_list[index].num_suits[POTION]);
    assert(4 == player_list[index].num_suits[FOSSIL]);
    assert(4 == player_list[index].num_suits[ARTIFACT]);
    assert(4 == player_list[index].num_suits[JEWEL]);
    assert(4 == player_list[index].num_suits[TOME]);

}

static inline void test_potion_of_strength()
{
    game_t * game = get_game();
    const card_t * card_list = get_master_card_list();
    const int index = game->current_player;
    
    player_t * player_list = game-> player_list;
    assert(0 == player_list[index].num_fours);
    assert(0 == player_list[index].num_suits[POTION]);
    assert(0 == player_list[index].num_curses);

    card_t card = card_list[POTION_OF_STRENGTH];
    assert(4 == card.value);
    assert(POTION == card.suit);
    assert(0 == card.curse);

    card.power(&card, game);
    assert(1 == player_list[index].num_fours);
    assert(4 == player_list[index].num_suits[POTION]);

}

static inline void test_love_potion()
{
    game_t * game = get_game();
    const card_t * card_list = get_master_card_list();
    assert(NULL != card_list);

    const int index = game->current_player;
    assert(0 == index);
    
    player_t * player_list = game-> player_list;

    assert(0 == player_list[index].num_threes);

    card_t card = card_list[LOVE_POTION_8];
    
    card.power(&card, game);
    assert(1 == player_list[index].num_threes);
    assert(3 == player_list[index].num_suits[POTION]);

}