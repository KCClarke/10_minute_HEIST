/* scoring.c */

#include "scoring.h"
#include "constants.h"

#include <assert.h>
#include <stdio.h>

int g_points[NUM_SCORING_TILES];

static int highest_num_suit(game_t * game, suit_t suit, int * player_index);
static bool suit_tied(game_t * game, suit_t suit, int num);
static void score_suits(game_t * game);

static int highest_num_value(game_t * game, value_t value, int * player_index);
static bool value_tied(game_t * game, value_t value, int num);
static void score_values(game_t * game);

static int fewest_curses (game_t * game, int * player_index);
static int highest_curses(game_t * game, int * player_index);
static bool curse_tied(game_t * game, int curses);
static void least_curses(game_t * game);
static void score_curses(game_t * game);

static void first_exit(game_t * game);
static void other_exit(game_t * game);
static void score_exit(game_t * game);

static void determine_high_score(game_t *game);
static void determine_winner_or_tie(game_t * game);

void score(game_t * game)
{
    (void) get_points();
    
    score_suits (game);
    score_values(game);
    score_curses(game);
    score_exit(game);
    determine_high_score(game);
    determine_winner_or_tie(game);
    
}

static void determine_high_score(game_t * game)
{
    player_t * players = game->player_list;

    for (int index = 0; index < game->num_players; ++index)
    {
        const int curr_score = players[index].points;
        if (curr_score > game->high_score)
        {
            game->high_score = curr_score;
            game->a_high_score_player = index;
        }
    }
}

static void determine_winner_or_tie(game_t * game)
{
    int players_at_score = 0;
    player_t * players = game->player_list;

    for (int index = 0; index < game->num_players; ++index)
    {
        const int curr_score = players[index].points;
        if (curr_score == game->high_score)
        {
            ++players_at_score;
        }
    }

    if (players_at_score > 1)
    {
        game->tie_occured = true; 
    }
    else
    {
        game->winner = game->a_high_score_player;
    }
}

int * get_points()
{
    g_points[MOST_POTIONS]   = 3;
    g_points[MOST_FOSSILS]   = 4;
    g_points[MOST_ARTIFACTS] = 4;
    g_points[MOST_JEWELS]    = 5;
    g_points[MOST_TOMES]     = 6;

    g_points[MOST_THREES]    = 5;
    g_points[MOST_FOURS]     = 4;
    g_points[MOST_FIVES]     = 3;

    g_points[FIRST_EXIT]     = 2;
    g_points[SECOND_EXIT]    = 1;
    g_points[LAST_EXIT]      = -1;

    g_points[MOST_CURSES]    = -3;
    g_points[FEWEST_CURSES]  = 1;

    return (g_points);
}


static void score_exit(game_t * game)
{
    first_exit(game);
    if (game->num_players > 2)
    {
        other_exit(game);
    }
}

static void first_exit(game_t * game)
{
    player_t * players = game->player_list;

    for (int player = 0; player < game->num_players; ++player)
    {
        int exit_number = players[player].exit_number;

        if(1 == exit_number)
        {
            players[player].points += g_points[FIRST_EXIT];
            players[player].awards[FIRST_EXIT] = true;
            break;
        }
    }

}

static void other_exit(game_t * game)
{
    player_t * players = game->player_list;

    for (int player = 0; player < game->num_players; ++player)
    {
        int exit_number = players[player].exit_number;

        if(2 == exit_number)
        {
            players[player].points += g_points[SECOND_EXIT];
            players[player].awards[SECOND_EXIT] = true;
        }

        if(game->num_players == exit_number)
        {
            players[player].points += g_points[LAST_EXIT];
            players[player].awards[LAST_EXIT] = true;
        }
        
    }

}

static void score_curses(game_t * game)
{
    int player_index;
    int num_curses = highest_curses(game, &player_index);

    if (false == curse_tied(game, num_curses))
    {
        game->player_list[player_index].points += g_points[MOST_CURSES];
        game->player_list[player_index].awards[MOST_CURSES] = true;
    }

    if (game->num_players > 2)
    {
        least_curses(game);
    }

}

