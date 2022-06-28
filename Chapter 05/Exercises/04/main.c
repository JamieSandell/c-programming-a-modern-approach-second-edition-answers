/*
Write a single expression whose value is either -1, 0, or +1, depending on whether i is less
than, equal to, or greater than j, respectively.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 1;
    int j = 2;
    printf("%d\n", (i >= j) - (i <= j)); // -1

    i = j;
    printf("%d\n", (i >= j) - (i <= j)); // 0

    i += j;
    printf("%d", (i >= j) - (i <= j)); // 1

    return EXIT_SUCCESS;
}