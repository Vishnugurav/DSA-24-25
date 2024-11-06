#include<stdio.h>
#include<stdlib.h>
#include"logic.c"

int main(){

    list mylinklist;            
    init(&mylinklist);

    append(&mylinklist, 3);
    append(&mylinklist, 4);
    append(&mylinklist, 5);
    append(&mylinklist, 88);

    display(mylinklist);

    insertAtBeginning(&mylinklist , 2);
    display(mylinklist);

    insertAtEnd(&mylinklist, 15);
    display(mylinklist);

    RDisplay(mylinklist);

    printf("Count %d\n",count(mylinklist));

    printf("RSum %d \n",Rsum(mylinklist));
    
    printf("Sum %d \n",sums(mylinklist));

    insertAtPosition(&mylinklist, 7, 4);
    display(mylinklist);

    printf("Maxmium value in linkedlist is %d \n",Max(mylinklist));
  
    printf(" element at this node %d\n\n ", search(mylinklist, 7));

    sortedinsert(&mylinklist, 9);
    sortedinsert(&mylinklist, 28);
    sortedinsert(&mylinklist, 13);
    display(mylinklist);

    insert(&mylinklist, 4, 6);
    display(mylinklist);

    deleteFromFirst(&mylinklist);
    deleteFromFirst(&mylinklist);
    deleteFromFirst(&mylinklist);
    deleteFromFirst(&mylinklist);
    deleteFromFirst(&mylinklist);
    display(mylinklist);

    deletefromPosition(&mylinklist, 5);
    display(mylinklist);

    deletefromPosition(&mylinklist, 9);
    display(mylinklist);

    deletefromPosition(&mylinklist, 2);
    display(mylinklist);

    printf("%d\n", isSorted(mylinklist));

    deletefromEnd(&mylinklist);
    display(mylinklist);

    insert(&mylinklist, 2 , 13);
    insert(&mylinklist, 3 , 6);
    insert(&mylinklist, 2 , 28);
    insert(&mylinklist, 6 , 28);
    display(mylinklist);

    removeDuplicates(&mylinklist);
    display(mylinklist);

    ReversingElements(&mylinklist);
    display(mylinklist);

    reverselink(&mylinklist);
    display(mylinklist);

    destroy(&mylinklist);
    display(mylinklist);

    list linklist1, linklist2;
    list linklist3;

    init(&linklist1);
    init(&linklist2);
    init(&linklist3);
// inserting value in linklist1;
    append(&linklist1, 7);
    append(&linklist1, 11);
    insertAtBeginning(&linklist1, 1);
    insert(&linklist1,2,9);
    insertAtPosition(&linklist1,25,4);
    insertAtEnd(&linklist1,45);
    display(linklist1);
    
// inserting value in linklist2;
    append(&linklist2, 5);
    append(&linklist2, 13);
    insertAtBeginning(&linklist2,3);
    insert(&linklist2,2,8);
    insertAtPosition(&linklist2,22,4);
    insertAtEnd(&linklist2,32);
    display(linklist2);

    concatenating(&linklist1, &linklist2);
    display(linklist1);
    
    sortmerge(&linklist1,&linklist2);
    display(linklist1);

    return 0;
}

