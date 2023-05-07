/*
Write the following function:

void swap(int *p, int *q);
When passed the addresses of two variables, swap should exchange the values of the vari-
ables:

swap(&i, &j);    // exchanges values of i and j

void swap(int *p, int *q)
{
    int temp = *q;

    *q = *p; // not q = p as they're copies of the pointers passed in.
    *p = temp;
}
*/