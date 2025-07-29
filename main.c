/*****************************************************************************/
/** @file main.c
 *
 * @brief Welcome to 10 MINUTE HEIST
 *
 * @par
 * Written July 16 2025 Kasey Clarke
 */

 #include "game.h"
 #include "terminal/io.h"

int main()
{
    #if DEBUG
        debug_greeting();
    #else
        greeting();
    #endif
    
    print_sizing_row();

    game_t game;
    game.command[0] = 'I';

    for (;;) 
    {
        switch (game.command[0])
        {
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            { // Above cases (A through H) correspond to floors of the tower.
              // Fallthrough behavior of this switch statement is intentional.
              
              // TODO: impliment moving through the tower.
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

            case 'Q': 
            { // Quit game
                return 0;
            }

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
                print_tower(game);
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

        } /* end switch */
        get_input(game.command);
    }
}

/*** end of file ***/