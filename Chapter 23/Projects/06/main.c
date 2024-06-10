/*
Write a program that copies a text file from standard input to standard output, replacing each
control character (other than \n) by a question mark.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char c;

    while ((c = getchar()) != EOF)
    {
        if (strchr("\a\b\f\r\t\v", c) != NULL)
        {
            putchar('?');
        }
        else
        {
            putchar(c);
        }
    }

    return EXIT_SUCCESS;
}