/*  terminal_out.h */

#ifndef TERMINAL_OUT_H
#define TERMINAL_OUT_H

#include "game/game.h"

void print_a_row_of_the_tower(const char floor, const room_t * tower);

void print_all_hauls(game_t * game);
void print_score(game_t * game);
void print_haul(game_t * game);
void you_are_player(game_t * game);

void print_a_card(card_t * card);

void welcome();
void how_many_players();
void floor_prompt();
void room_prompt();

#endif