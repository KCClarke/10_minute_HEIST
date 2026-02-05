/* test_players.c */

#include "players/players.h"
#include "game/game.h"

#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

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

    for (int index = 0; index < MAX_PLAYERS; ++index)
    {
        assert(0 == player_list[index].num_suits[POTION]);
        assert(0 == player_list[index].num_suits[FOSSIL]);
        assert(0 == player_list[index].num_suits[ARTIFACT]);
        assert(0 == player_list[index].num_suits[JEWEL]);
        assert(0 == player_list[index].num_suits[TOME]);
    }

}

static inline void test_player_initialization()
{
    player_t * player_list = get_player_list();

    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        assert(0 == player_list[index].num_values[THREES]);
        assert(0 == player_list[index].num_values[FOURS]);
        assert(0 == player_list[index].num_values[FIVES]);
        assert(0 == player_list[index].num_curses);
        assert(0 == player_list[index].exit_number);
        assert(0 == player_list[index].points);
        
        assert(false == player_list[index].in_tower);
        assert(false == player_list[index].has_exited);
        assert(false == player_list[index].is_you);
        assert(false == player_list[index].first_card_revealed);

    }

}

static inline void test_haul_initialization()
{
    player_t * player_list = get_player_list();

    for(int haul_index = 0; haul_index < MAX_HAUL; ++haul_index)
    {
        assert(NULL == player_list[PLAYER_1].haul[haul_index]);
        assert(NULL == player_list[PLAYER_2].haul[haul_index]);
        assert(NULL == player_list[PLAYER_3].haul[haul_index]);
        assert(NULL == player_list[PLAYER_4].haul[haul_index]);
        assert(NULL == player_list[PLAYER_5].haul[haul_index]);
    }
}
