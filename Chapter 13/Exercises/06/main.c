/*
Write a function named censor that modifies a string by replacing every occurrence of
foo by xxx. For example, the string "food fool" would become "xxxd xxxl". Make
the function as short as possible without sacrificing clarity.
*/

#include <stdlib.h>
#include <stdio.h>

void censor(char *string);

int main(void)
{
    char string[] = "food fool";

    printf("String to censor: %s\n", string);
    censor(string);
    printf("Result: %s\n", string);

    exit(EXIT_SUCCESS);
}

void censor(char *string)
{
    while (*string)
    {
        if (!(*(string + 1)) || !(*(string + 2))) // end of the string
        {
            break;
        }

        if (*string == 'f' && *(string + 1) == 'o' && *(string + 2) == 'o')
        {
            for (int i = 0; i < 3; i++)
            {
                *string++ = 'x';
            }
            continue;
        }

        string++;
    }
}