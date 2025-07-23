/** @file card_definitions.h
 *
 * @brief This file describes the cards, and the concepts that define them.
 *
 * @par
 * Written July 20 2025 Kasey Clarke
 */

#ifndef CARD_DEFINITIONS_H
#define CARD_DEFINITIONS_H

#define MAX_NAME_LENGTH 27

typedef enum
{
    potion,
    fossil,
    artifact,
    jewel,
    tome,
    wild,
    none
} suit_t;

typedef enum
{
    full_moon,
    crescent_moon,
    none
} special_set_t;


#endif /* CARD_DEFINITIONS_H */

/*** end of file ***/