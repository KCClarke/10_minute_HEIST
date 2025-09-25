/* players.c */

#include "players.h"
#include "game/game.h"

#include <stddef.h>


static player_t g_players[MAX_PLAYERS];

static inline void initialize_players();
static inline void initialize_suit_counts();
static inline void initialize_value_counts();
static inline void initialize_hauls();
static inline void initialize_awards();

player_t * get_player_list()
{
    initialize_players();
    initialize_suit_counts();
    initialize_value_counts();
    initialize_hauls();
    initialize_awards();
    
    return (g_players);
}

static inline void initialize_awards()
{
    for (int index = 0; index < MAX_PLAYERS; ++index)
    {
        for(int tiles = 0; tiles < NUM_SCORING_TILES; ++tiles)
        {
            g_players[index].awards[tiles] = false;
        }
    }
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
    for (int player_index = 0; player_index < MAX_PLAYERS; ++player_index)
    {
        for (int value = THREES; value <= FIVES; ++value)
        {
            g_players[player_index].num_values[value] = 0;
        }
    }

}

static inline void initialize_players()
{
    for(int index = 0; index < MAX_PLAYERS; ++index)
    {
        g_players[index].num_curses = 0;
        g_players[index].exit_number = 0;
        g_players[index].cards_in_haul = 0;
        g_players[index].points = 0;
        g_players[index].in_tower = false;
        g_players[index].has_exited = false;
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
