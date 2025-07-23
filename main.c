/*****************************************************************************/
/** @file main.c
 *
 * @brief Welcome to 10 MINUTE HEIST
 *
 * @par
 * Written July 16 2025 Kasey Clarke
 */
 
#include "terminal/io.h"

int main()
{
    #if DEBUG
        debug_greeting();
    #else
        greeting();
    #endif
    
    print_row();
    print_instructions();

    char command[COMMAND_LENGTH];

    for(;;) 
    {
        get_input(command);

        switch (command[0])
        {
            case 'I':
            {
                print_instructions();
                break;
            }
            case 'P': // view other Player's haul
            {
                break;
            }
            case 'Q': // Quit game
            {
                return 0;
            }
            case 'R': // view Rules
            {
                break;
            }
            case 'S': // view Scoring
            {
                break;
            }
            case 'V': // View your haul
            {
                break;
            }
            case 'X': // eXit tower
            {
                break;
            }
            default:
            {
                break;
            }
        } /* end switch */
        
        clear_input(command);

    } /* end for (;;) */
}

/*** end of file ***/