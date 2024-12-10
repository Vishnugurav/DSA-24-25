#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct array{
	int *A;
	int size;
	int length;
}Array;

void init(Array *a, int size);
void append(Array *a, int element);
void insertatpos(Array *a, int index, int element);
void removefrompos(Array *a, int index);
int Max(Array *a);
int Min(Array *a);
void display(Array a);
int isPalindrome(Array *a);
void removeduplicates(Array *a);
void moveNegative(Array *a);
void reverse(Array *a);
int search(Array *a, int element);
Array merge(Array *arr1, Array *arr2);