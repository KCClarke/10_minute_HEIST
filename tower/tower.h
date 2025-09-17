/* tower.h */

#ifndef TOWER_H
#define TOWER_H

#include "cards/cards.h"
#include "players/players.h"

typedef struct room_s room_t;

struct room_s{
    card_t * p_card;
    player_t * p_player;

};

room_t * get_tower();
bool has_card_no_player(const room_t room);

#endif
