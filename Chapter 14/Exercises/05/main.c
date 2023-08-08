/*
Let TOUPPER be the following macro:

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
Let s be a string and let i be an int variable. Show the output produced by each of the fol-
lowing program fragments.

(a) strcpy(s, "abcd");
    i = 0;
    putchar(TOUPPER(s[++i]));

(b) strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));

(a) Outputs D.
(b) Outputs 2.
*/