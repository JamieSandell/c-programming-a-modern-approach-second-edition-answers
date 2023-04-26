/*
Write a function gcd(m, n) that calculates the greatest common divisor of the integers m
and n. (Programming Project 2 in Chapter 6 describes Euclid's algorithm for computing the
GCD.)
*/

#include <stdlib.h>
#include <stdio.h>

int gcd(int m, int n);

int main()
{
    int m;
    int n;

    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);

    printf("GCD = %d \n", gcd(m, n));

    exit(EXIT_SUCCESS);
}

int gcd(int m, int n)
{
    int r;

    while (n > 0)
    {
        r = m % n;
        m = n;
        n = r;
    }

    return m;
}