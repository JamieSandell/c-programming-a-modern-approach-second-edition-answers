/*
Write the following function:

double inner_product(const double *a, const double *b,
                     int n);

a and b both point to arrays of length n. The function should return a[0] * b[0] +
a[1] * b[1] + ... + a[n-1] * b[n-1]. Use pointer arithmetic -- not subscripting -- to
visit array elements.
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

double inner_product(const double *a, const double *b, int n);

int main(void)
{
    const double a[LENGTH] = {1.0, 2.2, 1.4, 5.5, 1.4};
    const double b[LENGTH] = {4.3, 3.2, 1.1, 5.3, 2.3};

    printf("Inner product of a[] and b[]: %.2f\n", inner_product(a, b, LENGTH));

    exit(EXIT_SUCCESS);
}

double inner_product(const double *a, const double *b, int n)
{
    double inner_product = 0;

    for (const double *p1 = a, *p2 = b; p1 < a + n; p1++, p2++)
    {
        inner_product += *p1 + *p2;
    }

    return inner_product;
}