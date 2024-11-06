#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct stack{
   int *A;
   int size;
   int top;
}stack;

void init(stack *st, int size);
void push(stack *st, int element);
int pop(stack *st);
int peek(stack st, int index);
void display (stack st);
int peekTop(stack st);