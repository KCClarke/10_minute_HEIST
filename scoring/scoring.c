/* scoring.c */

#include "scoring.h"
#include "constants.h"

#include <assert.h>

int g_points[NUM_SCORING_TILES];

static inline int highest_num_suit(game_t * game, suit_t suit, int * player_index);
static inline bool tied(game_t * game, suit_t suit, int num);
static inline void score_suits(game_t * game);

static inline void score_values(game_t * game);


void score(game_t * game)
{
    (void) get_points();
    score_suits(game);

    score_values(game);
    
}

static inline void score_values(game_t * game)
{
    int most_of_value = 0;

    for (int player = 0; player < game->num_players; ++player)
    {
        int curr_num_values = game->player_list[player].num_threes;
        
        if (curr_num_values > most_of_value)
        {
            most_of_value = curr_num_values;
        }
    }

}

static inline void score_suits(game_t * game)
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
            is_tied = tied(game, suit, num);
        }

        if (!is_tied)
        {
            game->player_list[player_index].points += g_points[suit];
            game->player_list[player_index].awards[suit] = true;
        }
    }

}

static inline bool tied(game_t * game, suit_t suit, int num)
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

static inline int highest_num_suit(game_t * game, suit_t suit, int * player_index)
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

int * get_points()
{
    g_points[MOST_POTIONS]   = 3;
    g_points[MOST_FOSSILS]   = 4;
    g_points[MOST_ARTIFACTS] = 4;
    g_points[MOST_JEWELS]    = 5;
    g_points[MOST_TOMES]     = 6;

    g_points[MOST_THREES] = 3;
    g_points[MOST_FOURS]  = 4;
    g_points[MOST_FIVES]  = 5;

    g_points[FIRST_EXIT]  =  2;
    g_points[SECOND_EXIT] =  1;
    g_points[LAST_EXIT]   = -1;

    g_points[MOST_CURSES]  = -3;
    g_points[LEAST_CURSES] =  1;

    return (g_points);
}