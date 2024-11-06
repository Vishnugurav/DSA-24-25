#include<stdio.h>
#include<stdlib.h>

typedef struct Array{
    int *A;
    int size;
    int length;
}Array;

void init(Array *arr, int size){
    arr -> A = (int*)malloc(sizeof(int));
    arr -> size = size;
    arr->length = 0;
    return ;
}

void append(Array *arr, int data){
	if(arr->length == arr->size) return ;
	
	arr->A[arr->length++] = element;
	return ;
}

void fill (Array *arr){
	int length = arr->length;
    for(int i =length; length < arr->size; i++){
        arr->A[i] = i+1;
    }
    return ;
}


void display(Array arr){

    printf("Original Array = [ ");
    for(int i =0; i<arr.size; i++){
        printf("%d ",arr.A[i]);
    }
    printf("]\n");
    return ;
}

void reverse(Array arr){

    printf("Reverse Array = [ ");
    for(int i = arr.size-1; i>=0; i--){
        printf("%d ",arr.A[i]);
    }
    printf("]\n");
    return ;
}

int main(){

    struct Array arr;
    init(&arr,10);
    fill(&arr);
    display(arr);
    reverse(arr);
    
}
