/* powers.c */

#include "powers.h"

#include "game/game.h"

#include <stdio.h>

void basic_power(const card_t * card, game_t * game)
{
    const int curr_player = game->current_player;
    
    game->player_list[curr_player].num_threes++;

}