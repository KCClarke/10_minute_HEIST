/* test_turn.h */

#ifndef TEST_TURN_H
#define TEST_TURN_H

#include "game/game.h"

game_t * mock_game();
void print_mock_game(const game_t *);

void test_turn();

#endif