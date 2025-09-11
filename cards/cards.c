/* cards.c */

#include "cards.h"

#include "powers.h"

#include <assert.h>

static card_t g_master_card_list[] = 
{
    {
        "Love Potion #8",
        3,
        POTION
    },
    {
        "Potion of Strength",
        4,
        POTION
    },
    {
        "Greater Potion of Healing",
        5,
        POTION
    },

    {
        "Sunstone Phoenix Feather",
        3,
        FOSSIL
    },
    {
        "Gibbon's Paw",
        4,
        FOSSIL
    },
    {
        "Dragon Skull",
        5,
        FOSSIL
    },

    {
        "Sprig of the Dawn Tree",
        3,
        ARTIFACT
    },
    {
        "The Angelic Compass",
        4,
        ARTIFACT
    },
    {
        "Silver Idol of Hun-Batz",
        5,
        ARTIFACT
    },

    {
        "The Eye of Vala",
        3,
        JEWEL
    },
    {
        "Heart of Eternity",
        4,
        JEWEL
    },
    {
        "Stone of the Kings",
        5,
        JEWEL
    },

    {
        "Orion's Bestiary",
        3,
        TOME
    },
    {
        "Flamel's Formulas",
        4,
        TOME
    },
    {
        "Book of Spells",
        5,
        TOME
    },

    {
        "Celestial Tarot",
        2,
        WILD,
        1 // curse.
    },
    {
        "Infernal Tarot",
        2,
        WILD,
        1 // curse.
    }

    /* The end of the list of light cards. */
    
};

static const int cards_written = sizeof(g_master_card_list) / sizeof(card_t);

static inline void non_curse_light_cards();
static inline void connect_basic_power();

const card_t * get_master_card_list()
{
    assert(17 == cards_written);

    non_curse_light_cards();
    connect_basic_power();

    return (g_master_card_list);

}

static inline void non_curse_light_cards()
{
    const int light_cards_without_curses = 15;

    for (int index = 0; index < light_cards_without_curses; ++ index)
    {
        g_master_card_list[0].curse = 0;
    }
    
}

static inline void connect_basic_power()
{
    for (int index = 0; index < LIGHT_CARDS; ++index)
    {
        g_master_card_list[index].power = basic_power;
    }

}