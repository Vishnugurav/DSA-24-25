#include "header.h"

void init(Array *a, int size){
	a->A = (int*)malloc(size * sizeof(int));
	a->size = size;
	a->length = 0;
	return ;
}

void append(Array *a, int element){
	if(a->length == a->size) return ;
	
	a->A[a->length++] = element;
	return ;
}

void insertatpos(Array *a, int index, int element){
	if(index<0 || index>a->size) return ;
	int i;
	for(i = a->length; i>index; i--){
		a->A[i] = a->A[i-1];
	}
	
	a->A[i] = element;
	a->length++;

	return ;
}

void removefrompos(Array *a, int index){
	if(index<0 || index>a->size) return ;

	int i;

	for(i= index; i<a->length; i++){
		a->A[i] = a->A[i+1];
	}
	a->length--;
	return ;

}

int Max(Array *a){
	int max = a->A[0];
	 
	for(int i = 0; i<a->length; i++){
		if(a->A[i] > max){
			max = a->A[i];
		}
		
	}
	return max ;
}

int Min(Array *a){
	int min = a->A[0];
	for(int i = 0 ; i< a->length; i++){
		if(a->A[i]<min){
			min = a->A[i];
		}
	}
	return min ;

}


void display(Array a){
	
	printf("Array : [");

	for(int i = 0; i<a.length; i++){
		printf("%d  ",a.A[i]);
	}
	printf("\b\b]\n");
	return ;
		
}

int isPalindrome(Array *a){
	
	int start = a->A[0];
	int end = a->length-1;

	while(start<end){
		
		if(a->A[start] != a->A[end]) 
			return 0;
		start++;
		end--;				
	}
	return 1;
}

void removeduplicates(Array *a){
    int i, j, k;

    // Loop through each element of the array
    for (i = 0; i < a->length; i++) {
        // Inner loop to check for duplicates
        for (j = i + 1; j < a->length; j++) {
            if (a->A[i] == a->A[j]) {
                // If a duplicate is found, shift the elements to the left
                for (k = j; k < a->length- 1; k++) {
                    a->A[k] = a->A[k + 1];
                }
                // Decrease the size of the array after removing the duplicate
                a->length--;
                j--;	  // Adjust index to check for more duplicates at the same position
            }
        }
    }
	return ;
}

void moveNegative(Array *a){
    int j = 0;  // Index to track the position to place the next negative element
    int temp;

    // Traverse the array and place negative elements at the beginning
    for (int i = 0; i < a->length; i++) {
        if ( a->A[i] < 0) {
            // Swap the current negative element with the element at index j
            if (i != j) {
                temp = a->A[i];
                a->A[i] =  a->A[j];
                a->A[j] = temp;
            }
            j++;  // Increment j to place the next negative element in the next position
        }
    }
	return ;
}	

void reverse(Array *a){
	int start = 0;
	int end =a->length;

	while(start<end){
		int temp = a->A[start];
		a->A[start] =a->A[end];
		a->A[end] = temp;
		start++;
		end--;
	}
	return ;
}

int search(Array *a, int element){
	
	for(int i = 0; i<a->length; i++){
		if(a->A[i] == element){
			return i;
		}
	}
	return INT_MIN;
}