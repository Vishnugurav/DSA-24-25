#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *rear;
}queue;

void init(queue *q);
void enque(queue *q, int element);