static void least_curses(game_t * game)
{
    int player_index;
    int num_curses = fewest_curses(game, &player_index);

    if (false == curse_tied(game, num_curses))
    {
        game->player_list[player_index].points += g_points[FEWEST_CURSES];
        game->player_list[player_index].awards[FEWEST_CURSES] = true;
    }

}

static bool curse_tied(game_t * game, int curses)
{
    player_t * players = game->player_list;
    int players_at_curses = 0;

    for (int player = 0; player < game->num_players;  ++player)
    {
        int curr_curses = players[player].num_curses;
        if (curses == curr_curses)
        {
            ++players_at_curses;
        }
    }

    return (players_at_curses > 1);
}

static int fewest_curses(game_t * game, int * player_index)
{
    player_t * players = game->player_list;
    int fewest_curses = 256;

    for (int player = 0; player < game->num_players; ++player)
    {
        int curr_curses = players[player].num_curses;

        if(curr_curses < fewest_curses)
        {
            fewest_curses = curr_curses;
            *player_index = player;
        }
    }

    return (fewest_curses);
}

static int highest_curses(game_t * game, int * player_index)
{
    player_t * players = game->player_list;
    int highest_curses = 0;

    for (int player = 0; player < game->num_players; ++player)
    {
        int curr_curses = players[player].num_curses;

        if(curr_curses > highest_curses)
        {
            highest_curses = curr_curses;
            *player_index = player;
        }
    }

    return (highest_curses);
}

static void score_values(game_t * game)
{

    int award_index = MOST_THREES;
    int player_index;

    for (int value = THREES; value <= FIVES; ++value)
    {
        int num = highest_num_value(game, value, &player_index);

        bool is_tied = true;
        if (num > 0)
        {
            is_tied = value_tied(game, value, num);
        }

        if (!is_tied)
        {
            game->player_list[player_index].points += g_points[award_index];
            game->player_list[player_index].awards[award_index] = true;
        }

        ++award_index;
    }


}

static void score_suits(game_t * game)
{
    suit_t first_suit = POTION;
    suit_t last_suit = TOME;
    int player_index;

    for (int suit = first_suit; suit <= last_suit; ++suit)
    {
        int num = highest_num_suit(game, suit, &player_index);

        bool is_tied = true;
        if (num > 0)
        {
            is_tied = suit_tied(game, suit, num);
        }

        if (!is_tied)
        {
            game->player_list[player_index].points += g_points[suit];
            game->player_list[player_index].awards[suit] = true;
        }
    }

}


static bool suit_tied(game_t * game, suit_t suit, int num)
{
    player_t * players = game->player_list;
    int players_at_score = 0;

    for (int player = 0; player < game->num_players; ++player)
    {
        if (players[player].num_suits[suit] == num)
        {
            ++players_at_score;
        }
    }

    return (players_at_score > 1);
}


static bool value_tied(game_t * game, value_t value, int num)
{
    player_t * players = game->player_list;
    int players_at_score = 0;

    for (int player = 0; player < game->num_players; ++player)
    {
        if (players[player].num_values[value] == num)
        {
            ++players_at_score;
        }
    }

    return (players_at_score > 1);
}

static int highest_num_suit(game_t * game, suit_t suit, int * player_index)
{
    player_t * players = game->player_list;
    int most_in_suit = 0;

    for (int player = 0; player < game->num_players; ++ player)
    {
        int curr_num = players[player].num_suits[suit];

        if (curr_num > most_in_suit)
        {
            most_in_suit = curr_num;
            *player_index = player;
        }
    }

    return (most_in_suit);
}


static int highest_num_value(game_t * game, value_t value, int * player_index)
{
    player_t * players = game->player_list;
    int most_in_value = 0;

    for (int player = 0; player < game->num_players; ++ player)
    {
        int curr_num = players[player].num_values[value];

        if (curr_num > most_in_value)
        {
            most_in_value = curr_num;
            *player_index = player;
        }
    }

    return (most_in_value);
}
