/*
Write a declaration of an array named weekend containing seven bool values. Include an
initializer that makes the first and last values true; all other values should be false.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    bool weekend[] = {true, false, false, false, false, false, true};

    for (int i = 0; i < 7; ++i)
    {
        printf("%d ", weekend[i]);
    }

    return EXIT_SUCCESS;
}