/* location.c */

#include "location.h"
#include "constants.h"


void to_index(location_t * location)
{
    char floor = location->floor;
    char room = location->room;

    int floor_number = (int) (floor - 'a') * TOWER_WIDTH;
    int room_number = (int) (room - '1');

    location->index = floor_number + room_number;
}


void to_floor_room(location_t * location)
{
    int index = location->index;

    location->floor = 'a' + (index / TOWER_WIDTH);
    location->room = '1' + (index % TOWER_WIDTH);
}