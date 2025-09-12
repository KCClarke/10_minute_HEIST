/* powers.c */

#include "powers.h"

#include "constants.h"
#include "game/game.h"

#include <stdio.h>

static inline void update_player_suits(const card_t * card, game_t * game);
static inline void update_player_values(const card_t * card, game_t * game);

void basic_power(const card_t * card, game_t * game)
{
    update_player_values(card, game);
    update_player_suits(card, game);

}

void wild_power(const card_t * card, game_t * game)
{
    player_t * player_list = game->player_list;
    const int curr = game->current_player;

    // All wilds are cursed.
    player_list[curr].num_curses += card->curse;

    for (int index = 0; index < NUM_BASIC_SUITS; ++index)
    {
        player_list[curr].num_suits[index] += card->value;
    }
    
}

static inline void update_player_values(const card_t * card, game_t * game)
{
    const int index = game->current_player;
    player_t * player_list = game->player_list;

    switch (card->value)
    {
        case 3:
        player_list[index].num_threes++;
        break;

        case 4:
        player_list[index].num_fours++;
        break;

        case 5:
        player_list[index].num_fives++;
        break;

        default:
        break;

    }

}

static inline void update_player_suits(const card_t * card, game_t * game)
{
    const int index = game->current_player;
    player_t * player_list = game->player_list;
    
    player_list[index].num_suits[card->suit] +=card->value;

}
