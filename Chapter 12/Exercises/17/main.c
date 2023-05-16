/*
Rewrite the following function to use pointer arithmetic instead of array subscripting. (In
other words, eliminate the variables i and j and all uses of the [] operator.) Use a single
loop instead of nested loops.

int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < LEN; j++)
            sum += a[i][j];
    return sum;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 2

int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int sum = 0;

    for (const int *p = *a; p < *a + n * LEN; p++)
    {
        sum += *p;
    }

    return sum;
}

int main(void)
{
    int a[LEN][LEN] = {{2, 4}, {1, 2}};

    printf("%d\n", sum_two_dimensional_array(a, LEN));

    exit(EXIT_SUCCESS);
}