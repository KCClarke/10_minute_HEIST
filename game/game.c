/* game.c */

#include "game.h"
#include "tower/tower.h"
#include "players/players.h"

static game_t g_game;

static inline void initialize_game();

game_t * get_game()
{
    initialize_game();

    return (&g_game);

}

static inline void initialize_game()
{
    g_game.num_players = 1;
    g_game.current_player = PLAYER_1;

    g_game.tower = get_tower();
}