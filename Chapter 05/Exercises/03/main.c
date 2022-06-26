/*
The following program fragments illustrate the short-circuit behaviour of logical expressions.
Show the output produced by each, assuming that i, j, and k are int variables.

(a) i = 3; j = 4; k = 5;
    printf("%d ", i < j || ++j < k);
    printf("%d %d %d", i, j, k);

    (i < j) || (++j < k)
    3 < 4 || ++4 < 5
    order of evaluation/short circuit, 3 < 4 is true, so ++j < k is never executed
    prints 1 3 4 5

(b) i = 7; j = 8; k = 9;
    printf("%d ", i - 7 && j++ < k);
    printf("%d %d %d", i, j, k)
    i - 7 = 0, so LHS evaluates to false, j++ < k is never executed
    prints 0 7 8 9


(c) i = 7; j = 8; k = 9;
    printf("%d ", (i = j) || (j = k));
    printf("%d %d %d", i, j, k);
    RHS is never evaluated as i is assigned 8, so is "true"
    prints 1 8 8 9

(d) i = 1; j = 1; k = 1;
    printf("%d ", ++i || ++j && ++k);
    printf("%d %d %d", i, j, k);
    i is incremented and then evaluated to 2 ("true"), so ++j && ++k never executes.
    prints 1, 2, 1, 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, k;

    i = 3; j = 4; k = 5;
    printf("%d ", i < j || ++j < k);
    printf("%d %d %d\n", i, j, k);

    i = 7; j = 8; k = 9;
    printf("%d ", i - 7 && j++ < k);
    printf("%d %d %d\n", i, j, k);


    i = 7; j = 8; k = 9;
    printf("%d ", (i = j) || (j = k));
    printf("%d %d %d\n", i, j, k);

    i = 1; j = 1; k = 1;
    printf("%d ", ++i || ++j && ++k);
    printf("%d %d %d\n", i, j, k);

    return EXIT_SUCCESS;
}