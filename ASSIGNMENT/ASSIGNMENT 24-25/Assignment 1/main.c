#include<stdio.h>
#include "header.h"

int main(){
	Array arr1;
	int size1, choice, v;

	printf("Enter the size of the array: ");
    scanf("%d", &size1);
    init(&arr1, size1);

	do{
		printf("MENU\n");
		printf("1. Append Element\n");
		printf("2. Insert Element At Index\n");
		printf("3. Remove Element From Index\n");
		printf("4. Display Element\n");
		printf("5. Maximum Element\n");
		printf("6. Minimum Element\n");
		printf("7. Reverse Element\n");
		printf("8. Merge\n");
		printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

		switch (choice) {
            case 1:
                printf("\nEnter the value to append:\t");
				int element;
                scanf("%d", &element);
                append(&arr1, element);
                break;
            case 2:
                printf("\nEnter the index and value to insert: ");
				int index;
                scanf("%d %d", &index, &element);
                insert_at_index(&arr1, index, element);
                break;
            case 3:
                printf("\nEnter the index to remove:\t");
                scanf("%d", &index);
                remove_at_index(&arr1, index);
                break;
            case 4:
                display(arr1);
                break;
            case 5:
                printf("\nMaximum: %d\n", Max(&arr1));
                break;
            case 6:
                printf("\nMinimum: %d\n", Min(&arr1));
                break;
            case 7:
				printf("Original Array:\n");
				display(arr1);
                reverse(&arr1);
                printf("Array reversed.\n");
				display(arr1);
                break;
            case 8:
                printf("Array Merged\n");
				Array temp=merge(&arr1, &arr1);
                display(temp);
                break;
			
            default:
                printf("Invalid choice.\n");
        }
		printf("Enter 0  to exit !!\t");
        scanf("%d",&v);
		
		
		
	}while(v != 0);



    return 0;

}