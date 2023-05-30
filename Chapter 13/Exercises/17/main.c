/*
Write the following function:

bool test_extension(const char *file_name,
                    const char *extension);

file_name points to a string containing a file name. The function should return true if
the file's extension matches the string pointed to by extension, ignoring the case of let-
ters. For example, the call test_extension("memo.txt", "TXT") would return
true. Incorporate the "search for the end of a string" idiom into your function. Hint: Use
the toupper function to convert characters to upper-case before comparing them.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 10

bool test_extension(const char *file_name, const char *extension);

int main(void)
{
    if (test_extension("memo.txt", "TXT"))
    {
        printf("file extension txt found in memo.txt\n");
    }

    exit(EXIT_SUCCESS);
}

bool test_extension(const char *file_name, const char *extension)
{
    while (*file_name++ != '.')
    {
        ;
    }

    while (*file_name && *extension)
    {
        if (toupper(*file_name++) != toupper(*extension++))
        {
            return false;
        }
    }

    return true;
}