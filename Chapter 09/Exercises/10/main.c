/*
Write functions that return the following values. (Assume that a and n are parameters,
where a is an array of int values and n is the length of the array.)

(a) The largest element in a.
(b) The average of all elements in a.
(c) The number of positive elements in a.
*/

#include <stdlib.h>
#include <stdio.h>

#define LENGTH 10

int largest(int a[], int n);

int average(int a[], int n);

int positive_count(int a[], int n);

int main(void)
{
    int a[LENGTH];

    for (int i = 0; i < LENGTH; i++)
    {
        a[i] = i + 1;
    }

    printf("Largest: %d\n", largest(a, LENGTH));
    printf("Average: %d\n", average(a, LENGTH));
    printf("Number of positive elements: %d\n", positive_count(a, LENGTH));

    exit(EXIT_SUCCESS);
}

int largest(int a[], int n)
{
    int largest = a[0];

    for (int i = 1; i < n; i++)
    {
        largest = largest < a[i] ? a[i] : largest;
    }

    return largest;
}

int average(int a[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += a[i];
    }

    return total / n;
}

int positive_count(int a[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        count = a[i] > 0 ? count + 1 : count;
    }

    return count;
}