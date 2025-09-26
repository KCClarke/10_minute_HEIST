/* terminal_io.c */

#include "terminal_out.h"

#include <stdio.h>

void print_a_card(game_t * game)
{
    printf("a card\n");
}

void welcome()
{
    printf("%s to Ten Minute Heist\n", __func__);
}

void how_many_players()
{
    printf("%s?\n", __func__);
}