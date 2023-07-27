/*
Modify Programming Project 10 from Chapter 7 so that it includes the following function:

int compute_vowel_count(const char *sentence);

The function returns the number of vowels in the string pointed to by the sentence
parameter.
*/

/*
Write a program that counts the number of vowels (a, e, i, o and u) in a sentence:

Enter a sentence: And that's the way it is.

Your sentence contains 6 vowels.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 100

int compute_vowel_count(const char *sentence);

int main(void)
{
    int input;
    char sentence[MAX_SENTENCE_LENGTH + 1];
    char *p = sentence;

    printf("Enter a sentence: ");
    
    while ((input = getchar()) != '\n' && input != EOF && p <= sentence + MAX_SENTENCE_LENGTH)
    {
        *p++ = toupper(input);
    }

    *p = '\0';

    printf("The sentence %s contains %d vowels.", sentence, compute_vowel_count(sentence));

    return EXIT_SUCCESS;
}

int compute_vowel_count(const char *sentence)
{
    int count = 0;
    const char *p = sentence;

    while (*p)
    {
        switch (*p++)
        {
            case 'A': // fall through
            case 'E': // fall through
            case 'I': // fall through
            case 'O': // fall through
            case 'U':
            {
                ++count;
                break;
            }
            default:
            {
                break;
            }
        }
    }

    return count;
}