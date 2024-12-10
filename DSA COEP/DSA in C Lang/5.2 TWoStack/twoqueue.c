#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//QueueNode
typedef struct QueueNode{
    int *A;
    int front;
    int rear;
    int tsize;
    int usize;
}Queue;

typedef struct Stack{
    Queue* q1; //primary queue
    Queue* q2; //secondary queue
}Stack;

Queue* createQueue(int tsize){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->A = (int*)malloc(sizeof(int) * tsize);
    q->front = 0;
    q->rear = -1;
    q->tsize = tsize;
    q->usize = 0;

    return q;
}

bool isEmptyQueue(Queue *q){
    return q->usize == 0;
}

bool isFullQueue(Queue *q){
    return q->usize >= q->tsize;
}

void enqueue(Queue* q, int data){
    if(isFullQueue(q)){
        printf("Queue is full, cannot enqueue !!\n");
        return;
    }
    q->rear = (q->rear+1) % q->tsize;
    q->A[q->rear] = data;
    q->usize++;
}

int dequeue(Queue *q){
    if(isEmptyQueue(q)){
        printf("Queue is empty, cannot dequeue !!\n");
        return -1;
    }
    int data = q->A[q->front];
    q->front = (q->front+1) % q->tsize;
    q->usize--;

    return data;
}

int front(Queue *q){
    if(isEmptyQueue(q)){
        printf("Queue is empty !!\n");
        return -1;
    }
    return q->A[q->front];
}

//create a stack using two queues:

Stack* createStack(int tsize){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    st->q1 = createQueue(tsize);
    st->q2 = createQueue(tsize);

    return st;
}

//push element to stack of q1
void push(Stack *st, int data){
    enqueue(st->q1, data);
}

//pop element from the stack
int pop(Stack *st){
    if(isEmptyQueue(st->q1)){
        printf("Stack is empty, cannot pop !!\n");
        return -1;
    }
    
    while(st->q1->usize > 1){
        enqueue(st->q2, dequeue(st->q1));
    }
    //The last element in the queue1 is the top of the stack
    int poppedValue = dequeue(st->q1);

    //swap the queue1 and queue2
    Queue* temp = st->q1;
    st->q1 = st->q2;
    st->q2 = temp;

    return poppedValue;
}

int top(Stack *st){
    if(isEmptyQueue(st->q1)){
        printf("Stack is empty !!\n");
        return -1;
    }
    
    while(st->q1->usize > 1){
        enqueue(st->q2, dequeue(st->q1));
    }

    //The last element in queue1 is the top of the stack
    int topValue = dequeue(st->q1);

    //putting the top element back in the queue2
    enqueue(st->q2, topValue);

    Queue* temp = st->q1;
    st->q1 = st->q2;
    st->q2 = temp;

    return topValue;
}

bool isEmptyStack(Stack *st){
    return isEmptyQueue(st->q1);
}

int main(){
    Stack *st = createStack(10);

    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 40);

    printf("Top element : %d\n", top(st));

    printf("Popped element : %d\n", pop(st));
    printf("Popped element : %d\n", pop(st));

    printf("Top element : %d\n", top(st));

    push(st, 50);
    printf("Top element : %d\n", top(st));

    while(!isEmptyStack(st)){
        printf("Popped Element : %d\n", pop(st));
    }
    return 0;
}