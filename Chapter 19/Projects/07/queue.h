/*
A queue is similar to a stack, except that items are added at one end but removed from the
other in a FIFO (first-in, first-out) fashion). Operations on a queue might include:

    Inserting an item at the end of the queue  
    Removing an item from the beginning of the queue  
    Returning the first item in the queue (without changing the queue)  
    Returning the last item in the queue (without changing the queue)  
    Testing whether the queue is empty

Write an interface for a queue module in the form of a header file named queue.h.
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type *Queue;

Queue create(int size);
void destroy(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);
Item get_first(Queue q);
Item get_last(Queue q);
bool is_empty(Queue q);

#endif