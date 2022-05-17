/*
Write a program that asks the user to enter a value for x and then displays the value of the
following polynomial:
3x5 + 2x4 - 5x3 - x2 + 7x - 6

Hint: C doesn't have an exponentiation operator, so you'll need to multiply x by itself
repeatedly in order to compute the powers of x. (For example, x * x * x is x cubed).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please enter a value for x: ");
    float x;
    scanf("%f", &x);
    printf("\n%.1f", 3 * 3 * 3 * 3 * 3 + 2 * 2 * 2 * 2 - 5 * 5 * 5 - x * x + 7 * x - 6);
    return EXIT_SUCCESS;
}