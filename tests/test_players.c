/* test_players.c */

#include "players/players.h"

#include <assert.h>
#include <stdio.h>
#include <stddef.h>

static inline void test_player_initialization();
static inline void test_haul_initialization();
static inline void test_player_suit_counts();


void test_players()
{
    test_player_initialization();
    test_haul_initialization();
    test_player_suit_counts();

    printf("%s passed.\n", __func__);
    
}

static inline void test_player_suit_counts()
{
    player_t * player_list = get_player_list();

    for (int player_index = 0; player_index < MAX_PLAYERS; ++player_index)
    {
        for (int suit_index = 0; suit_index < NUM_BASIC_SUITS; ++suit_index)
        {
            assert(0 == player_list[player_index].num_suits[suit_index]);
        }
    }

    assert(0 == player_list[0].num_suits[POTION]);
}

static inline void test_player_initialization()
{
    player_t * players = get_player_list();

    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        assert(0 == players[index].num_threes);
        assert(0 == players[index].num_fours);
        assert(0 == players[index].num_fives);

        assert(0 == players[index].num_curses);
    }

}

static inline void test_haul_initialization()
{
    player_t * players = get_player_list();

    for(int player_index = 0; player_index < MAX_PLAYERS; ++player_index)
    {
        for(int haul_index = 0; haul_index < MAX_HAUL; ++haul_index)
        {
            assert(NULL == players[player_index].haul[haul_index]);
        }
    }

}
