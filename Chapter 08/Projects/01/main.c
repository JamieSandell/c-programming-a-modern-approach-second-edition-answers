/*
Modify the repdigit.c program of Section 8.1 so that it shows which digits (if any)
were repeated:

Enter a number: 939577
Repeated digit(s): 7 9
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    bool digit_seen[10] = {false};
    int digit;
    long n;
    bool repeated_digits[10] = {false};
    bool is_repeated = false;

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
        for (int digit = 0; digit < (sizeof(repeated_digits) / sizeof(repeated_digits[0])); ++digit)
        {
            if (repeated_digits[digit])
            {
                printf("%d ", digit);
            }
        }
        printf("\n");
    }
    else
    {
        printf("No repeated digit\n");
    }

    return EXIT_SUCCESS;
}