/*
The following function supposedly creates an identical copy of a string. What's wrong with
the function?

char *duplicate(const char *p)
{
    char *q;

    strcpy(q, p);
    return q;
}

q hasn't been initialised to a memory location, and it's scope is limited to the function.
*/