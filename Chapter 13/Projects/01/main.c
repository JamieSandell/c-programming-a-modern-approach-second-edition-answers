/*
Write a program that finds the "smallest" and "largest" in a series of words. After the user
enters the words, the program will determine which words would come first and last if the
words were listed in dictionary order. The program must stop accepting input when the user
enters a four-letter word. Assume that no word is more than 20 letters long. An interactive
session with the program might look like this:

Enter word: dog
Enter word: zebra
Enter word: rabbit
Enter word: catfish
Enter word: walrus
Enter word: cat
Enter word: fish

Smallest word: cat
Largest word: zebra

Hint: Use two strings named smallest_word and largest_word to keep track of the
"smallest" and "largest" words entered so far. Each time the user enters a word, use
strcmp to compare it with smallest_word; if the new word is "smaller", use strcpy
to save it in smallest_word. Do a similar comparison with largest_word. Use
strlen to determine when the user has entered a four-letter word.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 20

int main(void)
{
    char input[LENGTH + 1];
    char smallest[LENGTH + 1];
    char largest[LENGTH + 1];

    printf("Enter word: ");
    scanf("%s", input);
    strcpy(smallest, input);
    strcpy(largest, input);

    while (strlen(input) != 4)
    {
        printf("Enter word: ");
        scanf("%s", input);

        if (strcmp(smallest, input) > 0)
        {
            strcpy(smallest, input);
        }

        if (strcmp(largest, input) < 0)
        {
            strcpy(largest, input);
        }
    }

    printf("\nSmallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);
    

    exit(EXIT_SUCCESS);
}