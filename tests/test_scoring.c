/* test_scoring.c */

#include "test_scoring.h"
#include "test_turn.h"
#include "constants.h"

#include <stddef.h>
#include <assert.h>
#include <stdio.h>

static inline void test_for_tie();

void test_scoring()
{
    assert(13 == NUM_SCORING_TILES);

    test_for_tie();

    printf("passed %s.\n", __func__);
}

static inline void test_for_tie()
{
    game_t * game = mock_game();
    print_mock_game(game);

}