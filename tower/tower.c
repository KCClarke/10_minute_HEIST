/* tower.c */

#include "tower.h"
#include "constants.h"

#include <stddef.h>


static room_t g_tower[TOTAL_ROOMS];

static inline void put_love_potion_in_tower();
static inline void initialize_tower();

room_t * get_tower()
{
    initialize_tower();

    return(g_tower);
}


static inline void initialize_tower()
{
    for (int index = 0; index < TOTAL_ROOMS; ++index)
    {
        g_tower[index].p_player = NULL;
        g_tower[index].p_card = NULL;
    }

    put_love_potion_in_tower();
}

static inline void put_love_potion_in_tower()
{
    const card_t * master_card_list = get_master_card_list();
    const card_t * love_potion = &master_card_list[0];

    g_tower[0].p_card = (card_t *) love_potion;
    
}