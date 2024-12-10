#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;


void init(Stack *s);
void display(Stack *s);
void push(Stack *s, int element);
int pop(Stack *s);
int isEmpty(Stack s);
int peek(Stack s);