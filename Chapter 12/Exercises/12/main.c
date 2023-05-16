/*
Write the following function:

void find_two_largest(const int *a, int n, int *largest,
                      int *second_largest);

a points to an array of length n. The function searches the array for its largest and second-
largest elements, storing them in the variables pointed to by largest and
second_largest, respectively. Use pointer arithmetic -- not subscripting -- to visit array
elements.
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

void find_two_largest(const int *a, int n, int *largest, int *second_largest);

int main(void)
{
    int a[LENGTH] = {100, 25, 55, 99, 200};
    int largest;
    int second_largest;
    int *largest_p = &largest;
    int *second_largest_p = &second_largest;

    find_two_largest(a, LENGTH, largest_p, second_largest_p);
    printf("largest and second largest values in a[]: %d, %d\n", largest, second_largest);

    exit(EXIT_SUCCESS);
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    *largest = *a;
    *second_largest = *a;

    for (const int *p = a; p < a + n - 1; p++)
    {
        if (*largest < *(p + 1))
        {
            *largest = *(p + 1);
        }
        else if (*second_largest < *(p + 1))
        {
            *second_largest = *(p + 1);
        }
    }
}