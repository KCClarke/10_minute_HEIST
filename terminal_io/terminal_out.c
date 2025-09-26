/* terminal_io.c */

#include "terminal_out.h"

#include <stdio.h>

void welcome()
{
    printf("%s to Ten Minute Heist\n", __func__);
}

void how_many_players()
{
    printf("%s? ", __func__);
}