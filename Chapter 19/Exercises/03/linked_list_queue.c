/*
(b) Write a linked-list implementation of the queue module described in Exercise 1. Use
two pointers, one pointing to the first node in the list and the other pointing to the last node.
When an item is inserted into the queue, add it to the end of the list. When an item is
removed from the queue, delete the first node in the list.
*/

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

static void terminate(const char *message);

struct queue_node
{
    Item item;
    struct queue_node *next;
};

struct queue_type
{
    struct queue_node *front;
    struct queue_node *last;
    int count;
    int size; // max number of items
};

static int size;
struct queue_type *first_node;
struct queue_type *last_node;

Queue create(int size)
{
    Queue q = malloc(sizeof(struct queue_type));

    if (q == NULL)
    {
        terminate("Error in create: queue could not be created.");
    }

    q->front = NULL;
    q->last = NULL;
    q->count = 0;
    q->size = size;

    return q;
}

void destroy(Queue q)
{
    struct queue_node *temp;

    while (q->front != NULL)
    {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}