#include <stdio.h>
#include "logic.c"

int main() {
    queue q;
    data d;

    qinit(&q);
    while (scanf("%s %u", d.name, &(d.age)) != EOF) { // Use EOF instead of -1 for scanf
        if (!qfull(&q))
            enq(&q, d);
    }
    while (!qempty(&q)) {
        d = deq(&q);
        printf("%s %u\n", d.name, d.age);
    }
    return 0;
}
