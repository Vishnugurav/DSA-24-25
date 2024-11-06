#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "header.h"

void init(List *l){
    l -> front = NULL;
    l -> rear = NULL;
}

void append(List *l, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    if(l->front == NULL){
        l -> front = newnode;
        l -> rear = newnode;
    }
    else{
        newnode -> prev = l -> rear;
        l -> rear -> next = newnode;
        l -> rear = newnode;
    }
    return ;
}

void insertAtBeg(List *l, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> prev = NULL;
    if (l -> front == 0){
        l->front = newnode;
        l->rear = newnode;
    }else{
        newnode -> next = l -> front;
        l -> front -> prev = newnode;
        l -> front = newnode;
    }

    return ;
}

void display(List l){

    if (l.front == NULL) return;
    for (Node * p = l.front; p != NULL; p = p->next){
        printf("%d <-> ", p->data);
    }

    printf("\b\b\b\b     \n");

    return;
}

void insertAtEnd(List *l, int data){

    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> prev = NULL;
    newnode -> next = NULL;


    if(l->front == NULL){
        l -> front = newnode;
        l -> rear = newnode;
    }
    else{
        newnode -> prev = l -> rear;
        l-> rear -> next = newnode;
        l -> rear = newnode;
    }
    return ;
}

int length(List l){
    if(l.front == 0) return -1 ;

    l.rear = l.front;

    int count = 0;
    while(l.rear != 0){
        count++;
        l.rear = l.rear -> next ;
    }
    
    return count;
}

void insertAtposition(List *l, int position, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data ;
    newnode -> prev = NULL;
    newnode -> next = NULL;

    if(position < 0 && position > length(*l) ) return ;
   
    if (position == 0){
        if(l->front==0){
            l -> front = newnode;
            l -> rear = newnode;
        }else{
            newnode->next = l->front;
            l->front = newnode;
            return ;
        }
    } 
        
    Node *temp  = l->front;
    for(int i = 0; i < position-1; i++){
        temp= temp->next;
    }
    newnode -> prev = temp;
    newnode -> next = temp -> next;
    temp->next->prev = newnode;
    temp -> next = newnode;
    

    return ;

}

int removefromBeginning(List *l){
if (!l->front) return INT_MIN;
    Node *p = l->front;

    l->front = l->front->next;
    if (!l->front){
        l->rear = NULL;
        return INT_MIN;
    } 
    l->front->prev = NULL;

    int data = p->data;

    free(p);

    return data;
}

int removefromEnd(List *l){
    if(l->rear == 0) return INT_MIN ;
    Node *temp = l->rear;

    l->rear = l->rear->prev ;

    if(l->rear==NULL){
        l->front = NULL;
        return INT_MIN;
    }
    
    l->rear->next = NULL;

    int data = temp -> data ;
    free(temp);

    return data; 
}

int removefromindex(List *l, int index){
    if(index < 0 ) return INT_MIN;
    else if(index == 0){
        return removefromBeginning(l);
    }
    Node *temp = l->front;
    for(int i =0; i < index; i++){
        temp = temp->next;
    }
    
    if (temp->next == NULL){
        return removefromEnd(l);
    }

    temp -> prev -> next = temp -> next;
    if(temp->next)
    temp -> next -> prev = temp -> prev;
    int data = temp -> data;
    free(temp);

    return data;
}


int removeNode(List *l, Node * n){
    if (n == l->front) return removefromBeginning(l);
    else if (n == l->rear) return removefromEnd(l);

    n->prev->next = n->next;
    n->next->prev = n->prev;

    int data = n->data;

    free(n);

    return data;
}

void destroy(List *l){
    if(l->front ==0) 
        return ;
    
    while(l->front != NULL){
        removefromBeginning(l);
    }
    printf("destroyed DLL");
    return ;
}

void initASCII(List *l, char a){
    init(l);

    int p = (int) a;

    while (p)
    {
        insertAtBeg(l, p % 10);
        p /= 10;
    }
    
    return;
}


void reverseList(List *l){
    if (!l->front) return;

    l->rear = l->front;

    while (l->front->next)
    {
        Node *p = l->front->next;
        Node *q = l->front->prev;
        
        l->front->next = q;
        l->front->prev = p;
        l->front = p;
    }
    
    Node *p = l->front->next;
    Node *q = l->front->prev;
    
    l->front->next = q;
    l->front->prev = p;
    
    return;    
}

ispalindrome(List *l){
   
}

