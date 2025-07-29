/** @file test_game.c
 *
 * @brief game.c handles the function for testing the game.
 *
 * @par
 * Written July 29 2025 Kasey Clarke
 */

 #include "test_game.h"
 #include <assert.h>

/*!
 * @brief Runs the tests for the master game struct
 *
 * @param void.
 *
 * @return void.
 */
void
test_game()
{
    game_t test_game;

    initialize(&test_game);
    assert('I' == test_game.command[0]);
    
}

/*** end of file ***/