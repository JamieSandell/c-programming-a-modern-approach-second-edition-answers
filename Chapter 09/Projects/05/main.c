/*
Modify Programming Project 17 from Chapter 8 so that it includes the following functions:

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

After obtaining the number n from the user, main will call create_magic_square,
passing it an n x n array that is declared inside main. create_magic_square will fil
the array with the numbers 1, 2, ..., n² as described in the original project. main will then
call print_magic_square, which will display the array in the format described in the
original project. Note: If your compiler doesn't support variable-length arrays, declare the
array in main to be 99 x 99 instead of n x n and use the following prototypes instead:

void create_magic_square(int n, char magic_square[99][99]);
void print_magic_square(int n, char magic_square[99][99]);
*/

/*
Write a program that prints an n x n magic square (a square arangement of the numbers
1, 2, ... n² in which the sums of the rows, columns and diagonals are all the same). The
user will specify the value of n:

This program creates a magic square of a specified size.
The size must be an odd number between 1 and 99.
Enter size of magic square: 5
   17   24    1    8   15
   23    5    7   14   16
    4    6   13   20   22
   10   12   19   21    3
   11   18   25    2    9

Store the magic square in a two-dimensional array. Start by placing the number 1 in the mid-
dle of row 0. Place each of the remaining numbers 2, 3, ... n² by moving up one row and
over one column. Any attempt to go outside the bounds of the array should "wrap around"
to the opposite side of the array. For example, instead of storing the next number in row -1,
we would store it in row n - 1 (the last row). Instead of storing the next number in column n,
we would store it in column 0. If a particular array element is already occupied, put the
number directly below the previously stored number. If your compiler supports variable-
length arrays, declare the array to have n rows and n columns. If not, declare the array to
have 99 rows and 99 columns.
*/

#include <stdio.h>
#include <stdlib.h>



int main(void)
{
    int n;
    int row;
    int column;
    int count;
    int previous_row;
    int previous_column;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("%d is not an odd number", n);
        return EXIT_FAILURE;
    }

    int magic_square[n][n];

    for (row = 0; row < n; row++)
    {
        for (column = 0; column < n; column++)
        {
            magic_square[row][column] = 0;
        }
    }

    row = n / 2;
    column = 0;
    magic_square[row][column] = 1;

    count = 2;
    int n_squared = n * n;

    while (count <= n_squared)
    {        
        previous_row = row;
        previous_column = column;

        if (previous_row + 1 >= n) // wrap around
        {
            row = 0;
        }
        else
        {
            row = previous_row + 1;
        }

        if (previous_column - 1 < 0) // wrap around
        {
            column = n - 1;
        }
        else
        {
            column = previous_column - 1;
        }
        
        if (magic_square[row][column] == 0)
        {
            magic_square[row][column] = count++;
        }
        else
        {
            if (previous_column + 1 >= n)
            {
                magic_square[row = previous_row][column = 0] = count++;
            }
            else
            {
                magic_square[row = previous_row][column = previous_column + 1] = count++;
            }
        }
    }

    for (column = 0; column < n; column++)
    {
        for (row = 0; row < n; row++)
        {
            printf("%4d", magic_square[row][column]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}