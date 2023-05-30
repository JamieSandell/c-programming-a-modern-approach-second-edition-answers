/*
Use the techniques of Section 13.6 to condense the count_spaces function of Section
13.4. In particular, replace the for statement by a while loop.

Original:

int count_spaces(const char *s)
{
    int count = 0;

    for (; *s != '\0'; s++)
    {
        if (*s == ' ')
        {
            count++;
        }
    }

    return count;
}

Solution:

int count_spaces(const char *s)
{
    while (*p++)
    {
        if (*p == ' ')
        {
            count++;
        }
    }
}
*/