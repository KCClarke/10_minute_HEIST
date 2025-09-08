/* cards.h */

#ifndef CARDS_H
#define CARDS_H

#include "constants.h"

typedef struct game_s game_t;

typedef struct card_s
{
    char *   name;
    int      value;
    suit_t   suit;
    void (* power)(struct game_s *);
    
} card_t;

const card_t * get_master_card_list();

#endif