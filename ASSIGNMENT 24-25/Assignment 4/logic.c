#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void qinit(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

int qempty(queue *q){
    return (q->head == NULL);
}

int qfull(){

    Node *temp = malloc(sizeof(Node));
    if (temp == NULL){
        return 1; 
    }
    free(temp); 
    return 0; 
}


void enq(queue *q, data d){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed. \n");
        return;
    }

    newNode->d = d;

    if(q->head == NULL){
        newNode->next = newNode; 
        q->head = newNode;
        q->tail = newNode;
    }else{
        newNode->next = q->head;
        q->tail->next = newNode;
        q->tail = newNode;
    }
}


data deq(queue *q){
    if (qempty(q)){
        printf("Queue is empty.\n");
        data emptyData = {"", 0}; 
        return emptyData;
    }

    Node *temp = q->head;
    data d = temp->d;

    if(q->head == q->tail){
        q->head = NULL;
        q->tail = NULL;
    }else{
        q->head = q->head->next;
        q->tail->next = q->head;
    }

    free(temp);
    return d;
}


