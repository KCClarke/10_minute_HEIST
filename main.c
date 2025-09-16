/* main.c */

#include "tests/tests.h"
#include "random/random.h"

int main()
{
    seed_random();
    all_tests();

}