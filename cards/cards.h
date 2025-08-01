/** @file cards.h
 *
 * @brief This file describes the cards, and the concepts that define them.
 *
 * @par
 * Written July 20 2025 Kasey Clarke
 */

#ifndef CARD_DEFINITIONS_H
#define CARD_DEFINITIONS_H

#include <stdint.h>

#define TOTAL_CARDS 57

typedef enum
{
    potion,
    fossil,
    artifact,
    jewel,
    tome,
    wild,
    no_suit

} suit_t;

typedef enum
{
    crescent,
    full,
    no_set

} set_t;

typedef enum
{
    light,
    dark

} back_t;

typedef struct
{
    char*   name;
    uint8_t value;
    suit_t  suit;
    uint8_t curse;
    set_t   set;
    char*   power;
    back_t  back;
    
} card_t;

#endif /* CARD_DEFINITIONS_H */

/*** end of file ***/