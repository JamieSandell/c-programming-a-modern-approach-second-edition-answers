/*
Modify the maxmin.c program of Section 11.4 so that the max_min function uses a
pointer instead of an integer to keep track of the current position in the array.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int b[N];
    int big;
    int small;

    printf("Enter %d numbers: ", N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &b[i]);
    }

    max_min(b, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return EXIT_SUCCESS;
}

void max_min(int a[], int n, int *max, int* min)
{
    *max = *min = a[0];

    for (int *p = &a[1]; p < a + n; p++)
    {
        if (*p > *max)
        {
            *max = *p;
        }
        else if(*p < *min)
        {
            *min = *p;
        }
    }
}