/*
What will be the contents of the a array after the following statements are executed?

#define N 10

int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *p = &a[0], *q = &a[N-1], temp;

while (p < q) {
    temp = *p;
    *p++ = *q;
    *q-- = temp;
}

first run-through:
temp = 1
*p = *q (10) and then p is incremented (p = &a[1])
*q = temp (*q = 1) and then q is decremented (q = &a[8])

so it's reversing the array to become:
10, 9, 8, 7, 6, 5, 4, 3, 2, 1
*/