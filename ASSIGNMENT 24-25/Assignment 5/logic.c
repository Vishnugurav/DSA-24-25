#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "header.h"

void initBST(BST *tree){
    tree->t = NULL;
}

Node* createNode(char *month){
    Node *nn = (Node*)malloc(sizeof(Node));
    strcpy(nn->month, month);
    nn->lchild = nn->rchild = nn->parent = NULL;
    return nn;
} 

void insertnode(BST *tree, char *month){
    Node *nn = createNode(month);
    if (tree->t== NULL){
        tree->t = nn;
        return;
    } 
    Node *current = tree->t;
    Node *parent = NULL;
    while (current != NULL){
        parent = current;
        if (strcmp(month, current->month) < 0){
            current = current->lchild;
        }else{
            current = current->rchild;
        }
    }
    nn->parent = parent;
    if (strcmp(month, parent->month) < 0){
        parent->lchild= nn;
    }else{
        parent->rchild = nn;
    }
    return ; 
} 

Node* findMin(Node *node){
    while (node->lchild != NULL){
        node = node->lchild;
    }
    return node;
}

void removenode(BST *tree, char *month){
    Node *current = tree->t;
    Node *parent = NULL;


    while (current != NULL && strcmp(current->month, month) != 0){
        parent = current;
        if (strcmp(month, current->month) < 0) {
            current = current->lchild;
        } else {
            current = current->rchild;
        }
    }

    if (current == NULL) {
        printf("Node with month %s not found.\n", month);
        return;
    }


    Node *child;
    if (current->lchild == NULL || current->rchild == NULL){
        child = current->lchild ? current->lchild : current->rchild;
        

        if (parent == NULL){
            tree->t = child;
        }
        else if (parent->lchild == current){
            parent->lchild = child;
        } else {
            parent->rchild= child;
        }
        
        if (child != NULL){
            child->parent = parent;
        }
        free(current);
    }

    else{
        Node *successor = findMin(current->rchild);
        strcpy(current->month, successor->month);  
        removenode(tree, successor->month);         
    }

    printf("Node with month %s removed.\n", month);
    return ;
}

void traverse(BST *tree){
    if (tree->t == NULL) return;

    Node *current = tree->t;
    Node *stack[100];  
    int top = -1;

    while (current != NULL || top != -1){

        while (current != NULL) {
            stack[++top] = current;
            current = current->lchild;
        }


        current = stack[top--];
        printf("%s ", current->month);  


        current = current->rchild;
    }
    return ;
}

void destroyTree(Node *node){
    if (node == NULL) {
        return;
    }
    destroyTree(node->lchild);
    destroyTree(node->rchild);
    free(node);
}

void destroyBST(BST *tree){
    destroyTree(tree->t);
    tree->t = NULL;
    printf("Tree destroyed.\n");
}
