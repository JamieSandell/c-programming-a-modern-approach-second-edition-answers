/*
Rewrite the following function to use pointer arithmetic instead of array subscripting. (In
other words, eliminate the variable i and all uses of the [] operator.) Make as few changes
as possible.

void store_zeros(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        a[i] = 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

void store_zeros(int a[], int n);

int main(void)
{
    int a[LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("a[] before calling store_zeroes:\n\n");

    for (int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    store_zeros(a, LENGTH);

    printf("\na[] after calling store_zeroes:\n");

    for (int i = 0; i < LENGTH; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    exit(EXIT_SUCCESS);
}

void store_zeros(int a[], int n)
{
    for (int *p = a; p < a + n; p++)
    {
        *p = 0;
    }
}