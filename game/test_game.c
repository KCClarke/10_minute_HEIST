/** @file test_game.c
 *
 * @brief game.c handles the function for testing the game.
 *
 * @par
 * Written July 29 2025 Kasey Clarke
 */

#include "game.h"
#include "test_game.h"
#include <assert.h>

// Private function prototypes
static inline void test_initialization();
static inline void test_command_to_location();

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
    test_initialization();
    test_command_to_location();
}

/*!
 * @brief tests the initialization of a game_t game
 * make sure the starting conditions are correct.
 *
 * @param void
 *
 * @return void
 */
static inline void test_initialization()
{
    game_t test_game;

    initialize(&test_game);
    
    assert('I' == test_game.command[0]);
    
    for (uint8_t floor = 0; floor < NUM_FLOORS; ++floor)
    {
        for (uint8_t room = 0; room < NUM_ROOMS; ++room)
        {
           assert(no_player == test_game.tower[floor][room].occupant);
        }
    }
}

/*!
 * @brief tests the translation from a command to move from the terminal
 * to a location in the tower.
 *
 * @param void
 *
 *@ return void
 */
static inline void test_command_to_location()
{
    game_t test_game;

    // top left
    test_game.command[FLOOR] = 'A';
    test_game.command[ROOM]  = '1';
    assert(command_to_location(&test_game));
    assert(0 == test_game.location[FLOOR]);
    assert(0 == test_game.location[ROOM]);

    // bottom right
    test_game.command[FLOOR] = 'H';
    test_game.command[ROOM]  = '5';
    assert(command_to_location(&test_game));
    assert(7 == test_game.location[FLOOR]);
    assert(4 == test_game.location[ROOM]);

    test_game.command[FLOOR] = 'A';
    test_game.command[ROOM]  = '6'; // Not a room.
    assert(false == command_to_location(&test_game));

    test_game.command[FLOOR] = 'A';
    test_game.command[ROOM]  = '0'; // Also not a room.
    assert(false == command_to_location(&test_game));

    test_game.command[FLOOR] = 'Z'; // Not a floor.
    test_game.command[ROOM]  = '1';
    assert(false == command_to_location(&test_game));


    test_game.command[FLOOR] = 'W'; // Also not a floor.
    test_game.command[ROOM]  = '1';
    assert(false == command_to_location(&test_game));
}

/*** end of file ***/