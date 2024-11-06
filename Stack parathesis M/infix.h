#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;

void iniit(Stack *s);
void display(Stack *s);
void push(Stack *s, char x);
char pop(Stack *s);
char peek(Stack *s);