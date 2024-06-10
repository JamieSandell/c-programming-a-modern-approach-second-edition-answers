/*
Many versions of <string.h> provide additional (nonstandard) functions, such as those
listed below. Write each function using only the features of the C standard.

(a) strdup(s) -- Returns a pointer to a copy of s stored in memory obtained by calling
    malloc. Returns a null pointer if enough memory couldn't be allocated.
(b) stricmp(s1, s2) -- Similar to strcmp, but ignores the case of letters.
(c) strlwr(s) -- Converts upper-case letters in s to lower case, leaving other characters
    unchanged; returns s.
(d) strrev(s) -- Reverses the characters in s (except the null character); returns s.
(e) strset(s, ch) -- Fills s with copies of the character ch; returns s.

If you test any of these functions, you may need to alter its name. Function whose names
begin with str are reserved by the C standard.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_malloc(size_t size);
char* my_strdup(const char *s);
int my_stricmp(const char *s1, const char *s2);
char* my_strlwr(char *s);
char* my_strrev(char *s);
char* my_strset(char *s, char ch);
void toupper_str(char *s);

int main(void)
{
    char jamie[] = "Jamie";
    char *dup_jamie = my_malloc(strlen(jamie + 1));
    char jamie_upper[] = "JAMIE";
    char *jamie_lower = my_malloc(strlen(jamie_upper + 1));

    printf("Testing my_strdup.\n");
    printf("jamie[] = %s\n", jamie);
    dup_jamie = my_strdup(jamie);
    printf("Called my_strdup.\n");
    printf("dup_jame = %s\n\n", dup_jamie);

    printf("Testing my_stricmp with %s compared (insensitive) with %s.\n", jamie, jamie_upper);
    if (my_stricmp(jamie, jamie_upper) == 0)
    {
        printf("%s and %s are equal.\n\n", jamie, jamie_upper);
    }
    else
    {
        printf("%s and %s are not equal.\n\n", jamie, jamie_upper);
    }

    printf("Testing my_strlwr\n");
    printf("After calling my_strlwr on %s\n", jamie_upper);
    printf("The result is: %s\n\n", my_strlwr(jamie_upper));

    printf("Testing my_strrev.\n");
    printf("%s reversed is ", jamie_upper);
    printf("%s\n\n", my_strrev(jamie_upper));

    printf("Testing my_strset.\n");
    char c = '!';
    char *original = my_strdup(jamie);
    printf("%s filled with %c is: %s\n\n", original, c, my_strset(jamie, c));

    free(dup_jamie);
    free(jamie_lower);
    free(original);

    return EXIT_SUCCESS;
}

void* my_malloc(size_t size)
{
    void *memory;

    if ((memory = malloc(size)) == NULL)
    {
        fprintf(stderr, "Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    return memory;
}

char* my_strdup(const char *s)
{
    char *p = my_malloc(strlen(s) + 1);
    return strncpy(p, s, strlen(s));
}

int my_stricmp(const char *s1, const char *s2)
{
    char *p1 = my_malloc(strlen(s1) + 1);
    char *p2 = malloc(strlen(s2) + 1);

    strcpy(p1, s1);
    strcpy(p2, s2);
    toupper_str(p1);
    toupper_str(p2);

    return strcmp(p1, p2);
}

char* my_strlwr(char *s)
{
    char *start = s;

    while (*s != '\0')
    {
        *s = tolower(*s);
        ++s;
    }

    return start;
}

char* my_strrev(char *s)
{
    char *original = my_strdup(s);
    char *end = original + strlen(original) - 1;
    char *start = original;
    char *current = s;

    while (end >= start)
    {
        *current = *end;
        ++current;
        --end;
    }
    
    free(original);

    return s;
}

char* my_strset(char *s, char ch)
{
    memset(s, ch, strlen(s));

    return s;
}

void toupper_str(char *s)
{
    while (*s != '\0')
    {
        *s = toupper(*s);
        ++s;
    }    
}