/* main.c */

#include "tests/tests.h"
#include "random/random.h"
#include "terminal_io/terminal_io.h"

int main()
{
    seed_random();
    
    // all_tests();

    welcome();
    how_many_players();
    get_num_players();
}