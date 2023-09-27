/*
(a) Show what the following program will look like after preprocessing. you may ignore any lines added to the program as a result of including the <stdio.h> header.

#include <stdio.h>

#define N 100

void f(void);

int main(void)
{
    f();
#ifdef N
#undef N
#endif
    return 0;
}

void f(void)
{
#if defined(N)
    printf("N is %d\n", N);
#else
    printf("N is undefined\n");
#endif
}
*/

/*
contents from stdio.h

void f(void);

int main(void
{
    f();
    return 0;
}

void f(void)
{
    printf("N is undefined\n");
}
*/

/*
N is undefined

*/