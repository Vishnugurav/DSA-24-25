#include "logic.c"

int main(){
    CQueue q;
    init(&q, 7);

    enque(&q, 2);
    enque(&q, 4);
    enque(&q, 6);
    enque(&q, 8);
    enque(&q, 10);
    enque(&q, 12);
    display(q);

    deque(&q);
    deque(&q);
    deque(&q);
    deque(&q);
    display(q);

    enque(&q, 1);
    enque(&q, 3);
    enque(&q, 5);
    enque(&q, 7);
    enque(&q, 70);
    display(q);

    return 0;
}