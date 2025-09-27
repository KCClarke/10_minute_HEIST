/* terminal_io.c */

#include "terminal_out.h"

#include <stdio.h>


// Helper function prototypes
static inline void print_floor(const char floor);
static inline void print_player(const player_t * player);
static inline void print_floor(const char floor);


// Function Definitions
void you_are_player(game_t * game)
{
    for (int index = 0; index < game->num_players; ++index)
    {
        if (game->player_list[index].is_you)
        {
            printf("you are player %d\n", 1 + index);
        }
    }
}
static inline void print_player(const player_t * player)
{
    const int player_number = player->player_number + 1;
    printf("player_%d", player_number);

    if (player->is_you)
    {
        printf(" (you)");
    }

    putchar('\n');
}

static inline void print_floor(const char floor)
{
    const int floor_marker = 80;
    for (int index = 0; index < floor_marker; ++index)
    {
        putchar(floor);
    }
    putchar('\n');
}

void print_a_row_of_the_tower(const char floor, const room_t * tower)
{
    print_floor(floor);

    for (int index = 0; index < TOWER_WIDTH; ++index)
    {
        const int room_number = index + 1;
        printf("%d) ", room_number);

        card_t * card = tower[index].p_card;
        if(NULL != card)
        {
            print_a_card(card);
        }

        player_t * player = tower[index].p_player;
        if (NULL != player)
        {
            print_player(player);
        }

        if (NULL == player && NULL == card)
        {
            putchar('\n');
        }
    }
}

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