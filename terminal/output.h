/** @file output.h
 *
 * @brief A description of the module's purpose.
 *
 * @par
 * Written July 19 2025 Kasey Clarke
 */

#ifndef OUTPUT_H
#define OUTPUT_H

#include "game/game.h"
#include <stdbool.h>

void greeting();
void debug_greeting();
void print_sizing_row();
void print_instructions();
void prompt();
void print_tower(game_t * game);

#endif /* OUTPUT_H */

/*** end of file ***/