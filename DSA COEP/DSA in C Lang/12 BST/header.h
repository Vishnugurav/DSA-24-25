typedef struct node {
    int data;
    struct node * rchild;
    struct node *lchild;
}node;
    
typedef struct node *BST;

void init (BST *t);
void insertatbst(BST *t, int data);
void preorder(BST t);
void deletenode(BST *t, int data);
void deletebst(BST *t, int data);
node *search(BST t, int data);
node *inorder_successor(BST t);
void mirror_bst(BST *t);