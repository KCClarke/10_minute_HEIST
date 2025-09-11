/* players.c */

#include "players.h"

#include <stddef.h>


static player_t g_players[MAX_PLAYERS];

static inline void initialize_value_counts();
static inline void initialize_suit_counts();
static inline void initialize_hauls();

player_t * get_player_list()
{
    initialize_value_counts();
    initialize_hauls();
    
    return (g_players);
}

static inline void initialize_suit_counts()
{
    for (int player_index = 0; player_index < MAX_PLAYERS; ++player_index)
    {
        for (int suit_index = 0; suit_index < NUM_BASIC_SUITS; ++suit_index)
        {
            g_players[player_index].num_suits[suit_index] = 0;
        }
    }

}

static inline void initialize_value_counts()
{
    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        g_players[index].num_threes = 0;
        g_players[index].num_fours  = 0;
        g_players[index].num_fives  = 0;
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

