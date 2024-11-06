#include<stdio.h>
#include<stdlib.h>

typedef struct CircularQueue{
    int size;
    int front, rear;
    int *A;
}CQueue;

void init(CQueue *q, int size);
int isEmpty(CQueue q);
int isFull(CQueue q);
void enque(CQueue *q, int element);
int deque(CQueue *q);
void display(CQueue q);