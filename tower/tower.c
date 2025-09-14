/* tower.c */

#include "tower.h"
#include "constants.h"

#include <stddef.h>


static room_t g_tower[TOTAL_ROOMS];

static inline void put_cards_in_tower();
static inline void initialize_tower();


room_t * get_tower()
{
    initialize_tower();

    return(g_tower);
    
}


static inline void initialize_tower()
{
    put_cards_in_tower();

    for (int index = 0; index < TOTAL_ROOMS; ++index)
    {
        g_tower[index].p_player = NULL;
    }
    
}

static inline void put_cards_in_tower()
{
    const card_t * master_card_list = get_master_card_list();

    for (int index = 0; index < NUM_LIGHT_CARDS; ++index)
    {
        const card_t * card = &master_card_list[index];

        g_tower[index].p_card = (card_t *) card;
    }
    
}