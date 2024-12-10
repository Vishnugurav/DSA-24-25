#include "logic.c"

 int main(){
    queue q;
    init(&q);
    enque(&q, 17);
    enque(&q, 24);
    enque(&q, 57);
    enque(&q, 44);
    enque(&q, 19);
    enque(&q, 4);
    enque(&q, 7);
    enque(&q, 2);

    display(q);

    deque(&q);
    deque(&q);
    deque(&q);
    deque(&q);
    deque(&q);

    display(q);

    return 0;

}
