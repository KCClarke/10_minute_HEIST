/* terminal_in.c */

#include "terminal_in.h"
#include "terminal_out.h"
#include "game/game.h"

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


static char get_input();
static bool is_room(const char input);
static bool is_floor_or_exit(const char input);

void press_enter()
{
    printf("(press enter)\n");
    while(getchar() != '\n') {/* clear buffer */};
    
}

static bool is_floor_or_exit(const char input)
{
    const bool is_floor = input >= 'a' && input <= 'a' + TOWER_HEIGHT;
    const bool is_exit  = 'x' == input;

    return (is_floor || is_exit);
}


static bool is_room(const char input)
{
    const bool is_room = input >= '1' && input <= '1' + TOWER_WIDTH;

    return (is_room);
}


static char get_input(bool (* criteria)(const char input), const char * prompt)
{
    char input;

    for(;;)
    {
        printf("%s ", prompt);

        input = tolower(getchar());

        if ('\n' == input)
        {
            continue;
        }

        if(criteria(input))
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
    char * message = "(x to exit) enter floor";
    const char floor_or_exit = get_input(is_floor_or_exit, message);
    
    turn->location.floor = floor_or_exit;

    if ('x' == floor_or_exit)
    {
        turn->location.room = floor_or_exit;
    }
    else
    {
        message = "            enter room ";
        turn->location.room = get_input(is_room, message);
    }

}
