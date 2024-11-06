#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Queue{
    int size;
    int *A;
    int front, rear;
}queue;

void init(queue *q, int size);
void display(queue q);
void enque(queue *q, int element);
int deque(queue *q);
int isEmpty(queue q);
int isFull(queue q);