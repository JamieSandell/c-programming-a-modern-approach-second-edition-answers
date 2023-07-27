/*
Modify Programming Project 11 from Chapter 7 so that it includes the following function:

void reverse_name(char *name);

The function expects name to point to a string containing a first name followed by a last
name. It modifies the string so that the last name comes first, followed by a comma, a space,
the first initial, and a period. The original string may contain extra spaces before the first
name, between the first and last names, and after the last name.
*/

/*
Write a program that takes a first name and a last name entered by the user and displays the
last name, a comma, and the first initial, followed by a period:

Enter a first and last name: Lloyd Fosdick
Fodsick, L.

The user's input may contain extra spaces before the first name, between the first and last
names, and after the last name.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

void reverse_name(char *name);

int main(void)
{
    char name[MAX_NAME_LENGTH + 1];
    char *p = name;

    printf("Enter a first and last name: ");

    while ((*p = getchar()) != '\n' && *p != EOF && p <= name + MAX_NAME_LENGTH)
    {
        p++;
    }

    reverse_name(name);
    printf("%s", name);

    exit(EXIT_SUCCESS);
}

void reverse_name(char *name)
{
    char initial;
    char *p = name;
    char last_name[MAX_NAME_LENGTH + 1];
    char *l = last_name;

    while (*p == ' ') // skip any leading spaces
    {
        p++;
    }

    initial = *p;

    // read up until the first space
    while (*p != ' ')
    {
        p++;
    }

    // ignore spaces between the first and last names
    while (*p == ' ')
    {
        p++;
    }

    while (*p) // store the last name
    {
        *l++ = *p++;
    }
    *l = '\0';

    p = name;
    *p++ = initial;
    *p++ = ',';
    *p++ = ' ';
    l = last_name;

    while (*l)
    {
        *p++ = *l++;
    }

    *p = '\0';
}