/*
The following program fragments illustrate the relational and equality operators. Show the
output produced by each, assuming that i, j, and k are int variables.

(a) i = 2; j = 3;
    k = i * j == 6;
    printf("%d", k);

    k = ((i * j) == 6)
    k = ((6) == 6)
    k = 1
    prints 1

(b) i = 5; j = 10; k = 1;
    printf("%d", k > i < j);

    (k > i) < j
    (1 > 5) < 10
    (0) < 10
    1
    prints 1

(c) i = 3; j = 2; k = 1;
    printf("%d", i < j == j < k);

    (i < j) == (j < k)
    0 == 0
    1
    prints 1

(d) i = 3; j = 4; k = 5;
    printf("%d", i % j + i < k);

    ((i % j) + i) < k;
    ((0) + 3) < 5
    3 < 5
    0
    prints 0
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 3;
    int j = 4;
    int k = 5;

    i = 2; j = 3;
    k = i * j == 6;
    printf("%d\n", k);

    i = 5; j = 10; k = 1;
    printf("%d\n", k > i < j);

    i = 3; j = 2; k = 1;
    printf("%d\n", i < j == j < k);

    i = 3; j = 4; k = 5;
    printf("%d", i % j + i < k);

    return EXIT_SUCCESS;
}