/*
Write a program that translates an alphabetic phone number into numeric form:

Enter phone number: CALLATT
2255288
(In case you don't have a telephone nearby, here are the letters on the keys: 2=ABC, 3=DEF,
4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY.) If the original phone number contains
nonalphabetic characters (digits or punctuation, for example), leave them unchanged:

Enter phone number: 1-800-COL-LECT
1-800-265-5328

You may assums that any letteres entered by the user are upper case.
*/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main(void)
{
    int input;

    while ((input = getchar()) != '\n')
    {
        switch (input)
        {
            case 'A': // fall through
            case 'B': // fall through
            case 'C':
            {
                printf("2");
                break;
            }
            case 'D': // fall through
            case 'E': // fall through
            case 'F':
            {
                printf("3");
                break;
            }
            case 'G': // fall through
            case 'H': // fall through
            case 'I': // fall through
            {
                printf("4");
                break;
            }
            case 'J': // fall through
            case 'K': // fall through
            case 'L':
            {
                printf("5");
                break;
            }
            case 'M': // fall through
            case 'N': // fall through
            case 'O':
            {
                printf("6");
                break;
            }
            case 'P': // fall through
            case 'R': // fall through
            case 'S': // missing 'Q', as that's how it's written in the book.
            {
                printf("7");
                break;
            }
            case 'T': // fall through
            case 'U': // fall through
            case 'V':
            {
                printf("8");
                break;
            }
            case 'W': // fall through
            case 'X': // fall through
            case 'Y': // missing 'Z', as that's how it's written in the book.
            {
                printf("9");
                break;
            }
            default:
            {
                printf("%c", input);
                break;
            }

            printf("\n");
        }
    }

    return EXIT_SUCCESS;
}