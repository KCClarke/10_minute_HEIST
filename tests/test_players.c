/* test_players.c */

#include "players/players.h"

#include <assert.h>
#include <stdio.h>

static inline void test_player_initialization();

void test_players()
{
    test_player_initialization();
    printf("%s passed.\n", __func__);
}

static inline void test_player_initialization()
{
    player_t * players = get_player_list();

    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        assert(0 == players[index].num_threes);
    }
}
