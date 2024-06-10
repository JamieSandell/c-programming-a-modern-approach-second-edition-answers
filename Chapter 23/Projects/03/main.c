/*
Write a program that copies a text file from standard input to standard output, capitalizing
the first letter in each word.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    bool beginning_of_line = true;
    bool beginning_of_word = true;

    while ((c = getchar()) != EOF)
    {
        if (isspace(c))
        {
            beginning_of_word = false;
        }
        else if (!isspace(c) && !beginning_of_word)
        {
            beginning_of_word = true;
            c = toupper(c);
        }

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