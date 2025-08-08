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
#include <stdio.h>

// Private function prototypes
static inline void test_initialization();
static inline void test_player_initialization();
static inline void test_translate_command_to_location();

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
    test_player_initialization();
    test_translate_command_to_location();

    printf("Passed %s.\n", __func__);
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
    game_t game;

    initialize(&game);
    
    assert('I' == game.command[0]);
    
    for (uint8_t floor = 0; floor < NUM_FLOORS; ++floor)
    {
        for (uint8_t room = 0; room < NUM_ROOMS; ++room)
        {
           assert(no_player == game.tower[floor][room].occupant);
        }
    }


}

/*!
 * @brief Tests player initialization.
 *
 * @param[in] void
 *
 * @return void
 */
static inline void
test_player_initialization()
{
    game_t game;
    initialize(&game);

    assert(false == game.players[0].is_in_tower);
    assert(player_1 == game.players[0].player_ID);
}


/*!
 * @brief tests the translation from a command to move from the terminal
 * to a location in the tower.
 *
 * @param void
 *
 *@ return void
 */
static inline void test_translate_command_to_location()
{
    game_t game;

    // top left
    game.command[FLOOR] = 'A';
    game.command[ROOM]  = '1';
    assert(translate_command_to_location(&game));
    assert(0 == game.location[FLOOR]);
    assert(0 == game.location[ROOM]);

    // bottom right
    game.command[FLOOR] = 'H';
    game.command[ROOM]  = '5';
    assert(translate_command_to_location(&game));
    assert(7 == game.location[FLOOR]);
    assert(4 == game.location[ROOM]);

    game.command[FLOOR] = 'A';
    game.command[ROOM]  = '6'; // Not a room.
    assert(false == translate_command_to_location(&game));

    game.command[FLOOR] = 'A';
    game.command[ROOM]  = '0'; // Also not a room.
    assert(false == translate_command_to_location(&game));

    game.command[FLOOR] = 'Z'; // Not a floor.
    game.command[ROOM]  = '1';
    assert(false == translate_command_to_location(&game));


    game.command[FLOOR] = 'W'; // Also not a floor.
    game.command[ROOM]  = '1';
    assert(false == translate_command_to_location(&game));
}

/*** end of file ***/