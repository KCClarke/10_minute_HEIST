/* test_scoring.c */

#include "players/players.h"
#include "test_scoring.h"
#include "test_turn.h"
#include "constants.h"
#include "scoring/scoring.h"

#include <stddef.h>
#include <assert.h>
#include <stdio.h>

static inline void run_game_to_score();
static inline void test_point_values();

static inline void hard_coded_suit_tests();

void test_scoring()
{
    hard_coded_suit_tests();
    
    printf("passed %s.\n", __func__);
}

static inline void hard_coded_suit_tests()
{
    game_t * game = get_game();
    // We overwrite the card dealing from get_game() with the blank player list.
    // We want to hard code paramaters in the player to test the scoring.
    game->player_list = get_player_list();
    game->num_players = 5;

    player_t * players = game->player_list;

    players[PLAYER_1].num_suits[POTION] = 5;
    players[PLAYER_2].num_suits[FOSSIL] = 5;
    players[PLAYER_3].num_suits[ARTIFACT] = 5;
    players[PLAYER_4].num_suits[JEWEL] = 5;
    players[PLAYER_5].num_suits[TOME] = 5;

    score(game);

    assert(3 == players[PLAYER_1].points);
    assert(4 == players[PLAYER_2].points);
    assert(4 == players[PLAYER_3].points);
    assert(5 == players[PLAYER_4].points);
    assert(6 == players[PLAYER_5].points);


    // Test for a tie
    game->player_list = get_player_list();

    players[PLAYER_1].num_suits[POTION] = 5;
    players[PLAYER_2].num_suits[POTION] = 5;

    score(game);

    assert(0 == players[PLAYER_1].points);
    assert(0 == players[PLAYER_1].points);
    
}

static inline void test_point_values()
{
    assert(13 == NUM_SCORING_TILES);
    
    int * points = get_points();
    assert(NULL != points);

    assert(3 == points[MOST_POTIONS]);
    assert(6 == points[MOST_TOMES]);
    assert(3 == points[MOST_THREES]);
    assert(5 == points[MOST_FIVES]);
    assert(2 == points[FIRST_EXIT]);
    assert(-1 == points[MOST_CURSES]);
}

static inline void run_game_to_score()
{
    
}