#include<stdio.h>
#include<stdlib.h>
#include "logic.c"

int main(){
    List l;
    init(&l);

    append(&l, 13);
    append(&l, 73);

    append(&l, 14);
    append(&l, 7);
    display(l);

    
    insertAtBeg(&l, 3);
    insertAtBeg(&l, 4);
    display(l);

    insertAtEnd(&l, 45);
    insertAtEnd(&l, 55);
    display(l);

    printf("length is %d\n", length(l));

    insertAtposition(&l,4, 8);
    insertAtposition(&l,1, 5);
    display(l);

    printf("Removed element: %d\n",removefromBeginning(&l));
    display(l);

    printf("Removed element: %d\n",removefromEnd(&l));
    display(l);
  
    printf("Removed element: %d\n",removefromindex(&l, 4));
    display(l);
   
    printf("Removed node: %d\n",removeNode(&l, l.rear->prev->prev->prev));
    display(l);

    List A;
    init(&A);
   

    append(&A, 13);
    append(&A, 73);

    append(&A, 14);
    append(&A, 7);
    display(A);

    printf("Display Reverse:\n");
    reverseList(&A);
    display(A);
    
    
    if (isPalindrome(&A)) {
        printf("The doubly linked list is a palindrome.\n");
    } else {
        printf("The doubly linked list is NOT a palindrome.\n");
    }
    destroy(&A);

    return 0;

}