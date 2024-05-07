/*
Write the following function:

int line_length(const char *filename, int n);

The function should return the length of line n in the text file whose name is filename
(assuming that the first line in the file is line 1). If the line doesn't exist, the function should
return 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 255
#define TEST_FILE "test.txt"
#define LINE_NUMBER 3

char buffer[MAX_LINE_LENGTH];

int line_length(const char *filename, int n);

int main(void)
{
    printf("Length of line (includes newline character) %d of %s is %d", LINE_NUMBER, TEST_FILE, line_length(TEST_FILE, LINE_NUMBER));

    return EXIT_SUCCESS;
}

int line_length(const char *filename, int n)
{
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error in line_length: failed to open %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    int line_count = 0;
    int line_length = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL)
    {
        ++line_count;

        if (line_count == n)
        {
            line_length = strlen(buffer);
            break;
        }
    }

    if (ferror(fp))
    {
        fprintf(stderr, "Error in line_length: I/O error when reading %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    return line_length;
}