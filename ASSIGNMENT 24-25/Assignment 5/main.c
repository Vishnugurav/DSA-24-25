#include<stdio.h>
#include<stdlib.h>
#include "logic.c"
#include <string.h>

int main() {
    BST tree;
    initBST(&tree);

    int choice;
    char month[10];

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Remove Node\n");
        printf("3. Traverse (In-order)\n");
        printf("4. Destroy Tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter month to insert: ");
                scanf("%s", month);
                insertnode(&tree, month);
                printf("Node with month %s inserted.\n", month);
                break;

            case 2:
                printf("Enter month to remove: ");
                scanf("%s", month);
                removenode(&tree, month);
                break;

            case 3:
                printf("In-order traversal of the tree: ");
                traverse(&tree);
                break;

            case 4:
               destroyBST(&tree);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}