/* terminal_io.c */

#include "terminal_out.h"
#include "terminal_in.h"
#include "constants.h"
#include "scoring/scoring.h"
#include "cards/cards.h"
#include "location/location.h"

#include <stdio.h>


// Helper function prototypes
static void print_player(const player_t * player);
static void print_floor(const char floor);
static void print_awards(player_t * player);
static void print_winner(game_t * game);


// Function Definitions
void the_card_you_were_dealt(game_t * game)
{
    printf("The card you were dealt:\n   ");
    card_t * card = game->player_list[game->your_player_number].haul[0];
    print_a_card(card);
    putchar('\n');
    
}
void room_prompt()
{
    printf("(x to exit)  room? ");
}

void floor_prompt()
{
    printf("(x to exit) floor? ");
}

static void print_winner(game_t * game)
{
    int high_score = 0;
    int high_score_player = 0;

    player_t * players = game->player_list;

    for (int index = 0; index < game->num_players; ++index)
    {
        const int curr_score = players[index].points;
        if (curr_score > high_score)
        {
            high_score = curr_score;
            high_score_player = index;
        }
    }

    int players_at_score = 0;

    for (int index = 0; index < game->num_players; ++index)
    {
        const int curr_score = players[index].points;
        if (curr_score == high_score)
        {
            ++players_at_score;
        }
    }

    if (players_at_score > 1)
    {
        printf("a tie, nobody wins\n");
    }
    else
    {
        if(game->player_list[high_score_player].is_you)
        {
            printf("you win!\n");
        }
        else{
            printf("player %d wins!\n", high_score_player + 1);
        }
    }
    
}

void print_all_hauls(game_t * game)
{
    player_t * players = game->player_list;

    for (int index = 0; index < game->num_players; ++index)
    {
        putchar('\n');
        printf("The haul for ");
        print_player(&players[index]);
        for (int card_n = 0; card_n < players[index].cards_in_haul; ++card_n)
        {
            print_a_card(players[index].haul[card_n]);
        }
        putchar('\n');
    }
}

static void print_awards(player_t * player)
{
    const char * award_names[] = 
    {
        "MOST_POTIONS",
        "MOST_FOSSILS",
        "MOST_ARTIFACTS",
        "MOST_JEWELS",
        "MOST_TOMES",

        "MOST_THREES",
        "MOST_FOURS",
        "MOST_FIVES",

        "FIRST_EXIT",
        "SECOND_EXIT",
        "LAST_EXIT",

        "MOST_CURSES",
        "LEAST_CURSES",
    };

    int * points = get_points();

    for (int index = 0; index < NUM_SCORING_TILES; ++index)
    {
        if (player->awards[index] == true)
        {
            printf("\t%-14s ", award_names[index]);
            printf("%d", points[index]);
            putchar('\n');
        }
    }

    putchar('\n');
}

void print_score(game_t * game)
{
    printf("final score\n");

    player_t * players = game->player_list;
    for(int index = 0; index < game->num_players; ++index)
    {

        if (players[index].is_you ==  false)
        {
            printf("player %d's", index + 1);
        }
        else
        {
            printf( "      your");
        }

        printf(" points %d\n", players[index].points);
        print_awards(&players[index]);
    }

    print_winner(game);
}

void print_haul(game_t * game)
{
    printf("whose haul would you like to see? ");
    int player_number;
    scanf("%d", &player_number);

    printf("player %d's haul\n", player_number);

    const int player_index = player_number - 1;

    player_t * player = &game->player_list[player_index];

    printf("card 0) ");

    if (player->is_you)
    {
        print_a_card(player->haul[0]);
    }

    if (!player->is_you && player->first_card_revealed)
    {
        print_a_card(player->haul[0]);
    }

    if (!player->is_you && !player->first_card_revealed)
    {
        printf("????????\n");
        printf("\t?????? ?\n");
    }

    for (int index = 1; index < player->cards_in_haul; ++index)
    {
        printf("card %d) ", index);
        print_a_card(player->haul[index]);        
    }

    putchar('\n');
}

void you_are_player(game_t * game)
{
    for (int index = 0; index < game->num_players; ++index)
    {
        if (game->player_list[index].is_you)
        {
            printf("You are player %d,\n", 1 + index);
        }
    }
}

static void print_player(const player_t * player)
{
    const int player_number = player->player_number + 1;
    printf("player_%d", player_number);

    if (player->is_you)
    {
        printf(" (you)");
    }
    putchar('\n');
}

static void print_floor(const char floor)
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

    print_floor('b');

    for (int index = TOWER_WIDTH; index < TOWER_WIDTH * 2; ++index)
    {

        const int room_number = index + 1;
        printf("%d) ", (1 + room_number) % (TOWER_WIDTH + 1));

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

    putchar('\n');
}

void print_a_card(card_t * card)
{
    const char ** suit_names = get_suit_names();

    printf("%-9s", suit_names[card->suit]);
    printf("%d", card->value);
    printf(" %s", card->name);
    
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