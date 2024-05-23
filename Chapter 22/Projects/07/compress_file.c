/*
Of the many techniques for compressing the contents of a file, one of the simplest and fast-
est is known as run-length encoding. This technique compresses a file by replacing
sequences of identical bytes by a pair of bytes: a repetition count followed by a byte to be
repeated. For example, suppose that the file to be compressed begins with the following
sequence of bytes (shown in hexadecimal):

46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20

The compressed file will contain the following bytes:

01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20

Run-length encoding works well if the original file contains many long sequences of identi-
cal bytes. In the worst case (a file with no repeated bytes), run-length encoding can actually
double the length of the file.

(a) Write a program named compress_file that uses run-length encoding to compress
a file. To run compress_file, we'd use a command of the form

compress_file original-file

compress_file will write the compressed version of original-file to original-file.rle.

For example, the command

compress_file foo.txt

will cause compress_file to write a compressed version of foo.txt to a file named
foo.txt.rle. Hint: The program described in Programming Project 6 could be useful
for debugging.

(b) Write a program named uncompress_file that reverses the compression performed
by the compress_file program. The uncompress-file command will have the
form

uncompress_file compressed-file

compressed-file should have the extension .rle. For example, the command

uncompress_file foo.txt.rle

will cause uncompress_file to open the file foo.txt.rle and write an uncom-
pressed version of its contents to foo.txt. uncompress_file should display an error
message if its command-line argument doesn't end with the .rle extension.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define MAX_FILE_SIZE 255
#define MAX_SEQUENCE_COUNT 255

static void write_sequence(unsigned int sequence_count, int c, FILE *const fpw, const char *filename);

int main(int argc, char *argv[])
{
    terminate(argc != 2, "Invalid program arguments, example usage: compress_file original-file\n");

    FILE *fpr = fopen(argv[1], "rb");
    
    snprintf(g_message, MAX_MESSAGE_SIZE, "Error opening %s for reading.\n", argv[1]);
    terminate(fpr == NULL, g_message);

    unsigned int sequence_count = 1;
    int current;
    int next;
    char destination_filename[MAX_FILE_SIZE];
    char file_extension[] = ".rle";

    strncpy(destination_filename, argv[1], MAX_FILE_SIZE - 1);
    strncat(destination_filename, file_extension, MAX_FILE_SIZE - 1);

    FILE *fpw = fopen(destination_filename, "wb");

    while ((current = fgetc(fpr)) != EOF)
    {
        next = fgetc(fpr);

        if (current != next)
        {
            write_sequence(sequence_count, current, fpw, argv[1]);
            if (next != EOF)
            {
                terminate(ungetc(next, fpr) == EOF, "Failed to push back character to the stream.\n");
            }
            
            sequence_count = 1;
            continue;
        }

        ++sequence_count;

        if (next != EOF)
        {
            terminate(ungetc(next, fpr) == EOF, "Failed to push back character to the stream.\n");
        }
    }
    
    snprintf(g_message, MAX_MESSAGE_SIZE, "Error closing %s", destination_filename);
    terminate(fclose(fpw), g_message);

    snprintf(g_message, MAX_MESSAGE_SIZE, "Error whilst reading %s\n", argv[1]);
    terminate(ferror(fpr), g_message);

    snprintf(g_message, MAX_MESSAGE_SIZE, "Error closing %s\n", argv[1]);
    terminate(fclose(fpr), g_message);

    return EXIT_SUCCESS;
}

static void write_sequence(unsigned int sequence_count, int c, FILE *const fpw, const char *filename)
{
    snprintf(g_message, MAX_MESSAGE_SIZE, "Failed to write the sequence count %u to %s\n", sequence_count, filename);
    terminate(fputc(sequence_count, fpw) == EOF, g_message);
    snprintf(g_message, MAX_MESSAGE_SIZE, "Failed to write the character %c to %s\n", c, filename);
    terminate(fputc(c, fpw) == EOF, g_message);
}