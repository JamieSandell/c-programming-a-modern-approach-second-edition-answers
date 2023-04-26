/*
Write a function check(x, y, n) that returns 1 if both x and y fall between 0 and n - 1,
inclusive. The function should return 0 otherwise. Assume that x, y and n are all of type
int.
*/

#include <stdlib.h>
#include <stdio.h>

int check(int x, int y, int n);

int main()
{
    printf("%d", check(0, 5, 10));

    exit(EXIT_SUCCESS);
}

int check(int x, int y, int n)
{
    if ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1))
    {
        return 0;
    }

    return 1;
}