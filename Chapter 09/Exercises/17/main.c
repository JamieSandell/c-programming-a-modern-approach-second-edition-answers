/*
Rewrite the fact function so that it's no longer recursive.

Solution
The original fact function from Section 9.6:

int fact(int n)
{
    if (n <= 1)
        return 1;
    else 
        return n * fact(n - 1);
}
*/

#include <stdlib.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    printf("Factorial of 10: %d", fact(10));

    exit(EXIT_SUCCESS);
}

int fact(int n)
{
    int result = 1;

    while (n-- > 1)
    {
        result *= n;
    }

    return result;
}