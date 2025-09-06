/* tower.h */

#ifndef TOWER_H
#define TOWER_H

// Forward declared structs.
typedef struct card_s card_t;
typedef struct player_s player_t;

typedef struct room_s
{
    card_t * p_card;
    player_t * p_player;

} room_t;

room_t * get_tower();

#endif
