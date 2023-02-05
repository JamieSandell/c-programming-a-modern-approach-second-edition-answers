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

sum = 0;
for (i = 0; i < 10; i++) {
    if (i % 2)
        continue;
    sum += i;
}
printf("%d\n", sum);

0 - 0 % 0 = 0 so 0 += 0 = 0
1 - 1 % 2 = 0.5 so continue
2 - 2 % 2 = 0 so 0 += 2 = 2
3 - 3 % 2 = 1 so continue
4 - 4 % 2 = 0 so 2 += 4 = 6
5 - 5 % 2 = 1 so continue
6 - 6 % 2 = 0 so 6 += 6 = 12
7 - 7 % 2 = 1 so continue
8 - 8 % 2 = 0 so 12 += 8 = 20
9 - 9 % 2 = 1 so continue

prints 20

12. The following "prime-testing" loop appeared in Section 6.4 as an example:

for (d = 2; d < n; d++)
    if (n % d == 0)
        break;

This loop isn't very efficient. It's not necessary to divide n by all numbers between 2 and
n - 1 to determine whether it's prime. In fact, we only need check divisors up to the square
root of n. Modify the loop to take advantage of this fact. Hint: Don't try to compute the
square root of n; instead, compare d * d with n.

for (d = 2; d * d <= n; d++)
    if (n % d == 0)
        break;

13. Rewrite the following loop so that its body is empty:

for (n = 0; m > 0; n++)
    m /= 2;

for (n = 0; m > 0; n++, m /= 2)

14. Find the error in the following program fragment and fix it.

if (n % 2 == 0);
    printf("n is even\n");

The semicolon at the end of the if, means the printf is always printed. It should be:

if (n % 2 == 0)
    printf("n is even\n");
*/