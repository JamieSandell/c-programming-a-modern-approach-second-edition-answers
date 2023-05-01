/*
Write a function that computes the value of the following polynomial:

3x5 + 2x4 - 5x3 - x² + 7x - 6.

Write a program that asks the user to enter a value for x, calls the function to compute the
value of the polynomial, and then displays the value returned by the function.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long polynomial(long x)
{
    return 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - x * x + 7 * x - 6;
}

int main(void)
{
    long x;

    printf("Enter a value for x: ");
    scanf("%ld", &x);
    printf("Polynomial: %ld\n", polynomial(x));

    exit(EXIT_SUCCESS);
}