/*
Modify Programming Project 2 from Chapter 12 so that it includes the following function:

bool is_palindrome(const char *message);

The function returns true if the string pointed to by message is a palindrome.
*/

/*
(a) Write a program that reads a message, then checks whether it's a palindrome (the letters
in the message are the same from left to right as from right to left):

Enter a message: He lived as a devil, eh?
Palindrome

Enter a message: Madam, I am Adam.
Not a palindrome

Ignore all characters that aren't letters. Use integer variables to keep track of positions in the
array.

(b) Revise the program to use pointers instead of integers to keep track of positions in the
array.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER 1000

bool is_palindrome(const char *message);

int main(void)
{
    char message[BUFFER] = {0};
    char c;
    //int chars_stored = 0;
    bool palindrome;
    char *p = message;

    printf("Enter a message: ");

    // Array version
    /*while ((c = getchar()) != '\n' && chars_stored < BUFFER)
    {
        if (isalpha(c))
        {
            message[chars_stored++] = tolower(c);
        }        
    }
    
    for (int i = 0, j = chars_stored - 1; i < chars_stored / 2 && j >= chars_stored / 2; i++, j--)
    {
        if (message[i] != message[j])
        {
            palindrome = false;
            break;
        }
    }*/

    while ((c = getchar()) != '\n' && p < message + BUFFER)
    {
         if (isalpha(c))
         {
            *p++ = tolower(c);
         }
    }

    palindrome = is_palindrome(message);

    if (palindrome)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a plaindrome\n");
    }

    exit(EXIT_SUCCESS);
}

bool is_palindrome(const char *message)
{
    for (const char *i = message, *j = message + strlen(message) - 1; i < j; i++, j--)
    {
        if (*i != *j)
        {
            return false;
        }
    }

    return true;
}