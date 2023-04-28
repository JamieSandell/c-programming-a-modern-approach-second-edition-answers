/*
Consider the following "mystery" function:

void pb(int n)
{
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}

Trace the execution of the function by hand. Then write a program that calls the function,
passing it a number entered by the user. What does the function do?

The function prints the binary representation of the integer passed to it.
*/

#include <stdlib.h>
#include <stdio.h>

void pb(int n);

int main(void)
{
    printf("Binary representation of 10: ");
    pb(10);
    printf("\n");

    exit(EXIT_SUCCESS);
}

void pb(int n)
{
    if (n != 0) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}