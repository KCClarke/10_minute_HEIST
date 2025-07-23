/** @file output.c
 *
 * @brief This module holds the function bodies for printing 
 * to the terminal.
 *
 * @par
 * Written July 19 2025 Kasey Clarke
 */

#include <stdio.h>
#include <stdint.h>

#include "output.h"

/*
 * The desired width of the terminal.
 */
#define TERMINAL_WIDTH 148

/*!
 * @brief Prints a row of **** for the user to adjust their terminal size
 *
 * @param[in] void
 *
 * @return void.
 */
void
print_row()
{
    printf("\nPlease adjust your terminal to fit all of the ***s.\n");

    for (uint8_t index = 0; index < TERMINAL_WIDTH; ++index)
    {
        putchar('*');
    }

    putchar('\n');
}


/*!
 * @brief Prints a greeting for the game.
 *
 * @param[in] void
 *
 * @return void.
 */
void
greeting()
{
    printf("\n%s\n", "Welcome to 10 minute HEIST");
}

/*!
 * @brief Prints a greeting for debug mode.
 *
 * @param[in] void
 *
 * @return void.
 */
void
debug_greeting()
{
    printf("\n%s\n", "Welcome to DEBUG mode");
}

/*!
 * @brief Prints instructions to the user, from main to the terminal
 * on how to use this program
 */
void
print_instructions()
{
    printf("\n");
    printf("Commands\n");
    printf("\tI : view Instructions\n");
    printf("\tP : view other Player's haul\n");
    printf("\tQ : Quit game\n");
    printf("\tR : view Rules\n");
    printf("\tS : view Scoring\n");
    printf("\tV : View your haul\n");
    printf("\tX : eXit tower\n");
    printf("\n");
    printf("To play:\n");
    printf("\tenter a letter number combination \n");
    printf("\ta1 through h5\n");
    printf("\tto move yourself through the Wizard's Tower\n");
    printf("\n");

}

/*!
 * @brief To print something to prompt the user for input
 */
void
prompt()
{
    printf("(heist) ");
}

/*** end of file ***/