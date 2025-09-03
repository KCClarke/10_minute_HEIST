/* players.c */

#include "players.h"

#include <stddef.h>


static player_t g_players[MAX_PLAYERS];

static inline void initialize_players();
static inline void initialize_hauls();

player_t * get_player_list()
{
    initialize_players();
    initialize_hauls();
    
    return (g_players);
}

static inline void initialize_players()
{
    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        g_players[index].num_threes = 0;
    }
}

static inline void initialize_hauls()
{
    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        for(int haul_index = 0; haul_index < MAX_HAUL; ++haul_index)
        {
            g_players[index].haul[haul_index] = NULL;
        }
    }
}

