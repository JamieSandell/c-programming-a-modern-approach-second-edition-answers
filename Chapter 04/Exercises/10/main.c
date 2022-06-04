/*
Show the output produced by each of the following program fragments. Assume that i, j,
and k are int variables.

(a) i = 6;
    j = i += i;
    printf("%d %d", i, j);

    12 12

(b) i = 5;
    j = (i -= 2) + 1;
    printf("%d %d", i, j);

    3 4

(c) i = 7;
    j = 6 + (i = 2.5);
    printf("%d %d", i, j);

    2 8

(d) i = 2; j = 8;
    j = (i = 6) + (j = 3);
    printf("%d %d", i, j);

    6 9
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int i = 6;
    int j;
    j = i += i;
    printf("%d %d\n", i, j);

    i = 5;
    j = (i -= 2) + 1;
    printf("%d %d\n", i, j);

    i = 7;
    j = 6 + (i = 2.5);
    printf("%d %d\n", i, j);
    
    i = 2; j = 8;
    j = (i = 6) + (j = 3);
    printf("%d %d\n", i, j);


    return EXIT_SUCCESS;
}