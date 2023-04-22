/*
Modify Programming Project 11 from Chapter 7 so that the program labels its output:

Enter a first and last name: Lloyd Fosdick
You entered the name: Fosdick, L.

The program will need to store the last name (but not the first name) in an array of characters
until it can be printed. You may assume that the last name is no more than 20 characters long.
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

#define LENGTH 21

int main(void)
{
    char initial;
    char input;
    char last_name[LENGTH];
    int char_count = 0;

    printf("Enter a first and last name: ");
    scanf("%c", &initial);

    // scanf will put characters back on the buffer as we can only fit one character in initial.
    // read up until the first space
    while ((input = getchar()) != ' ') { ; }

    // ignores spaces between the first and last names
    while ((input = getchar()) == ' ') { ; }

    // get the last name
    do
    {
        last_name[char_count++] = input;
    } while ((input = getchar()) != '\n' && input != ' ');
    last_name[char_count] = '\0';

    printf("You entered the name: %s, %c\n", last_name, initial);

    return EXIT_SUCCESS;
}