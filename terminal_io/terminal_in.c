/* terminal_in.c */

#include "terminal_in.h"
#include "game/game.h"

#include <stdio.h>

int get_player_number()
{
    int player_number;
    scanf("%d", &player_number);
    
    return (player_number);

}

void get_num_players(game_t * game)
{
    int num_players = 5;

    game->num_players = num_players;
}