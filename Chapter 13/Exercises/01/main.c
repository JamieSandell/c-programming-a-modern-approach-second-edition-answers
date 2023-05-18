/*
The following function calls supposedly write a single newline character, but some are
incorrect. Identify which calls don't work and explain why.

(a) printf("%c", '\n');
(b) printf("%c", "\n");
(c) printf("%s", '\n');
(d) printf("%s", "\n");
(e) printf('\n');
(f) printf("\n");
(g) putchar('\n');
(h) putchar("\n");
(i) puts('\n');
(j) puts("\n");
(k) puts("");

(b) won't work as it expects a char but receives a string.
(c) won't work as it expects a string but receives a char.
(e) won't work because it expects a string.
(h) won't work as it expects a char but receives a string.
(i) won't work as it expects a string.
*/