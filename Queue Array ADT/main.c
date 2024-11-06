#include "logic.c"

int main (){
    queue q;
    init(&q, 10);
    
    enque(&q, 10);
    enque(&q, 20);
    enque(&q, 30);
    enque(&q, 40);
    enque(&q, 50);
    enque(&q, 60);

    display(q);

    deque(&q);
    deque(&q);
    deque(&q);
    deque(&q);

    display(q);

}