/*
(a) Write your own version of the fgets function. Make it behave as much like the real
fgets function as possible; in particular, make sure that it has the proper return value. To
avoid conflicts with the standard library, don't name your function fgets.

(b) Write your own version of fputs, following the same rules as in part (a).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_FILE "read.txt"
#define WRITE_FILE "write.txt"
#define MAX_BUFFER_SIZE 100

char *my_fgets(char *restrict s, int n, FILE *restrict stream);
int my_fputs(const char *restrict s, FILE *restrict stream);
void terminate(const char *message);

int main(void)
{
    FILE *fpr = fopen(READ_FILE, "r");
    char buffer[MAX_BUFFER_SIZE];
    char *buffer_pointer = buffer;

    if (ferror(fpr))
    {
        snprintf(buffer, MAX_BUFFER_SIZE, "Error in main: cannot open %s for reading.\n", READ_FILE);
        terminate(buffer);
    }

    buffer_pointer = my_fgets(buffer_pointer, MAX_BUFFER_SIZE - 1, fpr);
    
    if (ferror(fpr))
    {
        snprintf(buffer, MAX_BUFFER_SIZE, "Error in main: my_fgets had an error reading %s.\n", READ_FILE);
        terminate(buffer);
    }

    int result = fclose(fpr);

    if (result == EOF)
    {
        snprintf(buffer, MAX_BUFFER_SIZE, "Error in main: fclose EOF when closing file %s.\n", READ_FILE);
        terminate(buffer);
    }

    FILE *fpw = fopen(WRITE_FILE, "w+");

    if (ferror(fpw))
    {
        snprintf(buffer, MAX_BUFFER_SIZE, "Error in main: cannot open %s for writing.\n", WRITE_FILE);
        terminate(buffer);
    }

    result = my_fputs(buffer, fpw);

    if (ferror(fpw))
    {
        snprintf(buffer, MAX_BUFFER_SIZE, "Error in main: my_fputs had an error writing to %s.\n", WRITE_FILE);
        terminate(buffer);
    }

    printf("Wrote %d characters to %s.\n", result, WRITE_FILE);

    result = fclose(fpw);

    if (result == EOF)
    {
        snprintf(buffer, MAX_BUFFER_SIZE, "Error in main: fclose EOF when closing file %s.\n", READ_FILE);
        terminate(buffer);
    }

    return EXIT_SUCCESS;
}

/*
DESCRIPTION
       The fgets() function shall read bytes from stream into the array
       pointed to by s until n-1 bytes are read, or a <newline> is read
       and transferred to s, or an end-of-file condition is encountered.
       A null byte shall be written immediately after the last byte read
       into the array.  If the end-of-file condition is encountered
       before any bytes are read, the contents of the array pointed to
       by s shall not be changed.
RETURN VALUE
       Upon successful completion, fgets() shall return s.  If the
       stream is at end-of-file, the end-of-file indicator for the
       stream shall be set and fgets() shall return a null pointer.  If
       a read error occurs, the error indicator for the stream shall be
       set, fgets() shall return a null pointer, and shall set errno to
       indicate the error.
*/
char *my_fgets(char *restrict s, int n, FILE *restrict stream)
{
    if (stream == NULL)
    {
        return NULL;
    }

    int bytes_read = 0;
    int c;

    while (bytes_read < n - 1)
    {
        c = getc(stream);

        if (ferror(stream))
        {
            return NULL;
        }

        if (c == EOF && bytes_read == 0)
        {
            return NULL;
        }
        else if(c == EOF)
        {
            s[bytes_read] = '\0';
            return s;
        }
        else if(c == '\n')
        {
            s[bytes_read++] = c;
            return s;
        }

        s[bytes_read++] = c;
    }

    return s;
}

/*
DESCRIPTION
       The fputs() function shall write the null-terminated string
       pointed to by s to the stream pointed to by stream.  The
       terminating null byte shall not be written.
RETURN VALUE
       Upon successful completion, fputs() shall return a non-negative
       number. Otherwise, it shall return EOF, set an error indicator
       for the stream, and set errno to indicate the error.
*/
int my_fputs(const char *restrict s, FILE *restrict stream)
{
    size_t length = strlen(s) - 1;
    size_t i = 0;

    for (; i < length; ++i)
    {
        putc(s[i], stream);

        if (ferror(stream))
        {
            return EOF;
        }
    }

    return i;
}

void terminate(const char *message)
{
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
}