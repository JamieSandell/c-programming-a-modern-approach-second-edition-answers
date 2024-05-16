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
    terminate(argc != 2, "Incorrect usage. Example usage: count_words file1.txt\n");

    FILE *fp = open_file_for_reading(argv[1]);

    snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Failed to open %s for reading.\n", argv[1]);
    terminate(fp == NULL, g_message_buffer);

    int c;
    enum Word {
        WORD_START,
        WORD_END
    };
    enum Word state = WORD_END;
    unsigned int word_count = 0;

    do
    {
        c = fgetc(fp);
        switch (state)
        {
            case WORD_END:
            {
                if (isspace(c) == 0)
                {
                    state = WORD_START;
                }

                break;
            }
            case WORD_START:
            {
                if (isspace(c) != 0)
                {
                    state = WORD_END;
                    ++word_count;
                }

                break;
            }
            default:
            {
                terminate(true, "Invalid word state.\n");
            }
        }

    } while (c != EOF);

    if (ferror(fp))
    {
        snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Error whilst reading %s\n", argv[1]);
        terminate(fp == NULL, g_message_buffer);
    }

    if (feof(fp))
    {
        ++word_count;
    }

    printf("%d word%s in %s.", word_count, word_count == 1 ? "" : "s", argv[1]);

    snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Error whilst closing %s\n", argv[1]);
    terminate(fclose(fp) != 0, g_message_buffer);
    
    return EXIT_SUCCESS;
}