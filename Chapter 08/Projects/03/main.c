/*
Modify the repdigit.c program of Section 8.1 so that the user can enter more than one
number to be tested for repeated digits. The program should terminate when the user enters
a number that's less than or equal to 0.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LENGTH 10

int main(void)
{
    bool digit_seen[ARRAY_LENGTH] = {false};
    int digit;
    long n;
    bool repeated_digits[ARRAY_LENGTH] = {false};
    bool is_repeated = false;

    do
    {
        printf("Enter a number: ");
        scanf("%ld", &n);

        while (n > 0)
        {
            digit = n % 10;
            if (digit_seen[digit])
            {
                repeated_digits[digit] = true;
                is_repeated = true;
            }
            digit_seen[digit] = true;
            n /= 10;
        }

        if (is_repeated)
        {
            printf("Repeated digit(s): ");
            for (int i = 0; i < ARRAY_LENGTH; ++i)
            {
                if (repeated_digits[i])
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
        }
        else
        {
            printf("No repeated digit\n");
        }

        is_repeated = false;
        for (int i = 0; i < ARRAY_LENGTH; ++i)
        {
            digit_seen[i] = false;
            repeated_digits[i] = false;
        }
    } while (n <= 0);

    return EXIT_SUCCESS;
}