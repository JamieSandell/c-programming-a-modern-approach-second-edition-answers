/*
The following program fragments illustrate the logical operators. Show the outputs produced
by each, assuming that i, j, and k are int variables

(a) i = 10; j = 5;
    printf("%d", !i < j);

    (!i) < j
    0 < 5

    prints 1

(b) i = 2; j = 1;
    printf("%d", !i + !j);

    (!i) + (!j)
    (!2) + (!1)
    0 + 0

    prints 0

(c) i = 5; j = 0; k = -5;
    printf("%d", i && j || k);

    (i && j) || k
    (5 && 0) || -5
    0 || -5

    prints 1

(d) i = 1; j = 2; k = 3;
    printf("%d", i < j || k);

    (i < j) || k
    (1 < 2) || 3
    1 || 3

    prints 1
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int i = 10; 
    int j = 5;
    int k;
    printf("%d\n", !i < j);

    i = 2; j = 1;
    printf("%d\n", !i + !j);

    i = 5; j = 0; k = -5;
    printf("%d\n", i && j || k);

    i = 1; j = 2; k = 3;
    printf("%d", i < j || k);

    return EXIT_SUCCESS;
}