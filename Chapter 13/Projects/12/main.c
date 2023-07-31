/*
Modify Programming Project 14 from Chapter 8 so that it stores the words in a two-
dimensional char array as it reads the sentence, with each row of the array storing a sin-
gle word. Assume that the sentence contains no more than 30 words and no word is more
than 20 characters long. Be sure to store a null character at the end of each word so that it
can be treated as a string.
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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 200
#define MAX_WORDS 30
#define MAX_WORD_LENGTH 20

int main(void)
{
    char sentence[MAX_WORDS][MAX_WORD_LENGTH + 1];
    int input;
    char (*ptr_word)[MAX_WORD_LENGTH + 1] = sentence;
    char *ptr_char = ptr_word[0];
    char terminating_character;

    /*
    Traverse the slots for the words one word at a time.
    Read into the word slots one character at a time.
    If the max number of words is exceeded exit, with an error.
    If the number of characters exceeds the character limit for a word, exit with an error.
    Terminate each word with a \0
    Store the terminating character ('.', '?', '!')
    */

   while (true)
   {
    if (ptr_word >= sentence + MAX_WORDS)
    {
        printf("The number of words exceeded the maximum of %d.", MAX_WORDS);
        exit(EXIT_FAILURE);
    }    

    if (ptr_char >= ptr_word[0] + MAX_WORD_LENGTH)
    {
        printf("The number of characters for the word execeeds the maxmimum of %d", MAX_WORD_LENGTH);
        exit(EXIT_FAILURE);
    }

    input = getchar();

    if (input == '\n' || input == EOF)
    {
        *ptr_char = '\0';
        break;
    }

    if (input == '.' || input == '?' || input == '!')
    {
        terminating_character = input;
        *ptr_char = '\0';
        break;
    }

    if (input == ' ') // assumes only one space between words
    {
        *ptr_char = '\0';
        ++ptr_word;
        ptr_char = ptr_word[0];
        continue;
    }

    *ptr_char = input;
    ptr_char++;
   }

   while (ptr_word > sentence)
   {
    printf("%s ", *ptr_word);
    --ptr_word;
   }

   //--ptr_word;
   printf("%s%c\n", *ptr_word, terminating_character);
   
   return EXIT_SUCCESS;
}