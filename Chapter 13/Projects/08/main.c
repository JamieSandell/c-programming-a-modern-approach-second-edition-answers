/*
Modify Programming Project 5 from Chapter 7 so that it includes the following function:

int compute_vowel_count(const char *sentence);

The function returns the number of vowels in the string pointed to by the sentence parameter.
*/

/*
In the SCRABBLE Crossword Game, players form words using small tiles, each containing
a letter and a face value. The face value varies from one letter to another, based on the let-
ter's rarity. (Here are the face values: 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K,
8: JX, 10: QZ.) Write a program that computes the value of a word by summing the values
of its letters:

Enter a word: pitfall
Scrabble value: 12

Your program should allow any mixture of lower-case and upper-case letters in the word.
Hint: Use the toupper library function.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

int compute_vowel_count(const char *sentence);

int main(void)
{
    int value = 0;
    char word[LENGTH + 1];
    char *c = word;

    printf("Enter a word: ");

    while ((*c++ = toupper(getchar())) != '\n')
    {
        ;
    }

    *(--c) = '\0';
    c = word;

while (*c)
{
    switch (*c++)
    {
        case 'A': // fall through
        case 'E': // fall through
        case 'I': // fall through
        case 'L': // fall through
        case 'N': // fall through
        case 'O': // fall through
        case 'R': // fall through
        case 'S': // fall through
        case 'T': // fall through
        case 'U':
        {
            value += 1;
            break;
        }
        case 'D': // fall through
        case 'G':
        {
            value += 2;
            break;
        }
        case 'B': // fall through
        case 'C': // fall through
        case 'M': // fall through
        case 'P':
        {
            value += 3;
            break;
        }
        case 'F': // fall through
        case 'H': // fall through
        case 'V': // fall through
        case 'W': // fall through
        case 'Y':
        {
            value += 4;
            break;
        }
        case 'K':
        {
            value += 5;
            break;
        }
        case 'J': // fall through
        case 'X':
        {
            value += 8;
            break;
        }
        case 'Q': // fall through
        case 'Z':
        {
            value += 10;
            break;
        }
        default:
        {
            break;
        }
    }
}

    printf("Scrabble value: %d\n", value);
    printf("Vowel count of %s: %d\n", word, compute_vowel_count(word));

    return EXIT_SUCCESS;
}

int compute_vowel_count(const char *sentence)
{
    int count = 0;

    while (*sentence)
    {
        switch(toupper(*sentence++))
        {
            case 'A': // fallthrough
            case 'E': // fallthrough
            case 'I': // fallthrough
            case 'O': // fallthrough
            case 'U': // fallthrough
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