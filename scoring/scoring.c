/* scoring.c */

#include "scoring.h"
#include "constants.h"

int g_points[NUM_SCORING_TILES];

int * get_points()
{
    g_points[MOST_POTIONS]   = 3;
    g_points[MOST_FOSSILS]   = 4;
    g_points[MOST_ARTIFACTS] = 4;
    g_points[MOST_JEWELS]    = 5;
    g_points[MOST_TOMES]     = 6;

    g_points[MOST_THREES] = 3;
    g_points[MOST_FOURS]  = 4;
    g_points[MOST_FIVES]  = 5;

    g_points[FIRST_EXIT]  =  2;
    g_points[SECOND_EXIT] =  1;
    g_points[LAST_EXIT]   = -1;

    g_points[MOST_CURSES]  = -3;
    g_points[LEAST_CURSES] =  1;

    return (g_points);
}