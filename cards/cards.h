/* cards.h */

#ifndef CARDS_H
#define CARDS_H

#include "constants.h"

typedef struct card_s
{
    char *   name;
    int      value;
    suit_t   suit;
    
} card_t;

const card_t * get_master_card_list();

#endif