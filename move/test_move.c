/** @file move.c
 *
 * @brief Defines the functions for moving a character through the tower.
 *
 * @par
 * Written August 4 2025 Kasey Clarke
 */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "move.h"
#include "test_move.h"

// private function headers
static inline void test_is_move_valid();

/*!
 * @brief Tests the functions for doing a move.
 *
 * @param void
 *
 * @return void.
 */
void
test_move()
{
    test_is_move_valid();

    printf("Passed %s.\n", __func__);
}

/*!
 * @brief Checks to see if the proposed location would be a valid move.
 * For now it just checks to see if there isn't a player.
 * TODO: once cards are implimented check that there is a card at the location.
 *
 * @param void
 *
 * @return void
 */
static inline void
test_is_move_valid()
{
    game_t game;
    initialize(&game);
    
    game.command[0] = 'A';
    game.command[1] = '1';
    translate_command_to_location(&game);
    assert(true == is_move_valid(&game));
    
    uint8_t floor = game.location[FLOOR];
    uint8_t room  = game.location[ROOM];

    assert(no_player == game.tower[floor][room].occupant);
    move(&game);
    assert(player_1  == game.tower[floor][room].occupant);


    game.command[0] = 'A';
    game.command[1] = '2'; // move to the right by one
    translate_command_to_location(&game);
    assert(true == is_move_valid(&game));
    
    floor = game.location[FLOOR];
    room  = game.location[ROOM];

    assert(no_player == game.tower[floor][room].occupant);
    move(&game);
    assert(player_1  == game.tower[floor][room].occupant);

    game.command[0] = 'A';
    game.command[1] = '1'; 
    translate_command_to_location(&game);
    // Make sure the previous room is now unocupied.
    floor = game.location[FLOOR];
    room  = game.location[ROOM];
    assert(no_player == game.tower[floor][room].occupant);

}

/*** end of file ***/