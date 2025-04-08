#include <stdio.h>
#define MAX 100

struct Queue {
    int data[MAX];
    int rear, front;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

void enqueue(struct Queue *q, int x) {
    if (q->rear == (MAX - 1)) {
        // printf("Queue is full.\n");
        return;
    }

    q->data[++(q->rear)] = x;
    if (q->front == -1) {
        q->front = q->rear;
    }
}

int dequeue(struct Queue *q) {
    if( q -> front == q -> rear) {
        int dequeuedElement = q->data[q->front];
        q -> rear = q -> front = -1;
        return dequeuedElement;
    }

    if (q->rear == -1) {
        // printf("Queue is empty.\n");
        return -111;
    }

    int dequeuedElement = q->data[q->front++];
    return dequeuedElement;
}

int peek(struct Queue *q) {
    if(q -> rear == -1){
        // printf("Queue is empty.\n");
        return -111;
    }

    return q -> data[q -> front];
}

int isEmpty(struct Queue *q) {
    if(q -> rear == -1)
    return 1;

    return 0;
}

int isFull(struct Queue *q) {
    if(q -> rear == (MAX - 1)) return 1;

    return 0;
}