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

static inline game_t * blank_slate_setup();

static inline void hard_coded_curse_tests();
static inline void hard_coded_suit_tests();
static inline void hard_codes_value_tests();

void test_scoring()
{
    hard_coded_suit_tests();
    hard_codes_value_tests();
    hard_coded_suit_tests();
    hard_coded_curse_tests();
    
    printf("passed %s.\n", __func__);
}

static inline void hard_coded_curse_tests()
{
    game_t * game = blank_slate_setup();
    player_t * players = game->player_list;

    // Set up ties for most and least curses
    players[PLAYER_1].num_curses = 1;
    players[PLAYER_2].num_curses = 2;
    players[PLAYER_3].num_curses = 2;
    players[PLAYER_4].num_curses = 0;
    players[PLAYER_5].num_curses = 0;

    score(game);

    assert(0 == players[PLAYER_1].points);
    assert(0 == players[PLAYER_2].points);
    assert(0 == players[PLAYER_3].points);
    assert(0 == players[PLAYER_4].points);
    assert(0 == players[PLAYER_5].points);

    assert(false == players[PLAYER_1].awards[MOST_CURSES]);
    assert(false == players[PLAYER_2].awards[MOST_CURSES]);
    assert(false == players[PLAYER_3].awards[MOST_CURSES]);
    assert(false == players[PLAYER_4].awards[MOST_CURSES]);
    assert(false == players[PLAYER_5].awards[MOST_CURSES]);

    assert(false == players[PLAYER_1].awards[LEAST_CURSES]);
    assert(false == players[PLAYER_2].awards[LEAST_CURSES]);
    assert(false == players[PLAYER_3].awards[LEAST_CURSES]);
    assert(false == players[PLAYER_4].awards[LEAST_CURSES]);
    assert(false == players[PLAYER_5].awards[LEAST_CURSES]);
    // Assert nothing happened

    // Reset game
    game = blank_slate_setup();
    players[PLAYER_1].num_curses = 1;
    players[PLAYER_2].num_curses = 2;
    players[PLAYER_3].num_curses = 3;
    players[PLAYER_4].num_curses = 4;
    players[PLAYER_5].num_curses = 5;

    assert(0 == players[PLAYER_1].points);
    assert(0 == players[PLAYER_5].points);

    score(game);

    assert(-3 == players[PLAYER_5].points);
    assert(true == players[PLAYER_5].awards[MOST_CURSES]);

    assert(1 == players[PLAYER_1].points);
    assert(true == players[PLAYER_1].awards[LEAST_CURSES]);

}

static inline game_t * blank_slate_setup()
{
    game_t * game = get_game();
    // We overwrite the card dealing from get_game() with the blank player list.
    // We want to hard code paramaters in the player to test the scoring.
    game->player_list = get_player_list();
    game->num_players = 5;

    return (game);

}

static inline void hard_codes_value_tests()
{
    game_t * game = blank_slate_setup();

    player_t * players = game->player_list;

    players[PLAYER_1].num_values[THREES] = 1;
    players[PLAYER_2].num_values[THREES] = 2;
    players[PLAYER_3].num_values[THREES] = 2;
    players[PLAYER_4].num_values[FOURS] = 3;
    players[PLAYER_5].num_values[FIVES] = 4;

    score(game);

    assert(0 == players[PLAYER_1].points);
    assert(false == players[PLAYER_1].awards[MOST_THREES]);

    assert(0 == players[PLAYER_2].points);
    assert(false == players[PLAYER_2].awards[MOST_THREES]);

    assert(0 == players[PLAYER_3].points);
    assert(false == players[PLAYER_3].awards[MOST_THREES]);

    assert(4 == players[PLAYER_4].points);
    assert(true == players[PLAYER_4].awards[MOST_FOURS]);

    assert(3 == players[PLAYER_5].points);
    assert(true == players[PLAYER_5].awards[MOST_FIVES]);
}

static inline void hard_coded_suit_tests()
{
    game_t * game = blank_slate_setup();
    player_t * players = game->player_list;

    players[PLAYER_1].num_suits[POTION] = 5;
    players[PLAYER_2].num_suits[FOSSIL] = 5;
    players[PLAYER_3].num_suits[ARTIFACT] = 5;
    players[PLAYER_4].num_suits[JEWEL] = 5;
    players[PLAYER_5].num_suits[TOME] = 5;

    score(game);

    assert(3 == players[PLAYER_1].points);
    assert(true == players[PLAYER_1].awards[MOST_POTIONS]);

    assert(4 == players[PLAYER_2].points);
    assert(true == players[PLAYER_2].awards[MOST_FOSSILS]);

    assert(4 == players[PLAYER_3].points);
    assert(true == players[PLAYER_3].awards[MOST_ARTIFACTS]);
    
    assert(5 == players[PLAYER_4].points);
    assert(true == players[PLAYER_4].awards[MOST_JEWELS]);

    assert(6 == players[PLAYER_5].points);
    assert(true == players[PLAYER_5].awards[MOST_TOMES]);


    // Test for a tie.
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