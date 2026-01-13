/* terminal_in.c */

#include "terminal_in.h"
#include "terminal_out.h"
#include "game/game.h"

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

static char get_floor();
static char get_room();
static bool valid_floor(const char input);
static bool valid_room(const char input);


/* checks if the player entered a valid room or x for exit*/
static bool valid_room(const char input)
{
    bool valid_room = false;

    for (int index = 0; index < TOWER_WIDTH; ++index)
    {
        if ('1' + index == input)
        {
            valid_room = true;
            break;
        }
    }

    if ('x' == input)
    {
        valid_room = true;
    }

    return (valid_room);
}


/* checks if the player entered a valid floor or x for exit*/
static bool valid_floor(const char input)
{
    bool valid_floor = false;

    for (int index = 0; index < TOWER_HEIGHT; ++index)
    {
        if ('a' + index == input)
        {
            valid_floor = true;
            break;
        }
    }

    if ('x' == input)
    {
        valid_floor = true;
    }

    return (valid_floor);
}

static char get_floor()
{
    char input;
    for(;;)
    {
        floor_prompt();

        input = tolower(getchar());

        if(valid_floor(input))
        {
            break;
        }
        while(getchar() != '\n') {/* clear buffer */};    
    }

    while(getchar() != '\n') {/* clear buffer */};

    return(input);
}

static char get_room()
{
    char input;
    for(;;)
    {
        room_prompt();

        input = tolower(getchar());

        if(valid_room(input))
        {
            break;
        }
        while(getchar() != '\n') {/* clear buffer */};
    }

    while(getchar() != '\n') {/* clear buffer */};

    return(input);
}

void get_turn_input(turn_t * turn)
{
    char floor = get_floor();
    turn->location.floor = floor;

    char room = get_room();
    turn->location.room = room;

}

int get_player_number()
{
    int player_number;
    scanf("%d", &player_number);
    
    return(player_number);

}

