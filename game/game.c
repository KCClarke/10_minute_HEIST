/* game.c */

#include "game.h"

static game_t g_game;

static inline void initialize_game();

game_t * get_game()
{
    return (&g_game);
}

static inline void initialize_game()
{
    g_game.num_players = 1;
    g_game.current_player = PLAYER_1;
}