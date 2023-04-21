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
another direction. If all four directions are blocked, thr program must terminate. Here's an
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
#include <time.h>

#define SIZE 10

int main(void)
{
    char grid[SIZE][SIZE] = {'.'};
    int destination_x;
    int destination_y;
    int x = 0;
    int y = 0;
    int directions_blocked_count = 0;
    int direction;
    bool valid_move = false;

    srand((unsigned) time(NULL));
    // suit = rand() % NUM_SUITS;

    for (int letter = 'A'; letter < 'Z' && directions_blocked_count < 4; letter++)
    {
        grid[x][y] = letter;
        direction = rand() % 4;
        while (!valid_move)
        {
            switch (direction)
            {
                case 0: // move left
                {
                    destination_x = x - y;
                    destination_y = y;
                    break;
                }
                case 1: // move up
                {
                    destination_x = x;
                    destination_y = y - 1;
                    break;
                }
                default:
                {
                    printf("Error: invalid move direction");
                    return EXIT_FAILURE;
                }
            }
        }
        
    }

    return EXIT_SUCCESS;
}