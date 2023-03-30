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

int main(void)
{
    char initial;
    char input;

    printf("Enter a first and last name: ");
    scanf("%c", &initial);

    // scanf will put characters back on the buffer as we can only fit one character in initial.
    // read them all and ignore them
    while ((input = getchar()) != ' ') { ; }

    // ignores spaces between the first and last names
    while ((input = getchar()) == ' ') { ; }

    // get the last name
    do
    {
        putchar(input);
    } while ((input != getchar()) != '\n' && input != ' ');

    printf(", %c.\n", initial);    

    return EXIT_SUCCESS;
}