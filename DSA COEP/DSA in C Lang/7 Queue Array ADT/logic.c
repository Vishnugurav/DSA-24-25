#include "header.h"

void init(queue *q, int size){
    q->size = size;
    q->front =q->rear = -1;
    q->A = (int*)malloc(q->size * sizeof(int));
    return ;
}

void enque(queue *q, int element){
    if(isFull(*q)) return ;
   
    q->rear++;
    q->A[q->rear] = element;
    return ;
}

int deque(queue *q){
    if(isEmpty(*q)) return -1;    

    q->front++;
    int x = q->A[q->front];
    
    return x;  
}

void display(queue q){
    if(q.front == q.rear) return;

    for(int i = q.front+1; i<=q.rear; i++){
        printf("%d ",q.A[i]);
    }
    printf("\n");
    return ;
}

int isEmpty(queue q){
    if(q.front == q.rear) return 1;
    return 0;
}

int isFull(queue q){
    if(q.rear == q.size-1) return 1;
    return 0;
}