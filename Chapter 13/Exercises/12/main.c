/*
Write the following function:

void get_extension(const char *file_name, char *extension);

file_name points to a string containing a file name. The function should store the exten-
sion on the file name in the string pointed to by extension. For example, if the file name
is "memo.txt", the function will store "txt" in the string pointed to by extension. If
the file name doesn't have an extension, the function should store an empty string (a single
null character) in the string pointed to by extension. Keep the function as simple as pos-
sible by having it use the strlen and strcpy functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

void get_extension(const char *file_name, char *extension);

int main(void)
{
    char file_name[] = "memo.txt";
    char extension[10] = "";

    get_extension(file_name, extension);
    printf("File name of %s is %s\n", file_name, extension);

    exit(EXIT_SUCCESS);
}

void get_extension(const char *file_name, char *extension)
{
    int length = strlen(file_name);
    const char *p = file_name + length;

    while (*p != '.')
    {
        if (p-- == file_name)
        {
            strcpy(extension, "");
            return;
        }
    }

    p++;

    strcpy(extension, p);
}