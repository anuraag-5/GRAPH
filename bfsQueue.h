#include<stdio.h>
#include<stdlib.h>

int globalSize = 0;

typedef struct queue {
    int data;
    struct queue *next;
} Queue;

Queue *createQueueNode(int data) {
    Queue *newNode = (Queue *)malloc(sizeof(Queue));
    newNode -> data = data;
    newNode -> next = NULL;
    globalSize++;

    return newNode;
}

Queue *push(Queue *q, int data) {
    if(q == NULL) return createQueueNode(data);

    Queue *temp = q;

    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = createQueueNode(data);
    return q;
}

Queue *pop(Queue *q) {
    if(q == NULL)return q;

    Queue *temp = q -> next;
    free(q);
    globalSize--;

    return temp;
}

int front(Queue *q) {;
    return q -> data;
}

int isEmpty(Queue *q){
    return q == NULL;
}