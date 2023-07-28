/*
Modify Programming Project 13 from Chapter 7 so that it includes the following function:

double compute_average_word_length(const char *sentence);

The function returns the average length of the words in the string pointed to by sentence.
*/

/*
Write a program that calculates the average word length for a sentence:

Enter a sentence: It was deja vu all over again.
Average word length: 3.4

For simplicity, your program should consider a punctuation mark to be part of the word to
which it is attached. Display the average word length to one decimal place.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 30
#define MAX_SIZE (MAX_WORD_LENGTH + 1) * MAX_WORDS

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[MAX_SIZE];
    char *p = sentence;

    printf("Enter a sentence: ");

    while ((*p = getchar()) != '\n' && *p != EOF && p <= p + MAX_SIZE)
    {
        p++;
    }

    *p = '\0';


    printf("Average word length: %.1f\n", compute_average_word_length(sentence));

    return EXIT_SUCCESS;
}

double compute_average_word_length(const char *sentence)
{
    const char *p = sentence;
    int total_word_length = 0;
    int number_of_words = 0;

    while (*p)
    {
        while (*p != ' ' && *p != '\0')
        {
            total_word_length++;
            p++;
        }

        if (*p == ' ')
        {
            p++;
        }

        number_of_words++;
    }

    return total_word_length / number_of_words;
}