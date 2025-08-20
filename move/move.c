/** @file move.c
 *
 * @brief Defines the functions for moving a character through the tower.
 *
 * @par
 * Written August 4 2025 Kasey Clarke
 */

#include "move.h"

// Private function prototypes
static inline void leave_previous_room(game_t * p_game);
static inline void update_player_location(game_t * p_game);

/*!
 * @brief Checks to see if the proposed location would be a valid move.
 * For now it just checks to see if there isn't a player.
 *
 * TODO: once cards are implimented check that there is a card at the location.
 *
 * @param p_game
 *
 * @return true if the proposed location is a valid, false otherwise.
 */
bool
is_move_valid(game_t * p_game)
{
    const uint8_t check_floor = p_game->location[FLOOR];
    const uint8_t check_room  = p_game->location[ROOM];

    const room_t room = p_game->tower[check_floor][check_room];

    // TODO: once cards are implimented change the definition of valid.
    const bool valid = no_player == room.occupant;

    return (valid);
}

/*!
 * @brief Moves the player to the new location.
 *
 * @param p_game
 *
 * @return void.
 */
void
move(game_t * p_game)
{
    leave_previous_room(p_game);

    // And go to the next room.
    const uint8_t to_floor = p_game->location[FLOOR];
    const uint8_t to_room  = p_game->location[ROOM];

    p_game->tower[to_floor][to_room].occupant = player_1;

    update_player_location(p_game);
}

/*!
 * @brief If the player is in the tower they need to 
 * Leave their current place before entering the next
 *
 * @param[in] p_game.
 *
 * @return void.
 */
static inline void
leave_previous_room(game_t * p_game)
{
    const uint8_t current = p_game->current_player;

    if (p_game->players[current].is_in_tower)
    {
        uint8_t floor = p_game->players[current].location[FLOOR];
        uint8_t room  = p_game->players[current].location[ROOM];
        
        p_game->tower[floor][room].occupant = no_player;
    }
    
    p_game->players[current].is_in_tower = true;
}

/*!
 * @brief After moving to a new room in the tower
 * the player updates their new location.
 * 
 * @param[in] p_game pointer to the game.
 *
 * @return void.
 */
static inline void
update_player_location(game_t * p_game)
{
    const uint8_t current = p_game->current_player;

    p_game->players[current].location[FLOOR] = p_game->location[FLOOR];
    p_game->players[current].location[ROOM]  = p_game->location[ROOM];
}

/*** end of file ***/