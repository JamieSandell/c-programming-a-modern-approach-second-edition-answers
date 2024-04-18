#include <stdbool.h>
#include <stdlib.h>
#include "../queue.h"

#define QUEUE_SIZE 5

int main(void)
{
    Queue q1 = create(QUEUE_SIZE);
    Queue q2 = create(QUEUE_SIZE);

    enqueue(q1, 1);
    enqueue(q2, 2);

    int n = dequeue(q1);
    printf("Dequeued %d from q1.\n", n);
    enqueue(q2, n);
    printf("Enqueued %d to q2.\n", n);
    n = dequeue(q1);
    printf("Deqeued %d from q1.\n", n);
    enqueue(q2, n);
    printf("Enqueued %d to q2.\n", n);

    destroy(q1);
    
    while (is_empty(q2) == false)
    {
        printf("Dequeued %d from q2.\n", dequeue(q2));
    }

    n = 3;
    enqueue(q2, n);
    printf("Enqueued %d to q2.\n", n);

    destroy(q2);

    return EXIT_SUCCESS;
}