#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_VAL -1

void init(hashTable *ht, int size)
{
    ht->size = size;
    ht->data = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        ht->data[i] = INITIAL_VAL;
    }
    return;
}

int hashFunction(int val, int size)
{
    return val % size;
}

void insertVal(hashTable *ht, int val){
    int index = hashFunction(val, ht->size);
    if (ht->data[index] != INITIAL_VAL)
    {
        printf("Collision Occured\nElement already present at the index\n");
        return;
    }else{
        ht->data[index] = val;
    }
    return;
}

void deleteVal(hashTable *ht, int val){
    int index = hashFunction(val, ht->size);
    if (ht->data[index] == INITIAL_VAL)
    {
        printf("Element is not present\n");
        return;
    }else{
        ht->data[index] = INITIAL_VAL;
    }
    return;
}

void display(hashTable * ht){
    printf("Index\tData\n");
    for(int i = 0; i < ht->size; i++){
        if (ht->data[i] == INITIAL_VAL)
        {
            printf("%d\t--\n", i);
        }else{
            printf("%d\t%d\n", i, ht->data[i]);
        }
    }
    return;
}