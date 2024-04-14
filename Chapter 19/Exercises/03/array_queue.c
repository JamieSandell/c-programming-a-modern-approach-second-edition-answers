/*
(a) Write an array based implementation of the queue module described in Exercise 1. Use
three integers to keep track of the queue's status, with one integer storing the position of the
first empty slot in the array (used when an item is inserted), the second storing the position
of the next item to be removed, and the third storing the number of items in the queue.
An insertion or removal that would caused either of the first two integers to be incremented past
the end of the array should instead reset the variable to zero, thus causing it to "wrap
around" to the beginning of the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue_type
{
    Item *contents;
    int first_empty_slot;
    int next_item_to_be_removed;
    int count;
    int size; // max number of elements for contents
};

static void terminate(const char *message);

int main(void)
{
    return EXIT_SUCCESS;
}

Queue create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));

    if (q == NULL)
    {
        terminate("Error in create: queue could not be created.");
    }

    q->contents = malloc(size * sizeof(Item));

    if (q->contents == NULL)
    {
        free(q);
        terminate("Error in create: queue contents could not be created.");
    }

    q->first_empty_slot = 0;
    q->next_item_to_be_removed = 0;
    q->count = 0;
    q->size = size;
}

void destroy(Queue q)
{
    free(q->contents);
    free(q);
}

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}