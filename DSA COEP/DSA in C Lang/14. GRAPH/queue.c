#include<stdio.h>
#include<stdlib.h>


typedef struct  queue{
    int *A;
    int front;
    int rear;
    int size;
}queue;

void qinit(queue *q, int size){
    q->A = (int*)malloc(sizeof(int) *size);
    q->size = size;
    q->front =q->rear = -1;
    return ;
}

int isFull(queue *q){
    return q->rear == q->size-1;
}

int isEmpty(queue *q){
    return q->front == -1 || q->front >q->rear;
}

void eneque(queue *q, int data){
    if(isFull(q)) return;

    if(q->front == -1){
        q->front = 0;
    }
    q->A[++q->rear] = data;
    return ;
}

int deque(queue *q){
    if(isEmpty(q)) return -1 ;
    int x = q->A[q->front++];
    if(q->front> q->rear){
        q->front = q->rear = -1;
    }
    return x;
}


