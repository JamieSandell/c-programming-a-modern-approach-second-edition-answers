/*
Modify the find_largest function so that it uses pointer arithmetic -- not subscript-
ing -- to visit array elements.
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

int find_largest(int a[], int n);

int main(void)
{
    int a[LENGTH] = {1, 2, 8, 20, 5};

    printf("Largest value of a[] is: %d\n", find_largest(a, LENGTH));

    exit(EXIT_SUCCESS);
}

int find_largest(int a[], int n)
{
    int *p;
    int largest = *a;

    for (p = a; p < a + n - 1; p++)
    {
        if (largest < *(p + 1))
        {
            largest = *(p + 1);
        }
    }

    return largest;
}