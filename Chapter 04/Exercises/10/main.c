/*
Show the output produced by each of the following program fragments. Assume that i, j,
and k are int variables.

(a) i = 1;
    printf("%d ", i++ - 1);
    printf("%d", i);

    0 2

(b) i = 10; j = 5;
    printf("%d ", i++ - ++j);
    printf("%d %d", i, j);

    4 11 6

(c) i = 7; j = 8;
    printf("%d ", i++ - --j);
    printf("%d %d", i, j);

    0 1 7

(d) i = 3; j = 4; k = 5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d", i, j, k);

    3 4 5 4
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int i = 1;
    printf("%d ", i++ - 1);
    printf("%d\n", i);

    int j = 5;
    i = 10; j = 5;
    printf("%d ", i++ - ++j);
    printf("%d %d\n", i, j);

    i = 7; j = 8;
    printf("%d ", i++ - --j);
    printf("%d %d\n", i, j);

    int k;
    i = 3; j = 4; k = 5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d\n", i, j, k);

    return EXIT_SUCCESS;
}