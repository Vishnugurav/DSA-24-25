typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}Node;

typedef struct ASCII{
 Node * head;
 Node * tail;
}ASCII ;


void init_ASCII(ASCII *list);
void  ASCII_of(ASCII *list, char c);
void  traverse(ASCII *list);
void Destroy(ASCII *list);