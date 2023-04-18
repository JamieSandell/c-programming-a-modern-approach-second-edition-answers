/*
Write a declaration for an 8 x 8 char array named chess_board. Include an initializer
that puts the following data into the array ( one character per array element):

r n b q k b n r
p p p p p p p p
  .   .   .   .
.   .   .   .
  .   .   .   .
.   .   .   .
P P P P P P P P
R N B Q K B N R
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLUMNS 8

int main(void)
{
    char chess_board[ROWS][COLUMNS] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                                        {'p'},
                                        {'0', '.', '0', '.', '0', '.', '0', '.'},
                                        {'.', '0', '.', '0', '.', '0', '.', '0'},
                                        {'0', '.', '0', '.', '0', '.', '0', '.'},
                                        {'.', '0', '.', '0', '.', '0', '.', '0'},
                                        {'P'},
                                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    for (int row = 0; row < ROWS; ++row)
    {
        for (int column = 0; column < COLUMNS; ++column)
        {
            printf("%c", chess_board[row][column]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}