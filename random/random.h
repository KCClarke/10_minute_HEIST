/** @file random.h
 *
 * @brief The header for random.c
 *
 * @par
 * Kasey Clarke June 25 2025
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

void seed_random();
uint8_t random_number(const uint8_t range);

 #endif /* RANDOM_H */

 /*** end of file ***/