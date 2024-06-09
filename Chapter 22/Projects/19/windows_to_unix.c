/*
(a) Write a program that converts a Windows text file to a UNIX text file (See Section 22.1
for a discussion of the differences between Windows and UNIX text files).

(b) Write a program that converts a UNIX text file to a Windows text file.

In each case, have the program obtain the names of both files from the command line. Hint:
Open the input file in "rb" mode and the output file in "wb" mode.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 512

void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
    char message[MAX_MESSAGE_LENGTH];
    snprintf(message, MAX_MESSAGE_LENGTH, "Incorrect usage. Example usage: windows_to_unix windows.txt unix.txt\n");
    terminate(argc != 3, message);

    FILE *fpr = fopen(argv[1], "rb");
    snprintf(message, MAX_MESSAGE_LENGTH, "Error opening %s for reading.\n", argv[1]);
    terminate(fpr == NULL, message);

    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to seek to end of %s\n", argv[1]);
    terminate(fseek(fpr, 0L, SEEK_END), message);

    long input_file_size = ftell(fpr);
    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to get the file size of %s\n", argv[1]);
    terminate (input_file_size == -1L, message);

    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to seek to the beginning of file %s\n", argv[1]);
    terminate(fseek(fpr, 0L, SEEK_SET), message);

    char *input_contents = malloc((size_t) input_file_size);
    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to allocate memory for the contents of %s\n", argv[1]);
    terminate(input_contents == NULL, message);

    char *output_contents = malloc((size_t) input_file_size);
    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to allocate memory for the contents of %s\n", argv[2]);
    terminate(output_contents == NULL, message);

    FILE *fpw = fopen(argv[2], "wb");
    snprintf(message, MAX_MESSAGE_LENGTH, "Error opening %s for writing.\n", argv[2]);
    terminate(fpw == NULL, message);

    int c;

    while ((c = fgetc(fpr)) != EOF)
    {
        if (c != '\r')
        {
            snprintf("Failed to write %c to %s\n", c, argv[2]);
            terminate(fputc(c, fpw) == EOF, message);
        }
    }
    
    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to read %s\n", argv[1]);
    terminate(ferror(fpr), message);

    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to close to %s\n", argv[2]);
    terminate(fclose(fpw), message);

    snprintf(message, MAX_MESSAGE_LENGTH, "Failed to close %s\n", argv[1]);
    terminate(fclose(fpr), message);

    return EXIT_SUCCESS;
}

void terminate(bool condition, const char *message)
{
    if (condition)
    {
        fprintf(stderr, message);
    }
}