/* cards.c */

#include "cards.h"

#include "powers.h"
#include "constants.h"

#include <stddef.h>

static card_t g_master_card_list[TOTAL_CARDS] = {};

static inline void initialize_default_card_properties();
static inline void initialize_light_cards();
static inline void initialize_light_card_values();
static inline void initialize_light_cards_curse();
static inline void initialize_light_card_suits();
static inline void connect_light_card_powers();
static inline void name_cards();

const card_t * get_master_card_list()
{
    initialize_default_card_properties();
    name_cards();
    initialize_light_cards();

    return (g_master_card_list);

}

const char * suit_names[] = 
{
    "potion",
    "fossil",
    "artifact",
    "jewel",
    "tome",
    "ERROR: 'NUM_BASIC_SUITS' sent",
    "wild"
};

const char ** get_suit_names()
{
    return (suit_names);
}

static inline void initialize_default_card_properties()
{
    for (int index = 0; index < TOTAL_CARDS; ++index)
    {
        g_master_card_list[index].name  = "";
        g_master_card_list[index].value = 0;
        g_master_card_list[index].suit  = NONE;
        g_master_card_list[index].curse = 0;
        g_master_card_list[index].power = NULL;
    }

}

static inline void name_cards()
{
    g_master_card_list[LOVE_POTION_8].name = 
        "Love Potion #8";
    g_master_card_list[POTION_OF_STRENGTH].name = 
        "Potion of Strength";
    g_master_card_list[GREATER_POTION_OF_HEALING].name = 
        "Greater Potion of Healing";
    
    g_master_card_list[SUNSTONE_PHOENIX_FEATHER].name = 
        "Sunstone Phoenix Feather";
    g_master_card_list[GIBBONS_PAW].name = 
        "Gibbon's Paw";
    g_master_card_list[DRAGON_SKULL].name = 
        "Dragon Skull";

    g_master_card_list[SPRIG_OF_THE_DAWN_TREE].name = 
        "Sprig of the Dawn Tree";
    g_master_card_list[THE_ANGELIC_COMPASS].name = 
        "The Angelic Compass";
    g_master_card_list[SILVER_IDOL_OF_HUN_BATZ].name = 
        "Silver Idol of Hun-Batz";

    g_master_card_list[THE_EYE_OF_VALA].name = 
        "The Eye of Vala";
    g_master_card_list[HEART_OF_ETERNITY].name = 
        "Heart of Eternity";
    g_master_card_list[STONE_OF_KINGS].name = 
        "Stone of Kings";

    g_master_card_list[ORIONS_BESTIARY].name = 
        "Orion's Bestiary";
    g_master_card_list[FLAMELS_FORMULAS].name = 
        "Flamel's Formulas";
    g_master_card_list[BOOK_OF_SPELLS].name = 
        "Book of Spells";

    g_master_card_list[CELESTIAL_TAROT].name = 
        "Celestial Tarot";
    g_master_card_list[INFERNAL_TAROT].name = 
        "Infernal Tarot";
    
        /* End of the light card list. */
    
}

static inline void initialize_light_cards()
{
    initialize_light_card_values();
    initialize_light_card_suits();
    initialize_light_cards_curse();
    connect_light_card_powers();
}

static inline void initialize_light_card_suits()
{
    const int non_wild_light_cards = 15;
    const int cards_per_suit = 3;

    for (int index = 0; index < non_wild_light_cards; ++index)
    {
        g_master_card_list[index].suit = POTION + (index / cards_per_suit);
    }

    g_master_card_list[CELESTIAL_TAROT].suit = WILD;
    g_master_card_list[INFERNAL_TAROT].suit  = WILD;

}

static inline void initialize_light_card_values()
{
    const int non_wild_light_cards = 15;
    const int values[] = {3, 4, 5};
    const int possible_values = 3;

    for (int index = 0; index < non_wild_light_cards; ++index)
    {
        g_master_card_list[index].value = values[index % possible_values];
    }

    g_master_card_list[CELESTIAL_TAROT].value = 2;
    g_master_card_list[INFERNAL_TAROT].value  = 2;

}

static inline void initialize_light_cards_curse()
{
    g_master_card_list[CELESTIAL_TAROT].curse = 1;
    g_master_card_list[INFERNAL_TAROT].curse  = 1;

}

static inline void connect_light_card_powers()
{
    const int non_wild_light_cards = 15;

    for (int index = 0; index < non_wild_light_cards; ++index)
    {
        g_master_card_list[index].power = basic_power;
    }

    g_master_card_list[CELESTIAL_TAROT].power = wild_power;
    g_master_card_list[INFERNAL_TAROT].power = wild_power;

}