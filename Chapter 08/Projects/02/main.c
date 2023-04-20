/*
Modify the repdigit.c program of Section 8.1 so that it prints a table showing how
many times each digit appears in the number:

Enter a number: 41271092
Digit:        0 1 2 3 4 5 6 7 8 9
Occurrences:  1 2 2 0 1 0 0 1 0 1
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int digit;
    long n;
    int digits_count[10] = {0};

    printf("Enter a number: ");
    scanf("%ld", &n);
    printf("Digit:\t\t0 1 2 3 4 5 6 7 8 9\nn");

    while (n > 0)
    {
        digit = n % 10;
        digits_count[digit]++;
        n /= 10;
    }

    printf("Occurrences:\t");
    for (int i = 0; i < (sizeof(digits_count) / sizeof(digits_count[0])); ++i)
    {
        printf("%d ", digits_count[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}