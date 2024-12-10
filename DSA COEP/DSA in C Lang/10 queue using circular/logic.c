#include "header.h"

void init(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enque(queue *q, int element){
    Node *nn =(Node*)malloc(sizeof(Node*));

    if(nn == NULL) return ;

    nn->data = element;
    nn->next = q->front;

    if(q->front == NULL){
        q->front = q->rear = nn;
    }
    
    q->rear->next = nn;
    q->rear = nn;

    return ;
}

int deque(queue *q){
    int x=-1;
    if(q->front == NULL){
        return x;
    }
    if(q->front == q->rear){
        x = q->front->data;
        q->front =q->rear = NULL;
        return x;
    }
    x = q->front->data;
    q->front = q->front->next;
    q->rear->next = q->front;
    return x;
}

int isEmpty(queue q){
    return q.front == NULL;
}

int isFull(){
    Node *nn = (Node*)malloc(sizeof(Node));
    if(nn == NULL) return 1;
    free(nn);
    return 0;
}

void display(queue q){
    if(isEmpty(q)) return ;

    Node *temp = q.front;

    // do{
    //     printf("%d->",q.rear->data);
    //     q.rear = q.rear->next;
    // }while(q.rear!=q.front);

    do{
        printf("%d->",temp->data);
        temp = temp->next;
    }while(temp!=q.front);

    return ;
}
