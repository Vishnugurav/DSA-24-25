#include "logic.c"

int main(){
    Stack s;
    init(&s);
    push(&s, 89);
    push(&s, 88);
    push(&s, 87);
    push(&s, 86);
    push(&s, 85);
    push(&s, 84);
    push(&s, 83);
    push(&s, 82);
    display(&s);

    printf("Peek element: %d\n",peek(s));

    printf("Pop element: %d\n",pop(&s));
    printf("Pop element: %d\n",pop(&s));
    printf("Pop element: %d\n",pop(&s));
    printf("Pop element: %d\n",pop(&s));
    display(&s);

    printf("Peek element: %d\n",peek(s));

    int empty = isEmpty(s);
    if(empty==-1){
        printf("Stack is Empty");
    }else{
        printf("Stack is not empty");
    }

    return 0;
}
