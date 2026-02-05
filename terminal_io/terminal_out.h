/*  terminal_out.h */

#ifndef TERMINAL_OUT_H
#define TERMINAL_OUT_H

#include "game/game.h"

void print_all_hauls(game_t * game);
void print_score(game_t * game);
void you_are_player(game_t * game);
void the_card_you_were_dealt(game_t * game);
void print_tower(game_t * game);
void TUI_start(game_t * game);

#endif