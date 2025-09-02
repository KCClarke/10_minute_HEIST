/* master_card_list.c */

#include "cards.h"

static card_t g_master_card_list[] = 
{
    {
        "Love Potion #8",
        3,
        POTION
    }
};

card_t * get_master_card_list()
{
    return (g_master_card_list);
}
