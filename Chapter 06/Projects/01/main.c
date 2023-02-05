/*
Write a program that finds the largest in a series of numbers entered by the user. The pro-
gram must prompt the user to enter numbers one by one. When the user enters 0 or a nega-
tive number, the program must display the largest nonnegative number entered:

Enter a number: 60
Enter a number: 38.3
Enter a number: 4.89
Enter a number: 100.62
Enter a number: 75.2295
Enter a number: 0

The largest number entered was 100.62

Notice that the numbers aren't necessarily integers.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float previous_number = 0;
    float current_number;
    float largest_number = 0;

    while (true)
    {
        printf("Enter a number: ");
        scanf("%f", &current_number);

        if (current_number <= 0)
        {
            break;
        }

        if (current_number > previous_number)
        {
            largest_number = current_number;
        }
        previous_number = current_number;
    }

    printf("The largest number entered was %f", largest_number);

    return EXIT_SUCCESS;
}