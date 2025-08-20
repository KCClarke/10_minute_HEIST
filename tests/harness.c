/** @file harness.c
 *
 * @brief Runs tests from all other modules.
 *
 * @par
 * Written July 29 2025 Kasey Clarke
 */

#include <stdio.h>

#include "harness.h"
#include "game/test_game.h"
#include "move/test_move.h"

/*!
 * @brief Prints the function's name to the terminal to verify connection
 * to main.
 *
 * @param[in] void
 *
 * @return void.
 */
void
all_tests()
{
    test_game();
    test_move();

    printf("Passed %s.\n", __func__);
}

/*** end of file ***/