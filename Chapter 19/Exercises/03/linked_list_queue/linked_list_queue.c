/*
(b) Write a linked-list implementation of the queue module described in Exercise 1. Use
two pointers, one pointing to the first node in the list and the other pointing to the last node.
When an item is inserted into the queue, add it to the end of the list. When an item is
removed from the queue, delete the first node in the list.
*/

#include <stdlib.h>
#include <stdio.h>
#include "../queue.h"

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

void enqueue(Queue q, Item i)
{
    if (q->count == q->size)
    {
        char buffer[50];
        sprintf(buffer, "Error in enqueue: queue is full. Max size: %d", q->size);
        terminate(buffer);
    }

    struct queue_node *new_node = malloc(sizeof(struct queue_node));

    if (new_node == NULL)
    {
        terminate("Error in enqueue: new_node could not be created.");
    }

    new_node->item = i;
    new_node->next = NULL;

    if (is_empty(q))
    {
        q->front = new_node;
        q->front->next = NULL;
        q->last = new_node;
        q->last->next = NULL;
        q->count++;        
        return;
    }

    if (q->count == 1)
    {
        q->front->next = new_node;
        q->last = new_node;
        q->count++;
        return;
    }

    struct queue_node *current = q->front;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
    q->last = new_node;
    q->count++;
}

Item dequeue(Queue q)
{
    Item i = q->front->item;
    struct queue_node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return i;
}

Item get_first(Queue q)
{
    return q->front->item;
}

Item get_last(Queue q)
{
    return q->last->item;
}

bool is_empty(Queue q)
{
    return q->front == NULL;
}

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}