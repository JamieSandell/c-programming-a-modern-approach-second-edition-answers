/*
Modify Programming Project 14 from Chapter 8 so that it uses a pointer instead of an inte-
ger to keep track of the current position in the array that contains the sentence.
*/

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
    char *p;
    char *q;
    char terminating_character;

    printf("Enter a sentence: ");

    for (p = sentence; (c = getchar()) != '\n' && p < sentence + LENGTH; p++)
    {
        if (c == '.' || c == '?' || c == '!')
        {
            terminating_character = c;
            break;
        }

        *p = c;
    }

    printf("Reversal of sentence: ");

    while (p >= sentence)
    {
        while (*--p != ' ' && p != sentence)
        {
            ;
        }

        q = (p == sentence ? sentence : p + 1);

        while (*q != ' ' && *q != '\0')
        {
            putchar(*q++);
        }

        if (p >= sentence)
        {
            putchar(' ');
        }
    }

    printf("\b%c\n", terminating_character);

    return EXIT_SUCCESS;
}