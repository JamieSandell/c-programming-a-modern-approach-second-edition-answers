/*
Show the output produced by the following program fragments. Assume that i, j,
and k are int variables.

(a) i = 5; j = 3;
    printf("%d %d", i / j, i % j);
    1 2

(b) i = 2; j = 3;
    printf("%d", (i + 10) % j);
    0

(c) i = 7; j = 8; k = 9;
    printf("%d", (i + 10) % k / j);
    17 % 9 = 8
    8 / 8 = 1
    1


(d) i = 1; j = 2; k = 3;
    printf("%d", (i + 5) % (j + 2) / k);
    (6) % (4) / k
    2 / 3 = 0
    0
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 5, j = 3;
    printf("%d %d\n", i / j, i % j);

    i = 2;
    j = 3;
    printf("%d\n", (i + 10) % j);

    i = 7;
    j = 8;
    int k = 9;
    printf("%d\n", (i + 10) % k / j);

    i = 1; j = 2; k = 3;
    printf("%d\n", (i + 5) % (j + 2) / k);

    return EXIT_SUCCESS;
}