#include "logic.c"



int main (){
    BST t;
    init(&t);
    
    insertatbst(&t, 24);
    insertatbst(&t, 14);
    insertatbst(&t, 44);
    insertatbst(&t, 34);
    insertatbst(&t, 29);
    insertatbst(&t, 25);
    insertatbst(&t, 22);
    
    preorder(t);
    printf("\n");
    deletebst(&t, 34);
    preorder(t);

    // int data = 44;
    // node *result = search(t, data);
    // printf("\n");
    // if (result != NULL) {
    //     printf("Element %d found in the BST.\n", result->data);
    // } else {
    //     printf("Element %d not found in the BST.\n", data);
    // }
    printf("\n");
    mirror_bst(&t);
    preorder(t);
    return 0;
}
