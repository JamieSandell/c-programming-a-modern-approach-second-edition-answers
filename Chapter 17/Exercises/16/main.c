/*
Write the following function. The call sum(g, i, j) should return g(i) + ... + g(j).

int sum(int (*f)(int), int start, int end);
*/

#include <stdio.h>
#include <stdlib.h>

int sum(int (*f)(int), int start, int end);
int square(int i);

int main(void)
{
    int start = 1;
    int end = 10;

    printf("Summing all the squares between %d and %d inclusive = %d\n", start, end, sum(&square, start, end));

    return EXIT_SUCCESS;
}

int square(int i)
{
    return i * i;
}

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;

    for (int i = start; i <= end; i++)
    {
        sum += (*f)(i);
    }

    return sum;
}