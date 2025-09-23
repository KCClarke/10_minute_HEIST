/* turn.c */

#include "turn.h"

#include "game/game.h"
#include "players/players.h"
#include "location/location.h"
#include <stddef.h>
#include <stdio.h>

void move_player(turn_t * turn, game_t * game)
{
    player_t * player = &game->player_list[game->current_player];
    room_t * tower = game->tower;

    if (player->in_tower)
    {
        location_t previous_player_location;
        previous_player_location.floor = player->location.floor;
        previous_player_location.room = player->location.room;
        to_index(&previous_player_location);
        // Remove the player from the previous room.
        tower[previous_player_location.index].p_player = NULL;
    }

    // Put them in the new room.
    tower[turn->location.index].p_player = player;
    player->location.floor = turn->location.floor;
    player->location.room = turn->location.room;
    
    player->in_tower = true;
}

void collect_card(turn_t * turn, game_t * game)
{
    const int index = turn->location.index;

    card_t * card = game->tower[index].p_card;
    player_t * player = &game->player_list[game->current_player];

    card->power(card, game);
    
    player->haul[player->cards_in_haul] = card;
    player->cards_in_haul++;

    game->tower[index].p_card = NULL;

}

void get_bot_turn(turn_t * turn, game_t * game)
{

    for (int index = 0; index < TOWER_WIDTH * TOWER_HEIGHT; ++index)
    {
        if (has_card_no_player(game->tower[index]))
        {
            turn->location.index = index;
            to_floor_room(&turn->location);
            turn->card_found = true;
            break;
        }
    }

    if (false == turn->card_found)
    {
        turn->exited = true;
    }

}

void initialize_turn(turn_t * turn)
{
    turn->card_found = false;
    turn->exited = false;
    turn->success = false;
}

void take_turn(turn_t * turn, game_t * game)
{
    turn->location.floor = 'a';
    turn->location.room = '1';
    turn->exited = false;

}

bool did_not_move_up(const location_t * location, const player_t * player)
{
    return (true);
}
