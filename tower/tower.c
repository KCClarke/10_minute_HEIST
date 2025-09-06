/* tower.c */

#include "tower.h"
#include "constants.h"

static room_t g_tower[TOTAL_ROOMS];

static inline void initialize_tower();

room_t * get_tower()
{
    initialize_tower();

    return(g_tower);
}


static inline void initialize_tower()
{

}