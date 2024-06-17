/*
(a) Write a program that calls the rand function 1000 times, printing the low-order bit of
each value it returns (0 if the return value is even, 1 if it's odd). Do you see any patterns?
(Often, the last few bits of rand's return value aren't especially random)?

(b) How can we improve the randomness of rand for generating numbers within a small range?
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    for (int i = 0; i < 1000; ++i)
    {
        printf("%d\n", rand() % 2 ? 1 : 0);
    }

    return EXIT_SUCCESS;
}

//

/*
My output looked fine. http://knking.com/books/c2/answers/c26.html) states that
"rand() / (RAND_MAX / N + 1) often gives bettwe results than rand() % N."
*/