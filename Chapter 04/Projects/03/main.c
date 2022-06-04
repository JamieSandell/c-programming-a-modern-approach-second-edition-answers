/*
Rewrite the program in Programming Project 2 so that it prints the reversal of a three-digit
number without using arithmetic to split the number into digits. Hint: See the upc.c
program of Section 4.1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a three-digit number: ");
    int first, second, third;
    scanf("%1d%1d%1d", &first, &second, &third);
    printf("%d%d%d\n", third, second, first);

    return EXIT_SUCCESS;
}