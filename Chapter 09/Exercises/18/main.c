/*
Write a recursive version of the gcd function (see Exercise 3). Here's the strategy to use for
computing gcd(m, n): If n is 0, return m. Otherwise, call gcd recursively, passing n as
the first argument and m % n as the second.
*/

#include <stdlib.h>
#include <stdio.h>

double gcd(int m, int n);

int main(void)
{
    printf("GCD of 10 and 8: %.1f\n", gcd(10, 8));

    exit(EXIT_SUCCESS);
}

double gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}