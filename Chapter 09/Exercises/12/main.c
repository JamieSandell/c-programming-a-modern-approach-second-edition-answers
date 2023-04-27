/*
Write the following function:

double inner_product(double a[], double b[], int n);
The function should return a[0] * b[0] + a[1] * b[1] +  ... + a[n-1] * b[n-1].
*/

#include <stdlib.h>
#include <stdio.h>

#define LENGTH 10

double inner_product(double a[], double b[], int n);

int main(void)
{
    double a[LENGTH] = {5.5, 2.2, 2.2, 2.2, 5.6, 4.3, 5.6, 8.1, 7.1, 1.2};
    double b[LENGTH] = {1.2, 2.2, 2.2, 2.2, 5.6, 4.3, 5.6, 8.1, 7.1, 1.2};

    printf("Inner Product: %.2f\n", inner_product(a, b, LENGTH));

    exit(EXIT_SUCCESS);
}

double inner_product(double a[], double b[], int n)
{
    double result = 0;

    for (int i = 0; i < n; i++)
    {
        result += a[i] * b[i];
    }

    return result;
}