/*
The Q&A section at the end of this chapter shows how the strcmp function might be writ-
ten using array subscripting. Modify the function to use pointer arithmetic instead.

-- array subscription version
int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == s[t]; i++)
    {
        if (s[i] == '\0')
        {
            return 0;
        }
    }

    return s[i] - t[i];
}

-- pointer arithmetic version

int strcmp(char *s, char t)
{
    while (*s++ == *t++)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }

    return s - t;
}
*/