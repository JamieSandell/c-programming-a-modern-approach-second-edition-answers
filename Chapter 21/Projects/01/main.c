/*
Write a program that declares the s structure (see Section 21.4) and prints the sized and off-
sets of the a, b and c members (Use sizeof to find sizes; use offsetof to find off-
sets). Have the program print the size of the entire structure as well. From this information,
determine whether or not the structure has any holes. If it does, describe the location and
size of each.

On my PC it has a 3-byte hole between char a and int b[2], but no hole between int b[2] and float c.
Can conclude that struct elements are padded to 4 byte boundaries.
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct s
{
    char a; // 1 byte offset 0
    int b[2]; // 8 bytes offset 4
    float c; // 4 bytes offset 12
};

int main(void)
{
    struct s my_struct;

    printf("Size of a: %d. Offset of a: %d\n", sizeof(my_struct.a), offsetof(struct s, a));
    printf("Size of b: %d. Offset of b: %d\n", sizeof(my_struct.b[0]) * 2, offsetof(struct s, b));
    printf("Size of c: %d. Offset of c: %d\n", sizeof(my_struct.c), offsetof(struct s, c));
    printf("Size of struct s: %d.\n", sizeof(struct s));

    return EXIT_SUCCESS;
}