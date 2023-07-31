/*
Modify Programming Project 16 from Chapter 8 so that it includes the following function:

bool are_anagrams(const char *word1, const char *word2);

The function returns true if the strings pointed to by word1 and word2 are anagrams.
*/

/*
Write a program that test whether two words are anagrams (permutations of the same letters):

Enter first words: smartest
Enter second words: mattress
The words are anagrams.

Enter first word: dumbest
Enter second word: stumble
The words are not anagrams.

Write a loop that reads the first word, character by character, using an array of 26 integers to
keep track of how many times each letter has been seen. (For example, after the word smartest has
been read, the array should contain the values 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 2 2 0 0 0 0 0 0,
reflecting the fact that smartest contains one a, one e, one m, one r, two s's and two t's.) Use
another loop to read the second word, except this time decrementing the corresponding array element
as each letter is read. Both loops should ignore any characters that aren't letters, and both should
treat upper-case letters in the same way as lower-case letters. After the second word has been read,
use a third loop to check whether all the elements in the array are zero. If so, the words are anagrams.

Hint: You may wish to use the functions from <ctype.h>, such as isalpha and tolower.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 26

bool are_anagrams(const char *word1, const char *word2);
void populate_counts_one(const char *word, bool first_word);

int counts_one[LENGTH] = {0};

int main(void)
{
    /*
    int counts_one[LENGTH] = {0};
    int c;
    bool anagram = true;

    printf("Enter the first word: ");

    while((c = getchar()) != '\n')
    {
        if (isalpha(c) == 0)
        {
            continue;
        }

        c = tolower(c);
        counts_one[c - 'a']++;
    }    

    printf("Enter the second word: ");

    while((c = getchar()) != '\n')
    {
        if (isalpha(c) == 0)
        {
            continue;
        }

        c = tolower(c);
        counts_one[c - 'a']--;
    }

    for (int i = 0; i < LENGTH; i++)
    {
        if (counts_one[i] != 0)
        {
            anagram = false;
            break;
        }
    }

    if (anagram)
    {
        printf("The words are anagrams.\n");
    }
    else
    {
        printf("The words are not anagrams.\n");
    }
    */

   char word1[] = "angel";
   char word2[] = "glean";

   if (are_anagrams(word1, word2))
   {
    printf("The words are anagrams.\n");
   }
   else
   {
    printf("The words are not anagrams.\n");
   }

    exit(EXIT_SUCCESS);
}

void populate_counts_one(const char *word, bool first_word)
{
    char c;

    while(*word)
    {
        if (isalpha(*word) == 0)
        {
            word++;
            continue;
        }

        c = tolower(*word);
        (first_word) ? counts_one[c - 'a']++ : counts_one[c - 'a']--;
        word++;
    }
}

bool are_anagrams(const char *word1, const char *word2)
{
    populate_counts_one(word1, true);
    populate_counts_one(word2, false);

    for (int i = 0; i < LENGTH; i++)
    {
        if (counts_one[i] != 0)
        {
            return false;
        }
    }

    return true;
}