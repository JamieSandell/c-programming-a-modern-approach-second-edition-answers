/*
1. What output does the following program fragment produce?

i = 1;
while (i <= 128) {
    printf("%d ", i);
    i *= 2;
}

Outputs:
1 2 4 8 16 32 64 128

2. What output does the following program fragment produce?

i = 9384;
do {
    printf("%d ", i);
    i /= 10;
} while (i > 0);

Outputs:
9384 938 93 9

What output does the following for statement produce?

for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
    printf("%d ", i);

Outputs:
5 4 3 2

4. Which one of the following statements is not equivalent to the other two (assuming that the
loop bodies are the same)?

(a) for (i = 0; i < 10; i++) ...
(b) for (i = 0; i < 10; ++i) ...
(c) for (i = 0; i++ < 10;) ...

(a) and (b) are equivalent. The post-fix and pre-fix operators used here, are evaluated after a loop iteration, so the behaviour of loop is the same for (a) and (b).
(c) on the surface looks like it would be equivalent because of the post-fix operator, however ++ has operator precedence over <, so i will be incremented and then
checked if it is less than 10.

5. Which one of the following statements is not equivalent to the other two (assuing that the
loop bodies are the same)?

(a) while (i < 10) {...}
(b) for (; i < 10;) {...}
(c) do {...} while (i < 10);

(a) and (b) are equivalent. (c) will always execute the body of the loop at least once (even if i was >= 10).

6. Translate the program fragment of Exercise 1 into a single for statement.

i = 1;
for (int i = 1; i <= 128l i *= 2) {
    printf("%d ", i);
}

7. Translate the program fragment of Exercise 2 into a single for statement.

i = 9384;
do {
    printf("%d ", i);
    i /= 10;
} while (i > 0);

for (int i = 9384, i > 0; i /= 10)
{
    printf("%d ", i);
}

8. What output does the following for statement produce?

for (i = 10; i >= 1; i /= 2)
    printf("%d ", i++);

Output: 10 5 3 2 and then 1 infinitely.

9. Translate the for statement of Exercise 8 into an equivalent while statement. You will
need one statement in addition to the while loop itself.

for (i = 10; i >= 1; i /= 2)
    printf("%d ", i++);

while (i >= 1)
{
    printf("%d ", i++);
    i /= 2;
}

10. Show how to replace a continue statement by an equivalent goto statement.

while (true)
{
    value = function();
    if (value == 0)
    {
        continue;
    }

    do something;
}

while (true)
{
    value = function();
    if (value == 0)
    {
        goto dosomething;
    }

    dosomething:
    do something;
}

11. What output does the following program fragment produce?


*/