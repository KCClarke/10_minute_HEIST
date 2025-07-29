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

static inline void clear_input(char command[]);

/*!
 * @brief Gets user input to be used by the switch statement
 * in main.
 *
 */
void
get_input(char command[])
{
    clear_input(command);
    prompt();

    uint8_t index = 0;
    char ch = '\0';

    while((ch = getchar()) != '\n')
    {
        if ((index < COMMAND_LENGTH) && ch != '\n')
        {
            command[index] = toupper(ch);
        }
        ++index;
    }
}
/**/
static inline void
clear_input(char command[])
{
    for (uint8_t index = 0; index < COMMAND_LENGTH; ++index)
    {
        command[index] = '\0';
    }
}

/*** end of file ***/