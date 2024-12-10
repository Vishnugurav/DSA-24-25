#include <stdbool.h>

typedef struct{
    char name[50];
    unsigned int age;
}data;

typedef struct Node{
    data d;
    struct Node *next;
}Node;

typedef struct{
    Node *head; 
    Node *tail; 
}queue;


void qinit(queue *q);
int qfull();
int qempty(queue *q);
void enq(queue *q, data d);
data deq(queue *q);