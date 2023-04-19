/*
Write a program fragment that declares an 8 x 8 char array named checker_board and
then uses a loop to store the following data into the array (one character per array element):

B R B R B R B R
R B R B R B R B
B R B R B R B R
R B R B R B R B
B R B R B R B R
R B R B R B R B
B R B R B R B R
R B R B R B R B

Hint: The element in row i, column j, should be the letter B if i + j is an even number.
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLUMNS 8

int main(void)
{
    char checker_board[ROWS][COLUMNS];

    for (int row = 0; row < ROWS; ++row)
    {
        for (int column = 0; column < COLUMNS; ++column)
        {
          checker_board[row][column] = (row + column) % 2 == 0 ? 'B' : 'R';
        }
    }

    for (int row = 0; row < ROWS; ++row)
    {
      for (int column = 0; column < COLUMNS; ++column)
      {
        printf("%c ", checker_board[row][column]);
      }
      
      printf("\n");
    }

    return EXIT_SUCCESS;
}