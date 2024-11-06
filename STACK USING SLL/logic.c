#include "header.h"

void init(Stack *s){
    s->top = NULL;
    return ;
}

void push(Stack *s, int element){
    Node *newnode = (Node*)malloc(sizeof(Node));

    if(newnode==NULL)
    return;

    newnode->data = element;
    newnode->next = s->top;
    s->top = newnode;
    
    return ;
}

int pop(Stack *s){
    int x =-1;
    if(s->top==NULL){
        return INT_MIN ;
    }
    Node *temp = s->top;
    s->top = temp->next;
    x = temp->data;
    free(temp);

    return x;
}

int peek(Stack s){
    if(s.top == NULL)
    return INT_MIN;
    return s.top->data;
  
}

void display(Stack *s){

    if(s->top == NULL) return ;
    printf("displaying element in stacks\n");

    Node *temp = s->top;
    
    while(temp != NULL){  
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return ;
}

int isEmpty(Stack s){
    if(s.top == NULL)
        return -1;
    return 0;
}

int isFull(){

    Node *nn= (Node*)malloc(sizeof(Node));
    if(nn == NULL)
    return -1;
    free(nn);
    return 0;
}