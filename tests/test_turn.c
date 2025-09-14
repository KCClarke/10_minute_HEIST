/* test_turn.c */

#include "test_turn.h"

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#include "game/game.h"

static inline void mock_turn();

void test_turn()
{
    mock_turn();

    printf("%s passed.\n", __func__);
}

static inline void mock_turn()
{

}