/* constants.h */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define MAX_PLAYERS 5
#define TOTAL_CARDS 57
#define MAX_HAUL TOTAL_CARDS
#define SCORING_TILES 13
#define TOWER_WIDTH 5
#define TOWER_HEIGHT 8

typedef enum
{
    POTION

} suit_t;

typedef enum
{
    PLAYER_1,
    PLAYER_2, 
    PLAYER_3,
    PLAYER_4,
    PLAYER_5

} player_ID_t;

#endif