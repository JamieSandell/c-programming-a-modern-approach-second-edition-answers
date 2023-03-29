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

int main(void)
{
    int value = 0;
    int input;

    printf("Enter a word: ");

    while ((input = toupper(getchar())) != '\n')
    {
        switch (input)
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

    return EXIT_SUCCESS;
}