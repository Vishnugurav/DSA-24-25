#include<stdio.h>
#include<stdlib.h>

void init(Array *arr ){
    arr->A = (int*)malloc(sizeof(int) * size);
    arr->size= 20;
    arr-> length = 0;
}
