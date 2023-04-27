/*
Write the following function, which evaluates a chess position:

int evaluate_position(char board[8][8]);

board represents a configuration of pieces on a chessboard, where the letters K, Q, R, B, N,
P represent White pieces, and the letters k, q, r, b, n and p represent Black pieces.
evaluate_position should sum the values of the White pieces (Q = 9, R = 5, B = 3,
N = 3, P = 1). It should also sum the values of the Black pieces (done in a similar way). The
function will return the difference between the two numbers. This value wil be positive if
White has an advantage in material and negative if Black has an advantage.
*/

#include <stdlib.h>
#include <stdio.h>

#define LENGTH 8

int evaluate_position(char board[][LENGTH]);

int main(void)
{
    char board[LENGTH][LENGTH] = {[0][0] = 'K', [0][1] = 'k', [02][01] = 'Q', [02][03] = 'q', [04][02] = 'B', [05][07] = 'n'};
    int result = evaluate_position(board);

    if (result == 0)
    {
        printf("material even\n");
    }
    else if(result > 0)
    {
        printf("White has more material");
    }
    else
    {
        printf("Black has more material.\n");
    }


    exit(EXIT_SUCCESS);
}

int evaluate_position(char board[][LENGTH])
{
    const int queen_value = 9;
    const int rook_value = 5;
    const int bishop_value = 3;
    const int knight_value = 3;
    const int pawn_value = 1;

    int white = 0;
    int black = 0;

    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            switch (board[i][j])
            {
                case 'Q':
                {
                    white += queen_value;
                    break;
                }
                case 'q':
                {
                    black += queen_value;
                    break;
                }
                case 'R':
                {
                    white += rook_value;
                    break;
                }
                case 'r':
                {
                    black += rook_value;
                    break;
                }
                case 'B':
                {
                    white += bishop_value;
                    break;
                }
                case 'b':
                {
                    black += bishop_value;
                    break;
                }
                case 'P':
                {
                    white += pawn_value;
                    break;
                }
                case 'p':
                {
                    black += pawn_value;
                    break;
                }
                case 'N':
                {
                    white += knight_value;
                    break;
                }
                case 'n':
                {
                    black += knight_value;
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }

    return white - black;
}