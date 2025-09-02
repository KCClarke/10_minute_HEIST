/* players.c */

#include "players.h"


static player_t g_players[MAX_PLAYERS];

static inline void initialize_players();

player_t * get_player_list()
{
    initialize_players();
    return (g_players);
}

static inline void initialize_players()
{
    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        g_players[index].num_threes = 0;
    }
}

