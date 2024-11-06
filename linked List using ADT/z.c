#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

typedef struct list{
    int *front;
    int *rear;
}list;

void init(list *l){
    l->front = NULL;
    l->rear = NULL;
}

void append(list *l, int data){
    Node *nn;
    nn = (Node*)malloc(sizeof(Node));

    if(nn = NULL) return;
    nn->data = data;
    nn->next = NULL;
    nn->prev = NULL;

    if(l->front == NULL){
        
    }
}




int main(){
    list mylink;

}