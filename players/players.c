/* players.c */

#include "players.h"
#include "game/game.h"

#include <stddef.h>


static player_t g_players[MAX_PLAYERS];

static inline void initialize_players();
static inline void initialize_suit_and_value_counts_to_zero();
static inline void initialize_hauls();
static inline void initialize_awards();

player_t * get_player_list()
{
    initialize_players();
    initialize_suit_and_value_counts_to_zero();
    initialize_hauls();
    initialize_awards();
    
    return (g_players);
}

static inline void initialize_awards()
{
    for (int player_count = 0; player_count < MAX_PLAYERS; ++player_count)
    {
        for(int tiles = 0; tiles < NUM_SCORING_TILES; ++tiles)
        {
            g_players[player_count].awards[tiles] = false;
        }
    }
}


static inline void initialize_players()
{
    for(int player_count = 0; player_count < MAX_PLAYERS; ++player_count)
    {
        g_players[player_count].num_curses = 0;
        g_players[player_count].exit_number = 0;
        g_players[player_count].cards_in_haul = 0;
        g_players[player_count].points = 0;

        g_players[player_count].in_tower = false;
        g_players[player_count].has_exited = false;
        g_players[player_count].is_you = false;
        g_players[player_count].first_card_revealed = false;
        
        g_players[player_count].player_number = player_count;

    }
    
}


static inline void initialize_suit_and_value_counts_to_zero()
{
    for (int player_count = 0; player_count < MAX_PLAYERS; ++player_count)
    {

        for (int suit_count = 0; suit_count < NUM_BASIC_SUITS; ++suit_count)
        {
            g_players[player_count].num_suits[suit_count] = 0;
        }

        for (int value_count = THREES; value_count <= FIVES; ++value_count)
        {
            g_players[player_count].num_values[value_count] = 0;
        }

    }

}

static inline void initialize_hauls()
{
    for(int player_count = 0; player_count < MAX_PLAYERS; ++player_count)
    {
        for(int haul_player_count = 0; haul_player_count < MAX_HAUL; ++haul_player_count)
        {
            g_players[player_count].haul[haul_player_count] = NULL;
        }
    }

}
