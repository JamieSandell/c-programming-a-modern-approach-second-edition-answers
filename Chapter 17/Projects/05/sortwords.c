/*
Write a program that sorts a series of words entered by the user:

Enter word: foo
Enter word: bar
Enter word: baz
Enter word: quux
Enter word:

In sorted order: bar baz foo quux

Assume that each word is no more than 20 characters long. Stop reading when the user
enters an empty word (i.e., presses Enter without entering a word). Store each word in a
dynamically allocated string, using an array of pointers to keep track of the strings, as in the
remind2.c program (Section 17.2). After all words have been read, sort the array (using
any sorting technique) and then use a loop to print the words in sorted order. Hint: Use the
read_line function to read each word, as in remind2.c.
*/

#define MAX_WORDS 4
#define MAX_LENGTH 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_words(char **words, int number_of_words);
int pstrcmp(const void *a, const void *b);
void read_line(char *destination);

int main(void)
{
    char *words[MAX_WORDS];
    int number_of_words = 0;

    for (int word = 0; word < MAX_WORDS; ++word)
    {
        words[word] = malloc(sizeof(char) * MAX_LENGTH + 1);

        if (words[word] == NULL)
        {
            printf("Error! Couldn't allocate memory.\n");
            return EXIT_FAILURE;
        }

        read_line(words[word]);
        ++number_of_words;
    }

    qsort(words, number_of_words, sizeof(char *), pstrcmp);

    print_words(words, number_of_words);

    for (int word = 0; word < number_of_words; ++word)
    {
        free(words[word]);
    }

    return EXIT_SUCCESS;
}

void print_words(char **words, int number_of_words)
{
    printf("In sorted order: ");
    for (int word = 0; word < number_of_words; ++word)
    {
        printf("%s ", *words++);
    }

    printf("\n");
}

int pstrcmp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

void read_line(char *destination)
{
    int c;
    int num_chars = 0;

    printf("Enter a word (max length: %d):", MAX_LENGTH);

    while ((c = getchar()) != EOF && num_chars < MAX_LENGTH && c != '\n')
    {
        *destination++ = c;
    }

    *destination = '\0';
}