/* main.c */

#include "tests/tests.h"
#include "random/random.h"
#include "terminal_io/terminal_io.h"

int main()
{
    seed_random();
    
    all_tests();

    welcome();

}