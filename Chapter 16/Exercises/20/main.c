/*
Suppose that the direction variable is declared in the following way:

enum {NORTH, SOUTH, EAST, WEST} direction;

Let x and y be int variables. Write a switch statement that tests the value of direc-
tion, incrementing x if direction is EAST, decrementing x if direction is WEST,
incrementing y if direction is SOUTH and decrementing y if direction is NORTH.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    enum
    {
        NORTH,
        SOUTH,
        EAST,
        WEST
    } direction;

    int x = 100;
    int y = 100;
    direction = NORTH;

    switch (direction)
    {
        case EAST:
        {
            ++x;
            break;
        }
        case WEST:
        {
            --x;
            break;
        }
        case SOUTH:
        {
            ++y;
            break;
        }
        case NORTH:
        {
            --y;
            break;
        }
        default:
        {
            printf("Unhandled direction: %d\n", direction);
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}