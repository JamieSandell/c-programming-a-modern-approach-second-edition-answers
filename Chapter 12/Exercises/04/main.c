/*
Rewrite the make_empty, is_empty and is_full functions of Section 10.2 to use the
pointer variable top_ptr instead of the integer variable top.

#define STACK_SIZE 100

int *top_ptr = contents;

void make_empty(void)
{
    top_ptr = contents;
}

bool is_empty(void)
{
    return top_ptr == contents; // the array implicitly converts to pointer to first element. This implicit conversion is called decaying.
}

bool is_full(void)
{
    return top_ptr == &contents[STACK_SIZE - 1];
}
*/