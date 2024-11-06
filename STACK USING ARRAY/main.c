#include<stdio.h>
#include<stdlib.h>
#include"logic.c"

int main(){
    struct stack st;
    // printf("enter the size if stack");
    // scanf("%d",&st.size);
    // st.s = (stack*)malloc(sizeof(stack));
    // st.top = -1;
    
    init(&st, 5);
    push(&st, 07);
    push(&st, 8);
    push(&st, 9);
    push(&st, 11);
    push(&st, 13);
    
    display(st);

    printf("Pop element from the stack %d\n ",pop(&st));
    printf("Pop element from the stack %d\n ",pop(&st));
    display(st);

    int index = peek;
    if(index == 1)
    printf("Peek element from the stack %d\n ",peek(st,9));
    else
    printf("INVALID INDEX\n");

    printf("Peek element from the stack %d\n ",peekTop(st));

    return 0;
}