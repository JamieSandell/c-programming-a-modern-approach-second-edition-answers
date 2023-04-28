/*
Modify Programming Project 9 from Chapter 8 so that it includes the following functions:

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

main first calls generate_random_walk, which initializes the array to contain '.'
characters and then replaces some of these characters by the letters A through Z, as
described in the original project. main then calls print_array to display the array o
the screen.
*/

/*
Write a program that generates a "random walk" across a 10 x 10 array. The array will con-
tain characters (all '.' initially). The program must randomly "walk" from element to ele-
ment, always going up, down, left or right by one element. The elements visited by the
program will be labeled with the letters A through Z, in the order visited. Here's an example
of the desired output:

A . . . . . . . . .
B C D . . . . . . .
. F E . . . . . . .
H G . . . . . . . .
I . . . . . . . . .
J . . . . . . . Z .
K . . R S T U V Y .
L M P Q . . . W X .
. N O . . . . . . .
. . . . . . . . . .

Hint Use the srand and rand functions (see deal.c) to generate random numbers.
After generating a number, look at its remainder when divided by 4. There are four possible
values for the remainder -- 0, 1, 2 and 3 -- indiciating the direction of the next move. Before
performing a move, check that (a) it won't go outside the array, and (b) it doesn't take us to
an element that already has a letter assigned. If either condition is violated, try moving in
another direction. If all four directions are blocked, the program must terminate. Here's an
example of premature termination:

A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .

Y is blocked on all four sides, so there's no place to put Z.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10
#define MOVE_SIZE 4

void generate_random_walk(char grid[10][10]);
void print_array(char grid[10][10]);

int main(void)
{
    char grid[SIZE][SIZE];

    generate_random_walk(grid);
    print_array(grid);   

    exit(EXIT_SUCCESS);
}

void generate_random_walk(char grid[10][10])
{
    int destination_x = 0;
    int destination_y = 0;
    int x = 0;
    int y = 0;
    int directions_blocked_count = 0;
    int direction;
    bool invalid_moves[MOVE_SIZE] = {false}; // represents each direction, left, top, right and up (in that order)
    bool random_direction_selected;
    bool valid_move = true;

    memset(grid, '.', sizeof(char) * SIZE * SIZE);

    srand((unsigned) time(NULL));

    for (int letter = 'A' - 1; letter < 'Z' && directions_blocked_count < 4;)
    {
        if (valid_move)
        {
            letter++;
            grid[x][y] = letter;
        }

        random_direction_selected = false;        
        
        while (!random_direction_selected)
        {
            direction = rand() % 4;
            if (!invalid_moves[direction])
            {
                random_direction_selected = true;
            }
        }        

        switch (direction)
        {
            case 0: // move left
            {
                destination_x = x - 1;
                destination_y = y;
                break;
            }
            case 1: // move up
            {
                destination_x = x;
                destination_y = y - 1;
                break;
            }
            case 2: // move right
            {
                destination_x = x + 1;
                destination_y = y;
                break;
            }
            case 3: // move down
            {
                destination_x = x;
                destination_y = y + 1;
                break;
            }
            default:
            {
                printf("Error: invalid move direction");
                exit(EXIT_FAILURE);
            }
        }

        if (!(destination_x < 0 || destination_x >= SIZE || destination_y < 0 || destination_y > SIZE)) // inside bounds?
        {
            if (grid[destination_x][destination_y] == '.') // have we already visited this grid position?
            {
                x = destination_x;
                y = destination_y;
                for (int i = 0; i < MOVE_SIZE; i++)
                {
                    invalid_moves[i] = false;
                }
                directions_blocked_count = 0;
                valid_move = true;
            }
            else
            {
                directions_blocked_count++;
                invalid_moves[direction] = true;
                valid_move = false;
            }
        }
        else // outside bounds
        {
            directions_blocked_count++;
            valid_move = false;
        }   
    }
}

void print_array(char grid[10][10])
{
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            printf("%c ", grid[x][y]);
        }
        printf("\n");
    }
}