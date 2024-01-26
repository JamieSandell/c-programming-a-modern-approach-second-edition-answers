/*
(a) Each square of a chessboard can hold one piece -- a pawn, knight, bishop, rook, queen,
or king -- or it may be empty. Each piece is either black or white. Define two enumerated
types: Piece, which has seven possible values (one of which is "empty"), and Color,
which has two.

(b) Using the types from part (a), define a structure type named Square that can store both
the type of a piece and its color.

(c) Using the Square type from part (b), declare an 8 x 8 array named board that can
store the entire contents of a chessboard.

(d) Add an initializer to the declaration in part (c) so that board's initial value corresponds
to the usual arrangement of pieces at the start of a chess game. A square that's not occupied
by a piece should have an "empty" piece value and the color black.
*/

#include <stdlib.h>

int main(void)
{
    enum piece // (a)
    {
        empty,
        pawn,
        knight,
        bishop,
        rook,
        queen,
        king
    };

    enum color
    {
        white,
        black
    };

    struct Square // (b)
    {
        enum piece piece;
        enum color color;
    };

    //struct Square chessboard[8][8]; // (c)

    struct Square chessboard[8][8] = // (d)
    {
        {{rook,  white}, {knight, white}, {bishop, white}, {queen, white}, {king,  white}, {bishop, white}, {knight, white}, {rook,  white}},
        {{pawn,  white}, {pawn,   white}, {pawn,   white}, {pawn,  white}, {pawn,  white}, {pawn,   white}, {pawn,   white}, {pawn,  white}},
        {{empty, black}, {empty,  black}, {empty,  black}, {empty, black}, {empty, black}, {empty,  black}, {empty,  black}, {empty, black}},
        {{empty, black}, {empty,  black}, {empty,  black}, {empty, black}, {empty, black}, {empty,  black}, {empty,  black}, {empty, black}},
        {{empty, black}, {empty,  black}, {empty,  black}, {empty, black}, {empty, black}, {empty,  black}, {empty,  black}, {empty, black}},
        {{pawn,  black}, {pawn,   black}, {pawn,   black}, {pawn,  black}, {pawn,  black}, {pawn,   black}, {pawn,   black}, {pawn,  black}},
        {{rook,  black}, {knight, black}, {bishop, black}, {queen, black}, {king,  black}, {bishop, black}, {knight, black}, {rook,  black}}
    };

    return EXIT_SUCCESS;
}