/*
Show the output produced by each of the following program fragments. Assume that i, j,
and k are int variables.

(a) i = 1;
    printf("%d ", i++ - 1);
    printf("%d", i);

    0
    1

(b) i = 10; j = 5;
    printf("%d ", i++ - ++j);
    printf("%d %d", i, j);

(c) i = 7; j = 8;
    printf("%d ", i++ - --j);
    printf("%d %d", i, j);

(d) i = 3; j = 4; k = 5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d", i, j, k);
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int i = 1;
    printf("%d ", i++ - 1);
    printf("%d", i);

    return EXIT_SUCCESS;
}