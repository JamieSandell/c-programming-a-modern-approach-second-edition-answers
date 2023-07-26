/*
Modify Programming Project 11 from Chapter 5 so that it uses arrays containing pointers to
strings instead of switch statements. For example, instead of using a switch statement
to print the word for the first digit, use the digit as an index into an array that contains the
strings "twenty", "thirty", and so forth.
*/

/*
Write a program that asks the user for a two-digit number, then prints the English word for the number:

Enter a two-digit number: 45
You entered the number forty-five.

Hint: Break the number into two digits. Use one switch statement to print the word for the first
digit ("twenty," "thirty," and so forth). Use a second switch statement to print the word for the second
digit. Don't forget that the numbers between 11 and 19 require special treatment.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char *tens[] = {
        "",
        "",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };

    char *teens[] = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };

    char *ones[] = {
        "",
        "-one",
        "-two",
        "-three",
        "-four",
        "-five",
        "-sixe",
        "-seven",
        "-eight",
        "-nine"
    };

    int n;

    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    printf("You entered the number: ");

    if (n / 10 == 1)
    {
        printf("%s\n", teens[n % 10]);
    }
    else
    {
        printf("%s%s\n", tens[n / 10], ones[n % 10]);
    }

    exit(EXIT_SUCCESS);
}