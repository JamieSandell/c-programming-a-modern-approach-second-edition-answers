/*
(a) Write your own version of the fgets function. Make it behave as much like the real
fgets function as possible; in particular, make sure that it has the proper return value. To
avoid conflicts with the standard library, don't name your function fgets.

(b) Write your own version of fputs, following the same rules as in part (a).
*/

#include <stdio.h>
#include <stdlib.h>

char *my_fgets(char *restrict s, int n, FILE *restrict stream);

int main(void)
{
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

    unsigned int bytes_read = 0;
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
}