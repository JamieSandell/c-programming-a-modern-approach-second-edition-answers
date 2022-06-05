/*
Write a program that reads an integer entered by the user and displays it in octal (base 8):

Enter a number between 0 and 32767: 1953
In octal, your number is : 03641

The output should be displayed using five digits, even if fewer digits are sufficient. Hint: To
convert the number to octal, first divide it by 8; the remainder is the last digit of the octal
number (1, in this case). Then divide the original number by 8 and repeat the process to
arrive at the next-to-last digit. (printf is capable of displaying numbers in base 8, as we'll
see in Chapter 7, so there's actually an easier way to write this program.)
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a number between 0 and 32767: ");
    int entered_number;
    scanf("%d", &entered_number);
    int fifth_digit, fourth_digit, third_digit, second_digit, first_digit;

    fifth_digit = entered_number % 8;
    entered_number /= 8;

    fourth_digit = entered_number % 8;
    entered_number /= 8;

    third_digit = entered_number % 8;
    entered_number /= 8;

    second_digit = entered_number % 8;
    entered_number /= 8;

    first_digit = entered_number % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", first_digit, second_digit, third_digit, fourth_digit, fifth_digit);

    return EXIT_SUCCESS;
}