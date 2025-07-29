/** @file game.c
 *
 * @brief game.c handles the function for initializing the game.
 *
 * @par
 * Written July 19 2025 Kasey Clarke
 */

 #include "game.h"

/*!
 * @brief Initializes the master game struct with starting conditions
 * in main.
 *
 * @param[in] p_game a pointer to our master game struct.
 *
 * @return void.
 */
void
initialize(game_t * p_game)
{
    p_game->command[0] = 'I'; // Start the game by printing the instructions.
}

/*** end of file ***/