#include "header.h"

void init(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enque(queue *q, int element){
    Node *nn = (Node*)malloc(sizeof(Node));

    if(nn == NULL) return ;
    nn->data = element;
    nn->next = NULL;

    if(q->front == NULL){
        q->front = q->rear = nn;
    }else{
        q->rear->next = nn;
        q->rear = nn;
    }
    return ;
}

int isEmpty(queue q){
    return q.front == NULL;
}

// int isFull(queue q){
//     return newnode == NULL;
// }

int deque(queue *q){
    if(isEmpty(*q)) return -1;

    Node *temp =q->front;
    int data = temp->data;

    if(q->front == q->rear){
        q->front = q->rear = NULL;
    }else{
        q->front = q->front->next;
    }
    free(temp);
    return data ;
}

void display(queue q){
    if(isEmpty(q)) return ;

    printf("Displaying the Queue SLL: \n");
    Node *temp = q.front;

    while(temp != NULL){
        printf("%d-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return ;
}