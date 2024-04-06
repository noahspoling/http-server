#ifndef REQUEST_H
#define REQUEST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct RequestQueueNode
{
    int clientfd;
    struct RequestQueueNode* next;
} RequestQueueNode;

typedef struct RequestQueue
{
    RequestQueueNode* front;
    RequestQueueNode* back;
    int queue_count;
} RequestQueue;

RequestQueue* initQueue() {
    RequestQueue* queue = (RequestQueue*)malloc(sizeof(RequestQueue));
    queue-> front = queue->back = NULL;
    queue->queue_count = 0;
    return queue;
}

void enqueue(RequestQueue* queue, int clientfd) {
    RequestQueueNode
}

int dequeue(RequestQueue* queue) {
    if (queue->front == NULL) {
        return -1;
    }
}

#endif