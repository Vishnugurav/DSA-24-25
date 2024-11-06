#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

typedef struct list{
    Node *front;
    Node *rear;
}List;

void init(List *l);
void append(List *l, int data);

void insertAtBeg(List *l, int data);
void insertAtposition(List *l, int position, int data);
void insertAtEnd(List *l, int data);

int length(List l);

int removefromBeginning(List *l);
int removefromEnd(List *l);
int removefromindex(List *l, int index);
int removeNode(List *l, Node *n);
void destroy(List *l);
void initASCII(List *l, char a);
void swapnodes(List *l);
void reverseList(List *l);