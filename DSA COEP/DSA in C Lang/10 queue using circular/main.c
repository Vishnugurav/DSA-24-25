#include "logic.c"

int main(){
    queue q;
    init(&q);
    enque(&q, 2);
    enque(&q, 3);
    enque(&q, 4);
    enque(&q, 5);
    enque(&q, 6);
    enque(&q, 7);

    display(q);

    printf("Removed element from queue : %d\n",deque(&q));
    printf("Removed element from queue : %d\n",deque(&q));
    printf("Removed element from queue : %d\n",deque(&q));

    display(q);

}