#include<stdio.h>
#include<stdlib.h>

int main(){
    //int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int A[10];
    int sum = 0;


    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &A[i]);
    }

    for(int i =0; i<10; i++){
        sum = sum + A[i]*A[i];
    }
    printf("sum of the squares of element is %d",sum);

    return 0;
}