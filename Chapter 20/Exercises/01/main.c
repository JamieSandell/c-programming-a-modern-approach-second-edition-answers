/*
Show the output produced by each of the following program fragments. Assume that i, j,
and k are unsigned short variables.

(a) i = 8; j = 9;
    printf("%d", i >> 1 + j >> 1);

    0

(b) i = 1;
    printf("%d", i & ~i);

    0

(c) i = 2; j = 1; k = 0;
    printf("%d", ~i & j ^ k);

    1

(d) i = 7; j = 8; k = 9;
    printf("%d", i ^ j & k);

    15
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned short i = 8;
    unsigned short j = 9;
    unsigned k;

    printf("%d\n", i >> 1 + j >> 1);

    i = 1;
    printf("%d\n", i & ~i);

    i = 2; j = 1; k = 0;
    printf("%d\n", ~i & j ^ k);

    i = 7; j = 8; k = 9;
    printf("%d\n", i ^ j & k);

    return EXIT_SUCCESS;
}