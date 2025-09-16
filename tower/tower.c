/* tower.c */

#include "tower.h"
#include "constants.h"
#include "random/random.h"

#include <stddef.h>


static room_t g_tower[TOTAL_ROOMS];

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
    
}
