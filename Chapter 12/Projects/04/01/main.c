/*
(a) Write a program that reads a message, then prints the reversal of the message:

Enter a message: Don't get mad, get even.
Reversal is: .neve teg ,dam teg t'noD

Hint: Read the message one character at a time (using getchar) and store the characters in
an array. Stop reading when the array is full or the character read is '\n'.

(b) Revise the program to use a pointer instead of an integer to keep track of the current
position in the array.
*/

#include <stdlib.h>
#include <stdio.h>

#define BUFFER 1000

int main(void)
{
    char c;
    //int chars_stored = 0;
    char message[BUFFER] = {0};
    char *p = message;

    printf("Enter a message: ");

    //Array version
    /*while ((c = getchar()) != '\n' && chars_stored < BUFFER)
    {
        message[chars_stored++] = c;
    }*/

    printf("Reversal is: ");

    /*for (int i = chars_stored - 1; i >= 0; i--)
    {
        putchar(message[i]);
    }

    printf("\n"); */
    

    while ((c = getchar()) != '\n' && p < message + BUFFER)
    {
        *p++ = c;
    }

    while (--p >= message)
    {
        putchar(*p);
    }

    printf ("\n");

    exit(EXIT_SUCCESS);
}