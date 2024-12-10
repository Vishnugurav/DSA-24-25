#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_ASCII(ASCII *list) {
    list->head = NULL;
    list->tail = NULL;
}

Node *createnode(int data) {
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = data;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}

void ASCII_of(ASCII *list, char c) {
    int a = (int)c;
    Node *nn = createnode(a);

      if (list->head == NULL) {
        list->head = nn;
        list->tail = nn;
    } else {
        nn->next = list->head;
        list->head->prev = nn;
        list->head = nn;
    }
}

void traverse(ASCII *list) {
    Node *p = list->head;
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("ASCII List: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Destroy(ASCII *list) {
    Node *p = list->head;
    while (p != NULL) {
        Node *next = p->next;
        free(p);
        p = next;
    }
    list->head = NULL;
    list->tail = NULL;
}