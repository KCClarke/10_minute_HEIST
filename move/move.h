/** @file move.h
 *
 * @brief Contains the public function for moving a player through the tower.
 *
 * @par
 * Written August 4 2025 Kasey Clarke
 */

#ifndef MOVE_H
#define MOVE_H

#include "game/game.h"
#include <stdbool.h>

bool is_move_valid();
void move(game_t * p_game); 

#endif /* MOVE_H */

/*** end of file ***/