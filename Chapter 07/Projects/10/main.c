/*
Write a program that counts the number of vowels (a, e, i, o and u) in a sentence:

Enter a sentence: And that's the way it is.

Your sentence contains 6 vowels.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int input;
    int vowel_count = 0;

    printf("Enter a sentence: ");
    
    while ((input = getchar()) != '\n')
    {
        switch (input = toupper(input))
        {
            case 'A': // fall through
            case 'E': // fall through
            case 'I': // fall through
            case 'O': // fall through
            case 'U':
            {
                ++vowel_count;
                break;
            }
            default:
            {
                break;
            }
        }
    }

    printf("Your sentence contains %d vowels.", vowel_count);

    return EXIT_SUCCESS;
}