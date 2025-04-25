#include<stdio.h>
#include<stdlib.h>

int globalSize = 0;

typedef struct queue {
    int data[2];
    struct queue *next;
} Queue;

Queue *createQueueNode(int data, int dist) {
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode -> data[0] = data;
    newNode -> data[1] = dist;
    newNode -> next = NULL;
    globalSize++;

    return newNode;
}

Queue *push(Queue *q, int data, int dist) {
    if(q == NULL) return createQueueNode(data, dist);

    Queue *temp = q;

    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = createQueueNode(data, dist);
    return q;
}

Queue *pop(Queue *q) {
    if(q == NULL)return q;

    Queue *temp = q -> next;
    free(q);
    globalSize--;

    return temp;
}

int *front(Queue *q) {;
    return &(q -> data[0]);
}

int isEmpty(Queue *q){
    return q == NULL;
}