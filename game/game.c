/** @file game.c
 *
 * @brief game.c handles the function for initializing and playing the game.
 *
 * @par
 * Written July 19 2025 Kasey Clarke
 */

 #include "game.h"

 // private func prototypes
 static inline bool location_in_tower(game_t * p_game);
 static inline void everybody_out(game_t * p_game);

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
    everybody_out(p_game);
}


/*!
 * @brief Translates player readable tower coordinates A1 through H5
 * to indicies for the program for use in the 2d array tower[][].
 * Takes our command array makes the translation and populates the
 * loction array.
 *
 * @param[in] p_game a pointer to our master struct
 *
 * @return true if the location is within the bounds of the tower
 */
bool
command_to_location(game_t * p_game)
{
   const bool in_tower = location_in_tower(p_game);

   if(in_tower)
   {
       const uint8_t floor_index = (p_game->command[FLOOR] - 'A');
       p_game->location[FLOOR] = floor_index;

       const uint8_t room_index = (p_game->command[ROOM] - '0') - 1;
       p_game->location[ROOM] = room_index;
   }

   return (in_tower);
}

// Private function definitions.
/*!
 * @brief Sets the ocupant of each room to no_player.
 *
 * @param void
 *
 * @return void
 */
static inline void
everybody_out(game_t * p_game)
{
    for (uint8_t floor = 0; floor < NUM_FLOORS; ++floor)
    {
        for (uint8_t room = 0; room < NUM_ROOMS; ++room)
        {
            p_game->tower[floor][room].occupant =  no_player;
        }
    }    
}

/*!
 * @brief Checks to see if our command is a location coordinate.
 *
 * @param[in] p_game a pointer to our master struct.
 *
 * @return true if and only if the command is between A1 and H5
 */
static inline bool
location_in_tower(game_t * game)
{
    bool in_tower = true;

    if ((game->command[FLOOR] < 'A') || (game->command[FLOOR] > 'H'))
    {
        in_tower = false;
    }

    if ((game->command[ROOM] < '1') || (game->command[ROOM] > '5'))
    {
        in_tower = false;
    }

    return (in_tower);
}
/*** end of file ***/