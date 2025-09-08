/* cards.c */

#include "cards.h"

#include "powers.h"

static card_t g_master_card_list[] = 
{
    {
        "Love Potion #8",
        3,
        POTION,
    }
    
};


const card_t * get_master_card_list()
{
    g_master_card_list[0].power = basic_power;
    
    return (g_master_card_list);
}
