/*
(a) Write a program that counts the number of characters in a text file.

(b) Write a program that counts the number of words in a text file (A "word" is any
sequence of non-white-space characters).

(c) Write a program that counts the number of lines in a text file.

Have each program obtain the file name from the command line.
*/

#include <stdlib.h>
#include <stdio.h>
#include "common.h"

int main(int argc, char *argv[])
{
    terminate(argc != 2, "Incorrect program usage. Example usage: count_lines file1.txt\n");
    
    FILE *fp = fopen(argv[1], "r");

    snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Failed to open %s for reading.\n", argv[1]);
    terminate(ferror(fp), g_message_buffer);

    int c;
    unsigned int line_count = 0;

    do
    {
        c = fgetc(fp);

        if (c == '\n')
        {
            ++line_count;
        }
    } while (c != EOF);
    
    snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Error whilst reading %s\n", argv[1]);
    terminate(ferror(fp), g_message_buffer);

    if (c == EOF)
    {
        ++line_count;
    }

    printf("%d line%s in %s", line_count, line_count == 1 ? "" : "s", argv[1]);
    snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Error closing %s\n", argv[1]);
    terminate(fclose(fp) != 0, g_message_buffer);

    return EXIT_SUCCESS;
}