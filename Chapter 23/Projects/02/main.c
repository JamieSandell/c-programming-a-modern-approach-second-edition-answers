/*
Write a program that copies a text file from standard input to standard output, removing all white-space characters from the beginning of each
line. A line consisting entirely of white-space characters will not be copied.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    bool beginning_of_line = true;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            beginning_of_line = true;
            putchar(c);
        }
        if (beginning_of_line && isspace(c))
        {
            continue;
        }
        else
        {
            beginning_of_line = false;
            putchar(c);
        }
    }
    

    return EXIT_SUCCESS;
}