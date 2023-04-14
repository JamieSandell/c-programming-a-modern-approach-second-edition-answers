/*
(C99) Repeat Exercise 3, but this time use a designated initializer. Make the initializer as
short as possible.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    bool weekend[] = {[0] = true, [6] = true};

    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", weekend[i]);
    }

    return EXIT_SUCCESS;
}