/*
Modify Programming PRoject 1 from Chapter 12 so that it includes the following function:

void revrse(char *message);

The function reverses the string pointed to by message. Hint: Use two pointers, one ini-
tially pointing to the first character of the string and the other initially pointing to the last
character. Have the function reverse these characters and then move the pointers toward
each other, repeating the process untilthe pointers meet.
*/

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
#include <string.h>

#define BUFFER 1000

void reverse(char *message);

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

/*
    while (--p >= message)
    {
        putchar(*p);
    }
*/

    reverse(message);
    printf("%s\n", message);

    exit(EXIT_SUCCESS);
}

void reverse(char *message)
{
    char *p1 = message;
    char *p2 = message + strlen(message) - 1;
    char temp;

    while (p1 != p2)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        ++p1;
        --p2;
    }
}