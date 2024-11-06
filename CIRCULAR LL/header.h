#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef Node *List;

void init(List *l);
void display(List l);

void append(List *l, int data);
void insertAtBeg(List *l, int data);
void insertAtEnd(List *l, int data);
void insertAtpos(List *l,int index, int data);

int removefromFirst(List *l);
int removefromEnd(List *l);
int removefromposition(List *l,int index);

int length(List l);
void destroy(List *l);

void fill (List *l, int num);

void reverse(List *l);