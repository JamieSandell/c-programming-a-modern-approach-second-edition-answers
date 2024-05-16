/*
(a) Write a program that counts the number of characters in a text file.

(b) Write a program that counts the number of words in a text file (A "word" is any
sequence of non-white-space characters).

(c) Write a program that counts the number of lines in a text file.

Have each program obtain the file name from the command line.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
    FILE *fp = open_file_for_reading(argv[1]);

    snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Failed to open %s for reading.\n", argv[1]);
    terminate(fp == NULL, g_message_buffer);

    int c;
    enum Word {
        WORD_START,
        WORD_END
    };
    enum Word state = WORD_END;

    do
    {
        c = fgetc(fp);
        switch (state)
        {
            case WORD_END:
            {
                break;
            }
        }

    } while (c != EOF);
    
    return EXIT_SUCCESS;
}