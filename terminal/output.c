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
#include <assert.h>
#include "output.h"

#define CHARACTERS_PER_ROOM 28

//private function prototypes
static inline void print_room_numbers();
static inline void print_floor_seperator();
static inline void print_blank_room_line();
static inline void
print_first_line(const game_t * game, const uint8_t floor, const uint8_t room);
static inline void print_remaining_spaces(uint8_t printed);


/*
 * The desired width of the terminal.
 */
#define TERMINAL_WIDTH 148

/*!
 * @brief Prints the whole tower.
 *
 * @param[in] The pointer to the game struct
 *
 * @return void.
 */
void
print_tower(game_t * p_game)
{
    printf("TOWER MAP\n");
    print_room_numbers();

    for (uint8_t floor = 0; floor < NUM_FLOORS; ++floor)
    {
        printf("%c|", 'A' + floor);
        
        for(uint8_t room = 0; room < NUM_ROOMS; ++room)
        {
            print_first_line(p_game, floor, room);
            putchar('|');
        }

        putchar('\n');

        print_floor_seperator();
    }
}

/*!
 * @brief Prints a row of **** for the user to adjust their terminal size
 *
 * @param[in] void
 *
 * @return void.
 */
void
print_sizing_row()
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
    printf("\n%s\n", "Welcome to DEBUG mode.");
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
    printf("\tT : print Tower\n");
    printf("\tV : View your haul\n");
    printf("\tX : eXit tower\n");

    printf("\n");
    printf("To play:\n");
    printf("\tEnter a letter number combination \n");
    printf("\tsuch as a1 through h5\n");
    printf("\tto move yourself through the Wizard's Tower.\n");

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


// private function bodies

/*!
 * @brief Prints the room numbers for the tower.
 *
 * @param void.
 *
 * @return void
 */
static inline void
print_room_numbers()
{
   printf("  ");

   for (uint8_t room_number = 0; room_number < NUM_ROOMS; ++room_number)
   {
       printf("______________%d_____________", 1 + room_number);
       putchar(' ');
   }
   
   putchar('\n');
}

/*!
 * @brief Prints the room numbers for the tower.
 *
 * @param void.
 *
 * @return void
 */
static inline void
print_floor_seperator()
{
   printf("  ");

   for (uint8_t rooms = 0; rooms < NUM_ROOMS; ++rooms)
   {
       for (uint8_t dashes = 0; dashes < CHARACTERS_PER_ROOM; ++dashes)
       {
           putchar('-');
       }
       
       putchar(' ');
   }
   
   putchar('\n');
}

/*!
 * @brief Prints a bunch of spaces for a blank line of a card in the tower.
 *
 * @param void
 *
 * @return void
 */
static inline void
print_blank_room_line()
{
    for (uint8_t spaces = 0; spaces < CHARACTERS_PER_ROOM; ++spaces)
    {
        putchar(' ');
    }
}

/*!
 * @brief Prints the first line for a room
 *
 * @param[in] p_game, the pointer to the game
 * @param[in] floor, the index of the floor.
 * @param[in] room, the index of the room.
 *
 *@return void;
 */
static inline void
print_first_line(const game_t * game, const uint8_t floor, const uint8_t room)
{
    const player_ID_t occupant = game->tower[floor][room].occupant;
    if (no_player == occupant)
    {
        print_blank_room_line();
    }
    else
    {
        uint8_t printed = printf(" player %d", (uint8_t) occupant);
        print_remaining_spaces(printed);
    }

}

/*!
 * @brief Prints the remaining spaces for a line of a room.
 *
 * @param[in] printed, the number already printed for the line.
 *
 * @return void.
 */
static inline void
print_remaining_spaces(uint8_t printed)
{
    for (; printed < CHARACTERS_PER_ROOM; ++printed)
    {
        putchar(' ');
    }
}

/*** end of file ***/