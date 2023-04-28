/*
Condense the fact function in the same way we condensed power.

Here is the fact function as written in Section 9.6:

int fact(int n) 
{ 
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1); 
    }
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
    return n <= 1 ? 1 : n * fact(n - 1);
}