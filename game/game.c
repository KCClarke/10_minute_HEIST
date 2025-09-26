/* game.c */

#include "game.h"
#include "tower/tower.h"
#include "players/players.h"
#include "random/random.h"
#include "cards/cards.h"
#include "constants.h"

#include <assert.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#define NUM_PLAYERS 3

static game_t g_game;

static bool g_dealt[TOTAL_CARDS];

typedef struct card_range_s
{
    card_index_t from;
    card_index_t to;

} card_range_t;

static const card_range_t 
light_card_range = {.from = LOVE_POTION_8, .to = INFERNAL_TAROT};


// Private function prototypes
static inline void initialize_players();
static inline void initialize_dealt();
static inline void deal_to_players(const card_t * card_list);
static inline void deal_to_first_floor(const card_t * card_list);

static inline card_t * 
get_card(const card_t * card_list, const card_range_t range);

static inline int 
get_undealt_card_index(const card_index_t first, const card_index_t last);


// Public function definitions.
game_t * get_game()
{
    initialize_players();
    initialize_dealt();

    g_game.tower = get_tower();

    const card_t * card_list = get_master_card_list();
    deal_to_players(card_list);
    deal_to_first_floor(card_list);

    g_game.players_exited = 0;

    return (&g_game);

}

void exit_player()
{
    g_game.players_exited++;
    const int exit_number = g_game.players_exited;

    g_game.player_list[g_game.current_player].exit_number = exit_number;
    g_game.player_list[g_game.current_player].has_exited = true;

    to_index(&g_game.player_list[g_game.current_player].location);
    const int index = g_game.player_list[g_game.current_player].location.index;

    g_game.tower[index].p_player = NULL;
    
}

void next_player()
{
    g_game.current_player++;
    g_game.current_player %= g_game.num_players;
}

bool game_running()
{
    return (g_game.num_players != (g_game.players_exited));
}

// Private function definitions.
static inline void deal_to_first_floor(const card_t * card_list)
{
    for (int tower_index = 0; tower_index < TOWER_WIDTH; ++tower_index)
    {
        card_t * card = get_card(card_list, light_card_range);
        g_game.tower[tower_index].p_card = card;
        
    }

}


static inline void deal_to_players(const card_t * card_list)
{
    for (int player_index = 0; player_index < g_game.num_players; ++player_index)
    {
        card_t * card = get_card(card_list, light_card_range);
        
        g_game.player_list[player_index].haul[0] = card;
        card->power(card, &g_game);
        g_game.player_list[player_index].cards_in_haul = 1;
        g_game.current_player++;

    }
    
    g_game.current_player = 0;

}

static inline card_t * get_card(const card_t * card_list, card_range_t range)
{
    const int card_index = get_undealt_card_index(range.from, 1 + range.to);
    
    // We cast off the const qualifier from the master list.
    card_t * p_card = (card_t *) &card_list[card_index];

    return (p_card);

}

static inline int 
get_undealt_card_index(const card_index_t first, const card_index_t last)
{
    int card_index;

    for(;;)
    {
        card_index = first + random_number(last);

        if (!g_dealt[card_index])
        {
            g_dealt[card_index] = true;
            break;

        }
        
    }

    return (card_index);

}

static inline void initialize_players()
{
    g_game.num_players = NUM_PLAYERS;
    g_game.current_player = PLAYER_1;
    g_game.player_list = get_player_list();

}

static inline void initialize_dealt()
{
    for (int index = 0; index < TOTAL_CARDS; ++index)
    {
        g_dealt[index] = false;
    }
}