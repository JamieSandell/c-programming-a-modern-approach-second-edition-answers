/*
Write the following function:

void remove_filename(char *url);

url points to a string containing a URL (Uniform Resource Locator) that ends with a file
name (such as "http://www.knking.com/index.html"). The function should
modify the string by removing the file name and the preceding slash. (In this example, the
result will be "http://www.knking.com".) Incorporate the "search for the end of a
string" idiom into your function. Hint: Have the function replace the last slash in the string
by a null character.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_filename(char *url)
{
    char *p = url + strlen(url);

    while (*p-- != '/')
    {
        ;
    }

    *++p = '\0';
}

int main(void)
{
    char url[] = "http://www.knking.com/index.html";

    printf("url: %s\n", url);
    remove_filename(url);
    printf("url: %s\n", url);

    exit(EXIT_SUCCESS);
}