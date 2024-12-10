typedef struct hashTable{
    int size;
    int* data;
}hashTable;

void init(hashTable * ht, int size);
int hashFunction(int val, int size);
void insertUsingLinear(hashTable *ht, int val);
void deleteUsingLinear(hashTable *ht, int val);
void insertUsingQuadratic(hashTable *ht, int val);
void deleteUsingQuadratic(hashTable *ht, int val);
void display(hashTable * ht);