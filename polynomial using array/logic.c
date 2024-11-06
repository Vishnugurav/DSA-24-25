#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void init(poly *p, int capacity){
    p->n =0;
    p->t = (term*)malloc(sizeof(term) * capacity);
    return;
}

void create(poly *p){
    
}