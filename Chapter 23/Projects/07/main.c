/*
Write a program that counts the number of sentences in a text file (obtained from standard
input). Assume that each sentence ends with a ., ? or ! followed by a white-space charac-
ter (including \n).
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(void)
{
    int sentence_count = 0;
    char line[MAX_LINE_LENGTH];
    char *p;

    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
        p = line;

        while (*p != '\0')
        {
            if (*p == '.' || *p == '?' || *p == '!')
            {
                ++p;

                if (isspace(*p) || *p == '\0')
                {
                    ++sentence_count;
                }

                continue;
            }

            ++p;
        }        
    }
    
    printf("Found %d sentences.\n", sentence_count);

    return EXIT_SUCCESS;
}