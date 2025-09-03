/* tests.c */

#include "tests.h"
#include "test_cards.h"
#include "test_players.h"
#include "test_copying.h"

#include <stdio.h>

/*!
 * @brief all_tests is the primary function for this file, 
 * it is to be called by main and runs all other test code.
 */
void all_tests()
{
    test_cards();
    test_players();
    test_copying();

    printf("\n%s passed.\n", __func__);
}