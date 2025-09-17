/* tower.c */

#include "tower.h"
#include "constants.h"

#include <stddef.h>


static room_t g_tower[TOTAL_ROOMS];

static inline void initialize_tower();

room_t * get_tower()
{
    initialize_tower();

    return(g_tower);
    
}

bool has_card_no_player(const room_t room)
{
    bool has_card = room.p_card != NULL;
    bool no_player = room.p_player == NULL;
    return (has_card && no_player);
}

static inline void initialize_tower()
{
    for (int index = 0; index < TOTAL_ROOMS; ++index)
    {
        g_tower[index].p_player = NULL;
        g_tower[index].p_card = NULL;
    }
    
}
