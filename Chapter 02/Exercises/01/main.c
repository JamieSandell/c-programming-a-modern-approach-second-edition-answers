/*
Create and run Kernighan and Ritchie's famous "hello world" program:

Do you get a warning message from the compiler? If so, what's needed to make it go away?
No I don't because
"The reason why there is no warning from omitted return statement is that it isn't "wrong" - the C standard explicitly allows it, and such a program is well-defined; only, you're not to use the return value if none was actually returned.

Whatever the warnings that are emitted by default are mostly those that the C standard names as constraint violations - a conforming compiler must diagnose these. Hence, using -pedantic-errors or -std=c17 or similar is not going to do anything at all, because it makes the compiler being more pedantic (i.e. more diagnostics-conforming) about following the C standard which says that this is OK after all.

In GCC the warning can be controlled with -Wreturn-type, which will enabled by -Wall too. (Why aren't you using -Wall?!):"
https://stackoverflow.com/questions/52270122/how-do-i-make-the-compiler-warn-me-about-missing-return-value
*/

#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}