/*
Show the output produced by each of the following program fragments. Assume that i, j,
and k are int variables.

(a) i = 7; j = 8;
    i *= j + 1;
    printf("%d %d", i, j);

    i = i * j + 1
    i = 7 * (8 + 1)
    i = 7 * 9
    i = 63, j = 8
    
    Note: Addition (and subtraction) have a higher operator precedence than *= and =
(b)
    i = j = k = 1;
    i += j += k;
    printf("%d %d %d", i, j, k);
    
    i = 1, j = 1, k = 1
    i = i + j = j + k;
    i = i + j = 2
    i = i + 2
    i = 3, j = 2, k = 1
(c)
    i = 1; j = 2; k = 3;
    i -= j -= k;
    printf("%d %d %d", i, j, k);

    i = i - j = j - k
    i = 1 - 2 = 2 - 3
    i = 1 - j = -1
    i = 1 - -1
    i = 2

    i = 2, j = -1, k = 3
(d)
    i = 2; j = 1; k = 0;
    i *= j *= k;
    printf("%d %d %d", i, j, k);

    i = i * j = j * k
    i = 2 * j = 1 * 0
    j = 0
    i = 2 * 0

    i = 0, j = 0, k = 0
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    int i = 7, j = 8;
    i *= j + 1;
    printf("%d %d\n", i, j);

    int k;
    i = j = k = 1;
    i += j += k;
    printf("%d %d %d\n", i, j, k);

    i = 1, j = 2, k = 3;
    i -= j -= k;
    printf("%d %d %d\n", i, j, k);

    i = 2, j = 1, k = 0;
    i *= j *= k;
    printf("%d %d %d\n", i, j, k);

    return EXIT_SUCCESS;
}