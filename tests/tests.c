/* tests.c */

#include "tests.h"
#include "test_cards.h"
#include "test_players.h"
#include "test_copying.h"
#include "test_tower.h"
#include "test_game.h"
#include "test_powers.h"
#include "test_turn.h"
#include "test_location.h"
#include "test_scoring.h"

#include <stdio.h>

/*!
 * @brief all_tests is the primary function for this file, 
 * it is to be called by main and runs all other test code.
 */
void all_tests()
{
    printf("\n");

    test_cards();
    test_players();
    test_copying();
    test_tower();
    test_game();
    test_powers();
    test_location();
    test_turn();
    test_scoring();
    
    printf("\n%s passed.\n\n", __func__);
    
}