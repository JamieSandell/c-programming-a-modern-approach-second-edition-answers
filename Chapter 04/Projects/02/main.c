/*
Extend the program in Programming Project 1 to handle three-digit numbers.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a three-digit number: ");
    int n;
    scanf("%d", &n);
    printf("%d%d%d\n", n % 10, n / 10 % 10, n / 10 / 10);

    return EXIT_SUCCESS;
}