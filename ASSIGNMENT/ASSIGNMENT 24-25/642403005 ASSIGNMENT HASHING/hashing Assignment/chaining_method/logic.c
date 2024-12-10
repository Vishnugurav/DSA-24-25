#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define INIT_Val -1

void init(hashTable *ht, int size)
{
    ht->size = size;
    ht->elements = (node *)malloc(size * sizeof(node));
    for (int i = 0; i < size; i++)
    {
        ht->elements[i].d = INIT_Val;
        ht->elements[i].next = NULL;
    }
    return;
}

int hashFunction(int val, int size)
{
    return val % size;
}

void insertVal(hashTable *ht, int val)
{
    int i = hashFunction(val, ht->size);
    if (ht->elements[i].d == INIT_Val)
    {
        ht->elements[i].d = val;
    }
    else
    {
        node *nn = (node *)malloc(sizeof(node));
        nn->d = val;
        nn->next = ht->elements[i].next;
        ht->elements[i].next = nn;
    }
    return;
}

void deleteVal(hashTable *ht, int val)
{
    int i = hashFunction(val, ht->size);
    if (ht->elements[i].d == INIT_Val)
    {
        printf("Element not present in Hash Table");
    }
    else
    {
        node *current = &ht->elements[i];
        node *prev = NULL;
        while (current != NULL)
        {
            if (current->d == val)
            {
                if (prev == NULL)
                {
                    if(current->next == NULL){
                        ht->elements[i].d = INIT_Val;
                        break;
                    }
                    node *del = current->next;
                    current->d = current->next->d;
                    current->next = current->next->next;
                    free(del);
                    break;
                }
                else
                {
                    prev->next = current->next;
                    free(current);
                    break;
                }
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    return;
}

void display(hashTable *ht)
{
    printf("Index\tData\n");
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->elements[i].d == INIT_Val)
        {
            printf("%d\t--\n", i);
        }
        else
        {
            node *temp = &ht->elements[i];
            printf("%d\t", i);
            while (temp != NULL)
            {
                printf("%d -> ", temp->d);
                temp = temp->next;
            }
             printf("\n");
        }
    }
    return;
}