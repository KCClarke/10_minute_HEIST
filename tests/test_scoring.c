/* test_scoring.c */

#include "players/players.h"
#include "test_scoring.h"
#include "test_turn.h"
#include "constants.h"
#include "scoring/scoring.h"

#include <stddef.h>
#include <assert.h>
#include <stdio.h>

static inline void run_game_to_score();
static inline void test_point_values();

static inline void hard_coded_tests();

void test_scoring()
{
    hard_coded_tests();
    
    printf("passed %s.\n", __func__);
}

static inline void hard_coded_tests()
{
    player_t * players = get_player_list();
    assert(NULL != players);

    score(players);

    assert(500 == players[PLAYER_1].points);
    
}

static inline void test_point_values()
{
    assert(13 == NUM_SCORING_TILES);
    
    int * points = get_points();
    assert(NULL != points);

    assert(3 == points[MOST_POTIONS]);
    assert(6 == points[MOST_TOMES]);
    assert(3 == points[MOST_THREES]);
    assert(5 == points[MOST_FIVES]);
    assert(2 == points[FIRST_EXIT]);
    assert(-1 == points[MOST_CURSES]);
}

static inline void run_game_to_score()
{
    
}