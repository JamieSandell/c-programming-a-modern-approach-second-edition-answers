/*
(a) Write a function named capitalize that capitalizes all letters in its argument. The
argument will be a null-terminated string containing arbitrary characters, not just letters.
Use arry subscripting to access the characters in the string. Hint: Use the toupper func-
tion to convert each character to upper case.

(b) Rewrite the capitalize function, this time using pointer arithmetic to access the
characters in the string.
*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

void capitalize(char string[]);
void capitalize_ptr(char *string);

int main(void)
{
    char string1[] = "Jamie";
    char string2[] = "Sandell";

    printf("Capitalising %s using array subscripting: ", string1);
    capitalize(string1);
    printf("%s\n", string1);

    printf("Capitalisaing %s using pointer arithmetic: ", string2);
    capitalize(string2);
    printf("%s\n", string2);

    exit(EXIT_SUCCESS);
}

void capitalize(char string[])
{
    int length = strlen(string);

    for (int i = 0; i < length; i++)
    {
        string[i] = toupper(string[i]);
    }
}

void capitalize_ptr(char *string)
{
    while (*string)
    {
        *string = toupper(*string);
        string++;
    }
}