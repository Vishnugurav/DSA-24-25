#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(Array *arr, int size){
	arr->A =(int*)malloc(size * sizeof(int));
	arr->size = size;
	arr->length = 0;

    return;
} 

void append (Array *arr, int element){
    if(arr->length == arr->size) return ;

	arr->A[arr->length++] = element; 
	return ;
}

void insert_at_index(Array *arr, int index, int element){
    if(index<0  && index>arr->size) return ;

    int i ;
    for(i=arr->length; i>index; i--){
        arr->A[i]=arr->A[i-1];
    }
    arr->A[i]=element;
    arr->length++;

}

void remove_at_index(Array *arr, int index){
    if(index<0 && index>arr->size) return ;
        int i;
    for(i=index; i<arr->length-1; i++){
        arr->A[i]=arr->A[i+1];    
    }
    arr->length--;
    return ;
}

void display(Array arr ){
	int length =arr.length;
	printf("Array= [");
	for(int i =0;  i<length; i++){
		printf("%d  ",arr.A[i]);
	}
    printf("\b\b]\n\n");
	return;
}

int Max(Array *arr){
    int max = arr->A[0];
    for(int i = 0; i<=arr->length-1; i++){
        if(arr->A[i] > max){
            max = arr->A[i];
        } 
    }
    return max;
}


int Min(Array *arr){
    int min = arr->A[0];
    for(int i =0; i<arr->size; i++){
        if(arr->A[i] < min){
            min = arr->A[i];
        }
    }
    return min;
}

void reverse(Array *arr){
    int start = 0, end = arr->length-1;

    while(start<end){
        int temp =arr->A[start];
        arr->A[start] = arr->A[end];
        arr->A[end] = temp;
        start++ ;
        end-- ;
    }
    return ;
}

Array merge(Array *arr1, Array *arr2) {
    Array arr3;
    arr3.size = arr1->size + arr2->size;
    arr3.length = 0;
    arr3.A = (int *)malloc(arr3.size * sizeof(int));

    for (int i = 0; i < arr1->length; i++) {
        arr3.A[arr3.length++] = arr1->A[i];
    }
    for (int i = 0; i < arr2->length; i++) {
        arr3.A[arr3.length++] = arr2->A[i];
    }
    
    
return arr3;
}