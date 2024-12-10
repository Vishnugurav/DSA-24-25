typedef struct node
{
    int d;
    struct node * next;
}node;

typedef struct hashTable
{
    int size;
    node * elements;
}hashTable;

void init(hashTable * ht, int size);
int hashFunction(int val, int size);
void insertVal(hashTable *ht, int val);
void deleteVal(hashTable *ht, int val);
void display(hashTable * ht);
