#include<stdio.h>
#include<stdlib.h>

typedef struct term{
    int coeff;
    int expo;
}term;

typedef struct poly{
    int n;
    term *t;
}poly;

void init(poly *p, int capacity);
void create(poly *p);
poly sum(poly p1, poly p2);
poly difference(poly p1, poly p2);
void display(poly p);
   