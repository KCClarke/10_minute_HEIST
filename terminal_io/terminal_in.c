/* terminal_in.c */

#include "terminal_in.h"
#include "terminal_out.h"
#include "game/game.h"

#include <stdio.h>

void get_turn_input(turn_t * turn)
{
    floor_prompt();
    char floor;
    scanf("%c", &floor);
    turn->location.floor = floor;
    getchar();

    room_prompt();
    char room;
    scanf("%c", &room);
    turn->location.room = room;
    getchar();

}

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