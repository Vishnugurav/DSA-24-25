#include <stdio.h>
#include <stdlib.h>
#include "logic.c"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    heap h1;
    init_heap(&h1, 10);

    readfileandinsert(&h1, argv[1]);

    printf("Heap before sorting:\n");
    print_heap(h1);

    printf("\nSorted elements:\n");
    heap_sort(&h1);

    free(h1.h);
    return 0;
}
