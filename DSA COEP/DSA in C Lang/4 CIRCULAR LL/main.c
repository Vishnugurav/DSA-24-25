#include<stdio.h>
#include<stdlib.h>
#include "logic.c"

int main (){
    List l;
    init(&l);
    append(&l, 5);
    append(&l, 7);
    append(&l, 13);
    append(&l, 17);
    append(&l, 25);
    display(l);

    insertAtBeg(&l, 3);
    display(l);

    insertAtpos(&l, 2, 24);
    display(l);

    printf("RemovedElement = %d\n", removefromFirst(&l));
    display(l);

    printf("RemovedElement = %d\n", removefromEnd(&l));
    display(l);

    printf("RemovedElement = %d\n",removefromposition(&l, 2));
    display(l);

    printf("Count = %d\n", length(l));

    destroy(&l);
    display(l);

    fill(&l, 10);
    display(l);

    reverse(&l);
    display(l);


    return 0;

}
