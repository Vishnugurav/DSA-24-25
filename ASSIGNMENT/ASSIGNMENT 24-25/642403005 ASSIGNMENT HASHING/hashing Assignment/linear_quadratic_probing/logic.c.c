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

void insertUsingLinear(hashTable *ht, int val)
{
    int initialIndex = hashFunction(val, ht->size);
    int currentIndex = initialIndex;
    for (int i = 1; i < ht->size; i++)
    {
        if (ht->data[currentIndex] == INITIAL_VAL)
        {
            ht->data[currentIndex] = val;
            printf("Element inserted successfully\n");
            return;
        }
        else
        {
            currentIndex = (initialIndex + i) % ht->size;
        }
    }
    printf("No slot Empty to insert\n");
    return;
}

void deleteUsingLinear(hashTable *ht, int val)
{
    int initialIndex = hashFunction(val, ht->size);
    int currentIndex = initialIndex;
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->data[currentIndex] == val)
        {
            ht->data[currentIndex] = INITIAL_VAL;
            printf("Element deleted successfully\n");
            break;
        }
        else
        {
            currentIndex = (initialIndex + i) % ht->size;
        }
    }
    printf("Element not found");
    return;
}


void insertUsingQuadratic(hashTable *ht, int val)
{
    int initialIndex = hashFunction(val, ht->size);
    int currentIndex = initialIndex;
    for (int i = 1; i < ht->size; i++)
    {
        if (ht->data[currentIndex] == INITIAL_VAL)
        {
            ht->data[currentIndex] = val;
            printf("Element inserted successfully\n");
            return;
        }
        else
        {
            currentIndex = (initialIndex + (i*i)) % ht->size;
        }
    }
    printf("No slot Empty to insert\n");
    return;
}

void deleteUsingQuadratic(hashTable *ht, int val)
{
    int initialIndex = hashFunction(val, ht->size);
    int currentIndex = initialIndex;
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->data[currentIndex] == val)
        {
            ht->data[currentIndex] = INITIAL_VAL;
            printf("Element deleted successfully\n");
            break;
        }
        else
        {
            currentIndex = (initialIndex + (i*i)) % ht->size;
        }
    }
    printf("Element not found");
    return;
}

void display(hashTable *ht)
{
    printf("Index\tData\n");
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->data[i] == INITIAL_VAL)
        {
            printf("%d\t--\n", i);
        }
        else
        {
            printf("%d\t%d\n", i, ht->data[i]);
        }
    }
    return;
}