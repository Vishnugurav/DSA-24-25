#include "header.h"

void init(CQueue *q, int size){
    q->size = size;
    q->front = -1;
    q->rear = -1;

    q->A = (int*)malloc(q->size * sizeof(int));

    return ;
}

int isEmpty(CQueue q){
    return q.front == -1;
}

int isFull(CQueue q){
    return (q.rear+1)%q.size == q.front;
}

void enque(CQueue *q, int element){
    if(isFull(*q)){
        return ;
    }
    else if(isEmpty(*q)){
        q->front = 0;
        q->rear = 0;
    }else{
        q->rear = (q->rear+1) % q->size;
    }
    q->A[q->rear] = element;
    return ;
}

int deque(CQueue *q){
    if(isEmpty(*q)){
        return -1;
    }
    
    int data = q->A[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->front = (q->front+1)%q->size;   
    }
     
    return data;
  
}

void display(CQueue q){
    if(isEmpty(q)) return ;
    int i = q.front;

    printf("Displaying the queue :\n");
    do{
        printf("%d ",q.A[i]);
        i = (i+1)%q.size;
    }while(i != (q.rear+1)%q.size);

    printf("\n");
    
    return ;
}

