/* constants.h */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NUM_PLAYERS 2

#define NUM_LIGHT_CARDS 17
#define TOTAL_CARDS 57
#define MAX_HAUL TOTAL_CARDS
#define TOWER_WIDTH 5
#define TOWER_HEIGHT 8
#define TOTAL_ROOMS TOWER_HEIGHT * TOWER_WIDTH

typedef enum
{
    MOST_POTIONS,
    MOST_FOSSILS,
    MOST_ARTIFACTS,
    MOST_JEWELS,
    MOST_TOMES,

    MOST_THREES,
    MOST_FOURS,
    MOST_FIVES,

    FIRST_EXIT,
    SECOND_EXIT,
    LAST_EXIT,

    MOST_CURSES,
    LEAST_CURSES,

    NUM_SCORING_TILES

} score_t;

typedef enum
{
    POTION,
    FOSSIL,
    ARTIFACT,
    JEWEL,
    TOME,

    NUM_BASIC_SUITS,
    WILD,
    NONE

} suit_t;

typedef enum
{
    THREES, 
    FOURS,
    FIVES,
    NUM_VALUES
    
} value_t;

typedef enum
{
    LOVE_POTION_8,
    POTION_OF_STRENGTH,
    GREATER_POTION_OF_HEALING,

    SUNSTONE_PHOENIX_FEATHER,
    GIBBONS_PAW,
    DRAGON_SKULL,

    SPRIG_OF_THE_DAWN_TREE,
    THE_ANGELIC_COMPASS,
    SILVER_IDOL_OF_HUN_BATZ,

    THE_EYE_OF_VALA,
    HEART_OF_ETERNITY,
    STONE_OF_KINGS,

    ORIONS_BESTIARY,
    FLAMELS_FORMULAS,
    BOOK_OF_SPELLS,

    CELESTIAL_TAROT,
    INFERNAL_TAROT,

    /* The end of the list of light cards. */

} card_index_t;

typedef enum
{
    PLAYER_1,
    PLAYER_2, 
    PLAYER_3,
    PLAYER_4,
    PLAYER_5,

    MAX_PLAYERS

} player_ID_t;

#endif