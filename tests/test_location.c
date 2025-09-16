/* test_location.c */

#include "location/location.h"

#include <stdio.h>
#include <assert.h>
#include <stddef.h>

void test_to_index();
void test_to_floor_room();

void test_location()
{
    test_to_index();
    test_to_floor_room();

    printf("%s passed.\n", __func__);
}

void test_to_index()
{
    location_t location;

    // The first spot in the tower.
    location.floor = 'a';
    location.room = '1';
    to_index(&location);
    assert(0 == location.index);

    assert(0 == 'a' - 'a');
    assert(1 == 'b' - 'a');
    assert('a' < 'z');

    // The middle ish spot.
    location.floor = 'e';
    location.room = '5';
    to_index(&location);
    assert(24 == location.index);
    
    // The last spot in the tower.
    location.floor = 'h';
    location.room = '5';
    to_index(&location);
    assert(39 == location.index);

}

void test_to_floor_room()
{
    location_t location;
    
    location.index = 0;
    to_floor_room(&location);
    assert('a' == location.floor);
    assert('1' == location.room);

    location.index = 24;
    to_floor_room(&location);
    assert('e' == location.floor);
    assert('5' == location.room);

    location.index = 39;
    to_floor_room(&location);
    assert('h' == location.floor);
    assert('5' == location.room);
}