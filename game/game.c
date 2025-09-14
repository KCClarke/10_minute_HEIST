/* game.c */

#include "game.h"
#include "tower/tower.h"
#include "players/players.h"
#include "random/random.h"
#include "constants.h"

#include <assert.h>
#include <stddef.h>
#include <stdbool.h>

static game_t g_game;

static bool g_dealt[TOTAL_CARDS] = {false};

static inline void initialize_players();
static inline void deal_to_players(const card_t * card_list);

game_t * get_game()
{
    initialize_players();

    const card_t * card_list = get_master_card_list();
    deal_to_players(card_list);

    return (&g_game);

}


static inline void deal_to_players(const card_t * card_list)
{
    for (int player_index = 0; player_index < g_game.num_players; ++player_index)
    {

        int card_index;

        for(;;)
        {
            card_index = random_number(NUM_LIGHT_CARDS);

            if (false == g_dealt[card_index])
            {                
                break;
            }
        
        }
        
        // We cast off the const qualifier to copy into the haul.
        card_t * p_card = (card_t *) &card_list[card_index];

        g_game.player_list[player_index].haul[0] = p_card;
        
    }

}

static inline void initialize_players()
{
    g_game.num_players = 5;
    g_game.current_player = PLAYER_1;
    g_game.player_list = get_player_list();

}