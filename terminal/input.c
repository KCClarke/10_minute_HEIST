/** @file input.c
 *
 * @brief This module holds the function bodies for printing 
 * getting input from the user via the terminal.
 *
 * @par
 * Written July 22 2025 Kasey Clarke
 */

#include "input.h"
#include "output.h"

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

// private functions
static inline void clear_input(game_t * p_game);

/*!
 * @brief Gets user input to be used by the switch statement
 * in main.
 *
 * @param[in] p_game pointer to our game struct fromm main.
 *
 * @return void
 */
void
get_input(game_t * p_game)
{
    clear_input(p_game);
    prompt();

    uint8_t index = 0;
    char ch = '\0';

    while((ch = getchar()) != '\n')
    {
        if ((index < COMMAND_LENGTH) && ch != '\n')
        {
            p_game->command[index] = toupper(ch);
        }
        ++index;
    }
}

// private function bodies
/*!
 * @brief Sets our command array to null.
 *
 * @param[in] p_game the location of our game struct
 *
 * @return void.
 */
static inline void
clear_input(game_t * p_game)
{
    for (uint8_t index = 0; index < COMMAND_LENGTH; ++index)
    {
        p_game->command[index] = '\0';
    }
}

/*** end of file ***/