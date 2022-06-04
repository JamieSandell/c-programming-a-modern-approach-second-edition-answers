/*
Write a program that asks the user to enter a two-digit number, then prints the number with
its digits reversed. A session with the program should have the following appearance:

Enter a two-digit number: 28
The reversal is: 82

Read the number using %d, then break it into two digits. Hint If n is an integer then n % 10
is the last digit in n and n / 10 is n with the last digit removed.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a two-digit number: ");
    int n;
    scanf("%d", &n);
    printf("%d%d\n", n % 10, n / 10);

    return EXIT_SUCCESS;
}