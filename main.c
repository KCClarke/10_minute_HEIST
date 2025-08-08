/*****************************************************************************/
/** @file main.c
 *
 * @brief Welcome to 10 MINUTE HEIST
 * The purpose of this file
 *
 * @par
 * Written July 16 2025 Kasey Clarke
 */

#if DEBUG
    #include "tests/harness.h"
#endif

 #include "game/game.h"
 #include "random/random.h"
 #include "move/move.h"
 #include "terminal/io.h"

static inline void command_handler(game_t * game);

/*!
 * @brief The main function runs the test code if the program is run in debug mode,
 * Otherwise the user is asked to adjust their terminal to the correcct size and 
 * the game is run.
 */
int main() 
{
    seed_random();
    #if DEBUG
        debug_greeting();
        all_tests();
    
    #else
        print_sizing_row();
        greeting();

        game_t game;
        initialize(&game);
        print_tower(&game);

        for (;;)
        {
            command_handler(&game); 
            
            get_input(&game);

            if ('Q' == game.command[0])
            {
                break;
            }
        }

    #endif

    return 0;
}

/*!
 * @brief This function combines user input and output with game logic.
 * It is in main.c to be easily found and eddited.
 *
 * @param[in] p_game a pointer to our master game struct.
 *
 * @return void.
 */
static inline void
command_handler(game_t * p_game)
{
    switch (p_game->command[0])
    {
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        { // The above cases (A through H) correspond to floors of the tower.
          // Fallthrough behavior of this switch statement is intentional.

          // TODO: impliment moving through the tower.
          if(translate_command_to_location(p_game))
          {
            move(p_game);
            print_tower(p_game);
          }
        
        }
        break;

        case 'I':
        {
            print_instructions();
        }
        break;

        case 'P': 
        { // TODO: view other Player's haul
        }
        break;
        
        case 'R':
        { // TODO: view Rules
        }
        break;

        case 'S': 
        { // TODO: view Scoring
        }
        break;

        case 'T':
        {
            print_tower(p_game);
        }
        break;

        case 'V': 
        { // TODO: View your haul
        }
        break;

        case 'X': 
        { // TODO: eXit tower
        }
        break;

        default: 
        { // TODO: define default behavior
        }
        break;
    }
}

/*** end of file ***/