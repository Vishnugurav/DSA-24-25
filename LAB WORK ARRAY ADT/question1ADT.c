#include<stdio.h>
#include<stdlib.h>

typedef struct Array{
    int *A;
    int size;
    int length;
}Array;

void init(Array *arr, int size){
    arr -> A = (int*)malloc(size * sizeof(int));
    arr -> size = size;
    arr -> length = 0;
    return ;
}

void fill(Array *arr){
	//int length = arr->length;
	for (int i =arr->length; i< arr->size; i++){
		arr->A[i]= i+1;
	}
    arr->length = arr->size;
	
	return ;
}


void display(Array arr ){
	int length =arr.length;
	printf("Array= [");
	for(int i =0;  i<length; i++){
		printf("%d, ",arr.A[i]);
	}
        printf("\b\b]\n\n");
	return;
}

int sumofsquares(Array arr){

    int sum = 0;
   
    for(int i = 0; i<arr.length; i++){
        sum = sum+ arr.A[i] * arr.A[i];
    }
    printf("sum of squares = %d\n",sum);
    return sum ;
}


int main(){
    struct Array arr;

    init(&arr, 10);
    fill(&arr);
    display(arr);
    sumofsquares(arr);

    return 0;
}