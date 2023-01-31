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
*/