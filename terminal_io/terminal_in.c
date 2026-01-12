/* terminal_in.c */

#include "terminal_in.h"
#include "terminal_out.h"
#include "game/game.h"

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

static char get_floor();
static bool valid_floor(const char input);

/* checks if the player entered a valid floor or x for exit*/
static bool valid_floor(const char input)
{
    bool valid_floor = false;

    for (int index = 0; index < TOWER_HEIGHT; ++index)
    {
        if ('a' + index == input)
        {
            printf("truuuuuue\n");
            valid_floor = true;
            break;
        }
        printf("false\n");
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

        if('\n' == input)
        {
        }
        else
        {
            while(getchar() != '\n') {};
        }

    }

    return(input);
}

void get_turn_input(turn_t * turn)
{
    char floor = get_floor();
    turn->location.floor = floor;

    room_prompt();
    char room;
    scanf("%c", &room);
    turn->location.room = room;
    getchar();

}

int get_player_number()
{
    int player_number;
    scanf("%d", &player_number);
    
    return(player_number);

}

