#include <stdio.h>
#include<stdlib.h>

struct Queue {
    int data[2];
    struct Queue *next;
};

struct Queue *allocateNode(int x, int dist) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode -> data[0] = x;
    newNode -> data[1] = dist;
    newNode -> next = NULL;

    return newNode;
}

struct Queue *enqueue(struct Queue *front, int x, int dist) {
    struct Queue *newNode = allocateNode(x,dist);

    if(front == NULL) return newNode;

    struct Queue* temp = front;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }

    temp -> next = newNode;
    return front;
}

void dequeue(struct Queue *front) {
    if(front == NULL) return;

    // printf("Dequed element: %d",front -> data);
    front = front -> next;
}

int *peek(struct Queue *front) {
    return &(front -> data[0]);
}

int isEmpty(struct Queue *front) {
    if(front == NULL) return 1;

    return 0;
}