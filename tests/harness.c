/** @file harness.c
 *
 * @brief Runs tests from all other modules
 *
 * @par
 * Written July 29 2025 Kasey Clarke
 */

#include <stdbool.h>

#include "harness.h"
#include "game/test_game.h"

/*!
 * @brief Prints the function's name to the terminal to verify connection
 * to main.
 *
 * @param[in] void
 *
 * @return void.
 */
bool
all_tests()
{
    test_game();
    
    return (true);
}

/*** end of file ***/