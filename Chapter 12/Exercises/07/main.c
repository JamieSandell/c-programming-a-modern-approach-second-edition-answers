/*
Write the following function:

bool search(const int a[], int n, int key);

a is an array to be searched, n is the number of elements in the array, and key is the search
key. search should return true if key matches some element of a, and false if it
doesn't. Use pointer arithmetic -- not subscripting -- to visit array elements.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

bool search(const int a[], int n, int key);

int main(void)
{
    int a[LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;

    if (search(a, LENGTH, key))
    {
        printf("Found key %i in a[]\n", key);
    }
    else
    {
        printf("Did not find key %i in a[]\n", key);
    }

    exit(EXIT_SUCCESS);
}

bool search(const int a[], int n, int key)
{
    for (const int *p = a; p < a + n; p++)
    {
        if (*p == key)
        {
            return true;
        }
    }

    return false;
}