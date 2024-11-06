#include "logic.c"

int main(){

    Array a;
	init(&a, 15);
	
	// for(int i = 1; i< 7; i++){
	// 	append(&a, i);
	// }

	display(a);
	
	insertatpos(&a, 3 ,45);
	display(a);


	removefrompos(&a, 2 );
	display(a);

	printf("Maximum value : %d\n",Max(&a));
	
	printf("Minimum value : %d\n",Min(&a));

	int palin = isPalindrome(&a);
	if(palin ==0){
		printf("Is not Palindrome : %d\n",isPalindrome(&a));
	}else{
		printf("Is Palindrome : %d\n",isPalindrome(&a));
	}

	append(&a,-5);
	append(&a,-4);
	append(&a,-4);
	append(&a,-2);
	append(&a,-3);
	
	display(a);
	
	
	removeduplicates(&a);
	display(a);

	moveNegative(&a);
	display(a); 

    reverse(&a);
    display(a);

	int index = search(&a, 3);
    if (index!= INT_MIN) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found.\n");
    }
	display(a);

	return 0;
}