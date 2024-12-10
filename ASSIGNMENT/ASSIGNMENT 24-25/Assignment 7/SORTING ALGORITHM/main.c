#include<stdio.h>
#include<stdlib.h>
#include "logic.c"


int main(){
    Array arr;
    init(&arr,50);
    int n[10] = {10,8,20,30,40,24,78,3,55,45};
    for(int i = 0;i<10;i++){
        append(&arr, n[i]);
    }
    printf("Element in Array\n");
    display(&arr);

    printf("\nBubble Sort:\n");
    Bubble_Sort(&arr);
    display(&arr);

    printf("\nSelection Sort:\n");
    Selection_Sort(&arr);
    display(&arr);

    printf("\nInsertion_Sort:\n");
    Insertion_Sort(&arr);
    display(&arr);

    printf("\nQuick_Sort:\n");
    quick_sort(&arr, 0, arr.len-1);
    display(&arr);

    printf("\nHeap_Sort:\n");
    heap_sort(&arr);
    display(&arr);
        
    return 0;
}