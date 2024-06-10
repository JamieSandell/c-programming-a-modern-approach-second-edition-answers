/*
Use strtok to write the following function:

int count_words(char *sentence);

count_words returns the number of words in the string sentence, where a "word" is
any sequence of non-white-space characters. count_words is allowed to modify the string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(char *sentence);

int main(void)
{
    char sentence[] = "Hi, \nmy name \t\nis Jamie.";
    printf("%d words.\n", count_words(sentence));
    return EXIT_SUCCESS;
}

int count_words(char *sentence)
{
    int count = 0;
    char *token;
    char *delimiters = " \t\r\n\v\f";
    token = strtok(sentence, delimiters);

    while (token != NULL)
    {
        ++count;
        token = strtok(NULL, delimiters);
    }

    return count;
}