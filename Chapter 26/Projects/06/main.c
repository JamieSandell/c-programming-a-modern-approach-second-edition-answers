/*
Write programs that display the current date and time in each of the following formats. Use
strftime to do all or most of the formatting.

(a) Sunday, June 3, 2007  05:48p
(b) Sun, 3 Jun 07  17:48
(c) 06/03/07  5:48:34 PM
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 100

int main(void)
{
    char buffer[BUFFER_SIZE];
    time_t now = time(NULL);
    struct tm now_t = *localtime(&now);
    size_t length = strftime(buffer, BUFFER_SIZE, "%A, %B %d, %Y\t%I:%M%p", &now_t);
    buffer[length - 1] = '\0';
    printf("%s\n", buffer);

    strftime(buffer, BUFFER_SIZE, "%a, %d %b %y\t%I:%M", &now_t);
    printf("%s\n", buffer);

    strftime(buffer, BUFFER_SIZE, "%m/%d/%y\t%I:%M:%S %p", &now_t);
    printf("%s\n", buffer);

    return EXIT_SUCCESS;
}