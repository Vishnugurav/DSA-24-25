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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Bubble_Sort(Array * arr){
    for(int i  = 0;i<arr->len-1;i++){
        int flag = 0;
        for(int j = 0;j<arr->len-i-1;j++){
            if(arr->A[j]>arr->A[j+1]){
                swap(&arr->A[j], &arr->A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) return ;
    }
    return;
}
    
void Selection_Sort(Array * arr) {
    for (int i = 0; i < arr->len - 1; i++) {
        int key = i;
        for (int j = i + 1; j < arr->len; j++) {
            if (arr->A[j] < arr->A[key]) {
                key = j;
            }
        }
        int temp = arr->A[i];
        arr->A[i] = arr->A[key];
        arr->A[key] = temp;
    }
}



void Insertion_Sort(Array * arr){
    for(int i = 1;i<arr->len;i++){
        int element = arr->A[i];
        int j = i-1;

        while(j>=0 && arr->A[j] > element){
            arr->A[j+1] = arr->A[j];
            j = j-1;
        }
        arr->A[j+1] = element;
    }
}


int partition(Array * arr, int low, int high) {
    int pivot  = arr->A[high];
    int i = low-1;

    for(int j = low;j<high;j++){
        if(arr->A[j]< pivot){
            i++;
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
            i++;
            int temp = arr->A[i];
            arr->A[i] =  pivot;
            arr->A[high] = temp;
            return i;
}


void quick_sort(Array * a, int low, int high){
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}


void heapify(Array *arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr->A[left] > arr->A[largest]) {
        largest = left;
    }

    if (right < n && arr->A[right] > arr->A[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr->A[i];
        arr->A[i] = arr->A[largest];
        arr->A[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort(Array *arr){
    int n = arr->len;

    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--){
        int temp = arr->A[0];
        arr->A[0] = arr->A[i];
        arr->A[i] = temp;

        heapify(arr, i, 0);
    }
}

void display(Array *arr){
    for(int i = 0;i<arr->len;i++){
        printf("%d ",arr->A[i]);
    }
    printf("\n");
}