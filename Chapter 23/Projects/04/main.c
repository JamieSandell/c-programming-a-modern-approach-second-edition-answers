/*
Write a program that prompts the user to enter a series of words separated by single spaces,
then prints the words in reverse order. Read the input as a string, and then use strtok to
break it into words.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(void)
{
    printf("Enter a series of words separated by single spaces:\n");
    char input[MAX_LINE_LENGTH];
    fgets(input, MAX_LINE_LENGTH, stdin);
    char *token;
    char delimiter[] = " ";
    token = strtok(input, delimiter);
    int count = 1;

    while (token != NULL)
    {
        printf("%d: %s\n", count++, token);
        token = strtok(NULL, delimiter);
    }
    

    return EXIT_SUCCESS;
}