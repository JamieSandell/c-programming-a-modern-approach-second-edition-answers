/*
Suppose that p has been declared as follows:

char *p = "abc";
Which of the following function calls are legal? Show the output produced by each legal
call, and explain why the others are illegal.

(a) putchar(p);
(b) putchar(*p);
(c) puts(p);
(d) puts(*p);

(a) illegal, expects a char but gets a pointer to a char.
(b) a
(c) abc\n
(d) illegal, expects pointer to a char but gets char.

*/