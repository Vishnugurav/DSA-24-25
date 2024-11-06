#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;

    printf("Reverse array =[");

    for(int i = size-1; i>=0; i--){
        printf("%d ",A[i]);
    }
    printf("\b]");

}