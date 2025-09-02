#ifndef CARDS_H
#define CARDS_H

typedef enum
{
    POTION

} suit_t;

typedef struct card_s
{
    char *   name;
    int      value;
    suit_t   suit;
    
} card_t;


#endif // CARDS_H