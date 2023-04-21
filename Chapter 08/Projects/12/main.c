/*
Modify Programming Project 5 from Chapter 7 so that the SCRABBLE values of the letters
are stored in an array. The array wil have 26 elements, corresponding to the 26 letters of the
alphabet. For example, element 0 of the array will store 1 (because the SCRABBLE value of the
letter B is 3), and so forth. As each character of the input word is read, the program will use
the array to determine the SCRABBLE value of that character. Use an array initializer to set
up the array.
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

int main(void)
{
    int value = 0;
    int input;
    int scrabble_values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter a word: ");

    while ((input = toupper(getchar())) != '\n')
    {
        value += scrabble_values[input - 'A'];
    }

    printf("Scrabble value: %d\n", value);

    return EXIT_SUCCESS;
}