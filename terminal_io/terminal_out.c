/* terminal_io.c */

#include "terminal_out.h"

#include <stdio.h>


void print_a_card(card_t * card)
{
    const char ** suit_names = get_suit_names();

    printf("%s", card->name);
    putchar('\n');

    putchar('\t');
    printf("%s", suit_names[card->suit]);
    printf(" %d", card->value);
    putchar('\n');
}

void welcome()
{
    printf("%s to Ten Minute Heist\n", __func__);
}

void how_many_players()
{
    printf("%s?\n", __func__);
}