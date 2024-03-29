/*
Let f be the following function:

int f(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        if (*p2 == '\0') break;
    }
    return p1 - s;
}

(a) What is the value of f("abcd", "babc")? Pointer to s[3] minus pointer to s[0] = 3.
(b) What is the value of f("abcd", "bcd")? Pointer to s[0] minus pointer to s[0] = 0.
(c) In general, what value does f return when passed two strings s and t?
    It returns the address of the pointer of the first character in s that doesn't have
    a matching character in t minus the address of the first character in s. This is
    equivalent to returning the index of that particular character in s.
*/