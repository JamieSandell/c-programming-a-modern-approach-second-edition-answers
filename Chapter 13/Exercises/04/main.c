/*
Modify the read_line function in each of the following ways:

(a) Have it skip whitespace before beginning to store input characters.
(b) Have it stop reading at the first whitespace character. Hint: To determine whether or
    not a character is whitespace, call the isspace function.
(c) Have it stop reading at the first newline character, then store the newline character in
    the string.
(d) Have it leave behind characters that it doesn't have room to store.
*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

int my_read_line(char *line, int max_size);

int main(void)
{
    char name[MAX_SIZE + 1];
    int count;

    count = my_read_line(name, MAX_SIZE);
    printf("%s\nCharacters read: %d\n", name, count);

    exit(EXIT_SUCCESS);
}

// max_size should not include the null terminating character
int my_read_line(char *line, int max_size)
{
    int count = 0;
    char c;

    // Skip leading whitespace
    while (((c = getchar()) != '\n' && c != EOF) && count < max_size)
    {
        if (isspace(c) == 0) // not a whitespace char
        {
            count++;
            *line++ = c;
            break;
        }
    }

    while (((c = getchar()) != '\n' && c != EOF && !isspace(c)) && count < max_size)
    {
        count++;
        *line++ = c;
    }

    *line = '\0';

    return count;
}