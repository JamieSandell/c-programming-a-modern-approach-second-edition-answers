/*
Write a program that find the largest and smallest of four integers entered by the user:

Enter four integers: 21 43 10 35
Largest: 43
Smallest: 10

Use as few if statements as possible. Hint: Four if statements are sufficient
*/

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int num1, num2, num3, num4;
    int smallest_number, largest_number, smallest_number_1, largest_number_1, smallest_number_2, largest_number_2;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    if (num1 >= num2)
    {
        largest_number_1 = num1;
        smallest_number_1 = num2;
    } else
    { 
        largest_number_1 = num2;
        smallest_number_1 = num1;
    }
    if (num3 >= num4)
    {
        largest_number_2 = num3;
        smallest_number_2 = num4;
    }
    else
    {
        largest_number_2 = num4;
        smallest_number_2 = num3;
    }

    if (largest_number_2 > largest_number_1)
    {
        largest_number = largest_number_2;
    }
    else
    {
        largest_number = largest_number_1;
    }
    if (smallest_number_1 < smallest_number_2)
    {
        smallest_number = smallest_number_1;
    }
    else
    {
        smallest_number = smallest_number_2;
    }

    printf("Largest: %d\n", largest_number);
    printf("Smallest: %d\n", smallest_number);

    return EXIT_SUCCESS;
}