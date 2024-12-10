#include<stdio.h>
#include<stdlib.h>
#include "logic.c"


int main(){
    Array arr;
    init(&arr,45);
    int n[10] = {10,8,20,30,40,24,78,30,55,45};
    for(int i = 0;i<10;i++){
        append(&arr, n[i]);
    }
    printf("Element in Array\n");
    display(&arr);
    printf("\nLinear Search\n");
    Linear_Search(&arr, 40);
    printf("\nBinary Search\n");
    printf("sort the Element in Array for Binary Search\n");
    
    sort(&arr);
    display(&arr);

    Binary_Search(&arr,20);

    return 0;
}