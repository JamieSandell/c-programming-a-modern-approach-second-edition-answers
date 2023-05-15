/*
Suppose that the following declarations are in effect:

int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
int *p = &a[1], *q = &a[5];

(a) What is the value of *(p+3)?
14

(b) What is the value of *(q-3)?
34

(c) What is the value of q - p?
&a[4]

(d) Is the condition p < q true or false?
true

(e) Is the condition *p < *q true or false?
false
*/