/*
Write a program that calculates the average word length for a sentence:

Enter a sentence: It was deja vu all over again.
Average word length: 3.4

For simplicity, your program should consider a punctuation mark to be part of the word to
which it is attached. Display the average word length to one decimal place.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c;
    int number_of_words;
    int total_word_length = 0;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n')
    {
        if (c  == ' ')
        {
            ++number_of_words;
        }
        else
        {
            ++total_word_length;
        }
    }
    ++number_of_words;

    printf("Average word length: %.1f\n", total_word_length / number_of_words);

    return EXIT_SUCCESS;
}