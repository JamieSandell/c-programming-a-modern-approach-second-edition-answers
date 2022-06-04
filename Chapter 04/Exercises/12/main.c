/*
Show the output produced by each of the following program fragments. Assume that i, j,
and k are int variables.

(a) i = 5;
    j = ++i * 3 - 2;
    printf("%d %d", i, j);

    6 16

(b) i = 5;
    j = 3 - 2 * i++;
    printf("%d %d", i, j);

    6 -7

(c) i = 7;
    j = 3 * i-- + 2;
    printf("%d %d", i, j);

    6 23

(d) i = 7;
    j = 3 + --i * 2;
    printf("%d %d", i, j);

    6 15
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 5;
    int j;
    j = ++i * 3 - 2;
    printf("%d %d\n", i, j);

    i = 5;
    j = 3 - 2 * i++;
    printf("%d %d\n", i, j);

    i = 7;
    j = 3 * i-- + 2;
    printf("%d %d\n", i, j);
    
    i = 7;
    j = 3 + --i * 2;
    printf("%d %d\n", i, j);

    return EXIT_SUCCESS;
}