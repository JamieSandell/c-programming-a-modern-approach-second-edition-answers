/*
The value of the mathematical constant e can be expressed as an infinite series:

e = 1 + 1/1! + 1/2! + 1/3! + ...

Write a program that approximates e by computing the value of

1 + 1/1! + 1/2! + 1/3! + ... + 1/n!

where n is an integer entered by the user.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i, n, denom;
    float e;

    printf("Enter integer n: ");
    scanf("%d", &n);

    for (i = 1, denom = 1, e = 1.0f; i <= n; ++i)
    {
        e += 1.0f / (denom *= i);
    }
    printf("Approximation of e: %f\n", e);

    return EXIT_SUCCESS;
}