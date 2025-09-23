/* test_scoring.c */

#include "test_scoring.h"
#include "test_turn.h"
#include "constants.h"
#include "scoring/scoring.h"

#include <stddef.h>
#include <assert.h>
#include <stdio.h>

static inline void test_for_tie();
static inline void test_point_values();

void test_scoring()
{
    assert(13 == NUM_SCORING_TILES);

    test_for_tie();

    printf("passed %s.\n", __func__);
}

static inline void test_point_values()
{
    int * points = get_points();
    assert(NULL != points);

    assert(3 == points[MOST_POTIONS]);
    assert(6 == points[MOST_TOMES]);
    assert(3 == points[MOST_THREES]);
    assert(5 == points[MOST_FIVES]);
    assert(2 == points[FIRST_EXIT]);
    assert(-1 == points[MOST_CURSES]);
}

static inline void test_for_tie()
{
    game_t * game = mock_game();
    print_mock_game(game);

}