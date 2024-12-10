#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int *A;
    int top;
    int tsize;
}Stack;

typedef struct Queue{
    Stack *s1;
    Stack *s2;
}Queue;

Stack* createStack(int tsize){
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->A = (int*)malloc(sizeof(int) * tsize);
    st->tsize = tsize;
    st->top = -1;

    return st;
}

bool isEmptyStack(Stack *st){
    return st->top == -1;
}

bool isFullStack(Stack *st){
    return st->top >= st->tsize-1;
}

void push(Stack *st, int data){
    if(isFullStack(st)){
        printf("Stack overflow !!\n");
        return;
    }
    st->A[++st->top] = data;
}

int pop(Stack *st){
    if(isEmptyStack(st)){
        printf("Stack underflow !!\n");
        return -1;
    }   
    return st->A[st->top--];
}

int peek(Stack *st){
    if(isEmptyStack(st)){
        printf("Nothing to peek, stack underflow !!\n");
        return -1;
    }
    return st->A[st->top];
}

Queue* createQueue(int tsize){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->s1 = createStack(tsize);
    q->s2 = createStack(tsize);

    return q;
}

void enqueue(Queue *q, int data){
    //always push into stack 1
    push(q->s1, data);
    printf("Enqueued %d\n", data);
}

int dequeue(Queue *q){
    //if both stacks are empty, the queue is empty
    if(isEmptyStack(q->s1) && isEmptyStack(q->s2)){
        printf("Queue is empty !!\n");
        return -1;
    }

    //if stack 2 is empty, transfer all the elements of stack 1 to stack 2
    if(isEmptyStack(q->s2)){
        while(!isEmptyStack(q->s1)){
            push(q->s2, pop(q->s1));
        }
    }

    //pop the top element from the stack 2
    int dequeued = pop(q->s2);
    printf("Dequeued : %d\n", dequeued);

    return dequeued;
}

bool isEmptyQueue(Queue *q){
    return isEmptyStack(q->s1) && isEmptyStack(q->s2);
}

int front(Queue *q){
    if(isEmptyQueue(q)){
        printf("Queue is empty, nothing at front !!\n");
        return -1;
    }

    if(isEmptyStack(q->s2)){
        while(!isEmptyStack(q->s1)){
            push(q->s2, pop(q->s1));
        }
    }

    return peek(q->s2);
}

int main() {
    Queue* q = createQueue(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Front element : %d\n", front(q));

    dequeue(q);
    dequeue(q);

    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    dequeue(q);

    printf("Front element : %d\n", front(q));

    dequeue(q);
    dequeue(q);
    dequeue(q);
    
    return 0;
}