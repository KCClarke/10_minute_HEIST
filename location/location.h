/* location.h */

#ifndef LOCATION_H
#define LOCATION_H

typedef struct location_s location_t;

struct location_s
{
    char floor;
    char room;
    int index; 
};

void to_index(location_t * location);
void to_floor_room(location_t * location);

#endif