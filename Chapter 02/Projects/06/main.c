/*
Modify the program of Programming Project 5 so that the polynomial is evaluated using the
following formula:
((((3x + 2)x - 5)x - 1)x / 7)x - 6
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter a value for x: ");
    float x;
    scanf("%f", &x);
    printf("\n%.1f", ((((3 * x + 2) * x - 5) * x - 1) * x / 7) * x - 6);
    return EXIT_SUCCESS;
}