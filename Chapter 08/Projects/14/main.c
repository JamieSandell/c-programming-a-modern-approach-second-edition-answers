/*
Write a program that reverses the words in a sentence:

Enter a sentence: you can cage a swallow can't you?
Reversal of sentence: you can't swallow a cage can you?

Hint: Use a loop to read the characters one by one and store them in a one-dimensional
char array. Have the loop stop at a period, question mark, or exclamation point (the "termi-
nating character"), which is saved in a separate char variable. Then use a second loop to
search backward through the array for the beginning of the last word. Print the last word,
then search backward for the next-to-last word. Repeat until the beginning of the array is
reached. Finally, print the terminating character.
*/

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 200

int main(void)
{
    char sentence[LENGTH] = {0};
    char c;
    int count = 0;
    int start_index;
    int end_index;
    char terminating_character;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n' && count < LENGTH)
    {
        if (c == '.' || c == '?' || c == '!')
        {
            terminating_character = c;
            break;
        }

        sentence[count++] = c;
    }

    printf("Reversal of sentence: ");

    start_index = count;

    while (start_index >= 0)
    {
        while (sentence[--start_index] != ' ' && start_index != 0)
        {
            ;
        }

        end_index = (start_index == 0 ? 0 : start_index + 1);

        while (sentence[end_index] != ' ' && sentence[end_index] != '\0')
        {
            putchar(sentence[end_index++]);
        }

        if (start_index >= 0)
        {
            putchar(' ');
        }
    }

    printf("\b%c\n", terminating_character);

    return EXIT_SUCCESS;
}