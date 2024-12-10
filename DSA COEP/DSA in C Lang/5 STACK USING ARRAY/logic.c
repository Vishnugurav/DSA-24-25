#include"header.h"

void init(stack *st, int size){
    if(size < 1)
    return;

    st->size =size;
    st->top = -1;
  
    st->A = (int*)malloc(sizeof(int)*size);
    return ;
    
}

int isEmpty(stack st){
    if(st.top == -1)
        return 1; 
        
    return 0;
}

int isFull(stack st){
    if(st.top == (st.size-1))
        return 1;
    
    return 0;
}

void push(stack *st, int element){
    if(isFull(*st)) return ;

    st->A[++st->top] = element;
    return ;

}

int pop(stack *st){
    if(isEmpty(*st)) return INT_MIN ;

    return st->A[st->top--];
}

int peekTop(stack st){
    if(isEmpty(st)) return INT_MIN ;

    return st.A[st.top];
}

void display(stack st){
    printf("displaying the stack:\n");
    while(st.top != -1){
        printf("%d ",st.A[st.top--]);  
    }
    printf("\n");
    return ;
}

int peek(stack st,int index){
    int x=-1;
    if(st.top-index+1<0) 
    return -1;  
    x=st.A[st.top-index+1];
    return x;
}