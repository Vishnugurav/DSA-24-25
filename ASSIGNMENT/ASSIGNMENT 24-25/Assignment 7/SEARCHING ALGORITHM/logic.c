#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(Array * arr, int size){
    arr->A = (int *)malloc(sizeof(int) * size);
    arr->size = size;
    arr->len = 0;
}
void append(Array * arr, int data){
    if(arr->len > arr->size)
    return;

    arr->A[arr->len++] = data;
}

void Linear_Search(Array * arr, int element){
    
    for(int i = 0;i<arr->len;i++){
        if(arr->A[i] == element){
            printf("Element Found at %d place\n", i);
        }
    }
}

void Binary_Search(Array *arr, int element) {
    int low = 0;
    int high = arr->len - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr->A[mid] == element) {
            printf("Element Found at %d place", mid);
            return;   
        }
        if (arr->A[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element not Found\n"); 
}

void sort(Array * arr){
    for(int i  = 0;i<arr->len-1;i++){
        for(int j = 0;j<arr->len-i-1;j++){
            if(arr->A[j]>arr->A[j+1]){
                int temp = arr->A[j+1];
                arr->A[j+1] =arr->A[j];
                arr->A[j] = temp;
            }
        }
    }
    return;
}


void display(Array *arr){
    for(int i = 0;i<arr->len;i++){
        printf("%d ",arr->A[i]);
    }
    printf("\n"); 
}