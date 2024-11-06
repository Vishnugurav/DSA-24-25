typedef struct Node{
    char month[10];
    struct Node *lchild;
    struct Node *rchild;
    struct Node *parent;
}Node;
typedef struct BST {
 Node *t;
} BST;
void initBST(BST* tree);
void insertnode(BST *tree, char *month);
void removenode(BST *tree, char *month);
void traverse(BST *tree);
void destroyTree(Node *n);
void destroyBST(BST *tree);