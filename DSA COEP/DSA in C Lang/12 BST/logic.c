#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node * rchild;
    struct node *lchild;
}node;
    
typedef node *BST;

void init (BST *t){
    *t = NULL;
    return ;
}
    
void insertatbst(BST *t, int data){
    node *nn = (node *)malloc(sizeof(node));
    nn->data = data;
    nn->rchild = NULL;
    nn->lchild = NULL;
    
    if(*t == NULL){
        *t = nn;
        return ;
    }
    
    node *p = *t;
    node *q = NULL;
    while(p != NULL){
        q = p;
        if(p->data > data){
            p = p->lchild;
        }else if(p->data < data){
            p = p->rchild;
        }else{
            free(nn);
            return ;
        }
        
    }
    if(q->data >data){
        q->lchild = nn;
    }else{
        q->rchild = nn;
    }
    return;

}

void preorder(BST t){
    if(t == NULL) return;
     
    printf("%d  ", t->data);
    preorder(t->lchild);
    
    preorder(t->rchild);
    return ;
}

node *inorder_successor(BST t){
    node *p = t;
    if (p == NULL || p->rchild == NULL) return NULL;
    p = p->rchild;
    while (p->lchild != NULL) {
        p = p->lchild;
    }
    return p;
}

node *inorder_predecessor(BST t) {

    node *p = t;
    if (p == NULL || p->lchild == NULL) return NULL;
    p = p->lchild;
    while (p->rchild != NULL) {
        p = p->rchild;
    }
    return p;
}

void deletebst(BST *t, int data){
    if (*t == NULL) return; 

    node *p = *t; 
    node *q = NULL; 
    char direction;

    // Search for the node to delete
    while (p && p->data != data) {
        q = p;
        if (p->data > data) {
            p = p->lchild;
            direction = 'l';
        } else {
            p = p->rchild;
            direction = 'r';
        }
    }
    if(p == NULL) return;

    if(p->lchild == NULL && !p->rchild){
        if(!q){
            *t = NULL;
        }else if(direction == 'l'){
            q->lchild = NULL;
        }else{
            q->rchild = NULL;
        }
        free(p);
        return ;
    }

    
    if(!p->lchild || !p->rchild){
        node *child =(p->lchild)?p->lchild :p->rchild;
        if(q == NULL){
            *t= child;
        }else if(direction == 'l'){
            q->lchild = child;
        }else{
            q->rchild = child;
        }
        free(p);
        return ;
    }

    node *successor = inorder_successor(*t);
    int successorData = successor->data;
    deletebst(t, successorData);
    p->data = successorData;
}

void deletenode(BST *t, int data) {
    if (*t == NULL) return; // Tree is empty

    node *p = *t; // Pointer to the current node
    node *q = NULL; // Pointer to the parent node
    char direction;

    // Search for the node to delete
    while (p && p->data != data) {
        q = p;
        if (p->data > data) {
            p = p->lchild;
            direction = 'l';
        } else {
            p = p->rchild;
            direction = 'r';
        }
    }


    // Node not found
    if (!p) return;

    // Case 1: Node has no children (leaf node)
    if (!p->lchild && !p->rchild) {
        if (!q) {
            *t = NULL; // Node is the root
        } else if (direction == 'l') {
            q->lchild = NULL;
        } else {
            q->rchild = NULL;
        }
        free(p);
        return;
    }

    // Case 2: Node has only one child
    if (p->lchild == NULL || p->rchild == NULL) {
        node *child = (p->lchild) ? p->lchild : p->rchild;

        if (!q) {
            *t = child; // Node is the root
        } else if (direction == 'l') {
            q->lchild = child;
        } else {
            q->rchild = child;
        }
        free(p);
        return;
    }

    // Case 3: Node has two children
    node *r = p; // Reference to the node being deleted
    node *qSuccessor = p->rchild; // Start with the right child
    direction = 'r'; // Initial direction is 'right'

    // Find the in-order successor (smallest in the right subtree)
    while (qSuccessor->lchild) {
        r = qSuccessor;
        direction = 'l';
        qSuccessor = qSuccessor->lchild;
    }

    // Replace p's data with the successor's data
    p->data = qSuccessor->data;

    // Adjust the links to remov the successor node
    if (direction == 'l') {
        r->lchild = qSuccessor->rchild;
    } else {
        r->rchild = qSuccessor->rchild;
    }

    free(qSuccessor); // Free the memory of the successor
}

node *search(BST t, int data){
    node *p = t;
    while(p){
        if(p->data > data ){
            p = p->lchild;
        }else if(p->data <data){
            p = p->rchild;
        }else{
            return p;
        }
    }
    return NULL;
}

void mirror_bst(BST *t) {
    if (*t == NULL) return;
    BST temp = (*t)->lchild;
    (*t)->lchild = (*t)->rchild;
    (*t)->rchild = temp;

    mirror_bst(&(*t)->lchild);
    mirror_bst(&(*t)->rchild);
}
