/* terminal_io.c 
 *
 * Reviewed Feb 2
*/


#include "terminal_out.h"
#include "terminal_in.h"
#include "constants.h"
#include "scoring/scoring.h"
#include "cards/cards.h"
#include "location/location.h"
#include <stdio.h>


static void print_player(const player_t * player);
static void print_player_haul_one_line(const player_t * player);
static void print_card_suit_and_value(card_t * card);
static void print_awards(player_t * player);
static void print_winner(game_t * game);
static void print_floor_name_and_seperator(const char floor_name);
static void print_rooms_of_the_floor(const int floor_count, game_t * game);
static void print_the_contentents_of_a_room(const int tower_index, game_t * game);


void print_tower(game_t * game)
{
    const int floors = 2;
    for (int floor = 0; floor < floors; ++floor)
    {
        print_floor_name_and_seperator('a' + floor);
        print_rooms_of_the_floor(floor, game);
    }
    print_floor_name_and_seperator('-');
}

static void print_rooms_of_the_floor(const int floor, game_t * game)
{
    for (int room = 0; room < TOWER_WIDTH; ++room)
    {
        printf("%d)", room + 1);
        const int tower_index = floor * TOWER_WIDTH + room;
        print_the_contentents_of_a_room(tower_index, game);
        putchar('\n');
    }
}


static void print_the_contentents_of_a_room(const int index, game_t * game)
{
    room_t room = game->tower[index];

    if(NULL != room.p_card)
    {
        print_card_suit_and_value(room.p_card);
    }

    if (NULL != room.p_player)
    {
        print_player(room.p_player);
        print_player_haul_one_line(room.p_player);
    }
}


static void print_floor_name_and_seperator(const char floor_name)
{
    putchar(floor_name);
    const int num_dashes = 40;
    for (int index = 0; index < num_dashes; ++index)
    {
        putchar('-');
    }
    putchar('\n');
}


void print_player_haul_one_line(const player_t * player)
{
    for(int count = 0; count < 26; ++count)
    {
        putchar(' ');
    }

    if (player->is_you)
    {
        print_card_suit_and_value(player->haul[0]);
    }
    else
    {
        printf(" ???????? ?");
    }

    for (int index = 1; index < player->cards_in_haul; ++index)
    {
        print_card_suit_and_value(player->haul[index]);
    }
}


void print_card_suit_and_value(card_t * card)
{
    const char ** suit_names = get_suit_names();
    printf(" %-9s", suit_names[card->suit]);
    printf("%d", card->value);
}


void print_all_hauls(game_t * game)
{
    player_t * players = game->player_list;

    putchar('\n');

    for (int index = 0; index < game->num_players; ++index)
    {
        
        printf("\n Haul: ");
        print_player(&players[index]);
        putchar('\n');
        for (int card_n = 0; card_n < players[index].cards_in_haul; ++card_n)
        {
            card_t * p_card = players[index].haul[card_n];
            print_card_suit_and_value(p_card);
            printf(" %s\n", p_card->name);
        }
        
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
        "FEWEST_CURSES",
    };

    const int * points = get_points();

    for (int index = 0; index < NUM_SCORING_TILES; ++index)
    {
        if (player->awards[index])
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
    printf("\n Final score:\n");

    player_t * players = game->player_list;
    for(int index = 0; index < game->num_players; ++index)
    {
        printf("%d points ", players[index].points);
        print_player(&players[index]);
        putchar('\n');
        print_awards(&players[index]);

    }

    print_winner(game);
}


void you_are_player(game_t * game)
{
    printf(" There are %d players ", NUM_PLAYERS);
    for (int index = 0; index < game->num_players; ++index)
    {
        if (game->player_list[index].is_you)
        {
            printf("you are player %d ", 1 + index);
        }
    }
}


static void print_player(const player_t * player)
{
    const int player_number = player->player_number + 1;
    printf("player_%d ", player_number);
    if (player->is_you)
    {
        printf(" (you) ");
    }
    else
    {
        printf("       ");
    }
}


void the_card_you_were_dealt(game_t * game)
{
    printf("\n                  In your haul you have the: ");
    card_t * card = game->player_list[game->your_player_number].haul[0];
    print_card_suit_and_value(card);
    printf(" %s\n", card->name);   
}


static void print_winner(game_t * game)
{
    if (game->tie_occured)
    {
        printf("a tie, nobody wins\n");
    }
    else
    {
        if(game->player_list[game->winner].is_you)
        {
            printf("You win!\n");
        }
        else{
            printf("Player %d wins.\n", game->winner + 1);
        }
    }
}
