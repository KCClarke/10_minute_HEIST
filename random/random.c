/** @file random.c
 *
 * @brief A c file for generating non zero true random
 * numbers within a range of 0 to n.
 *
 * @par
 * Kasey Clarke June 25 2025
 */

#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// public function bodies
 /*!
  * @brief Seeds the random number generator.
  *
  * @param void
  *
  * @return void
  */
void
seed_random ()
{
  srand((unsigned int)(time(0)));
}

/*!
 * @brief A true random number generator that avoids the bias introduced
 * by using the modulo operator. For the purpose of this project
 * uint8_t is large enough.
 *
 * @param[in] range The range of random numbers possible from
 * 0 to (range - 1).
 *
 * @return a true random number.
 */
uint8_t
random_number (const uint8_t range)
{
  // Use division truncation to get the largest number div by range.
  const uint8_t rand_limit = (RAND_MAX / range) * range;
  uint8_t number = rand_limit;
  while (number >= rand_limit)
  {
    number = (uint8_t) rand(); // casting raw output from rand to our type.
  }
  return (number % range); //returns true random number
}

/*** end of file ***/