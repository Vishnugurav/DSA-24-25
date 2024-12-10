#include"logic.c"

int main(){
    hashTable ht;
    init(&ht, 10);
    insertVal(&ht, 30);
    insertVal(&ht, 40);
    insertVal(&ht, 50);
    insertVal(&ht, 55);
    display(&ht);
    deleteVal(&ht, 40);
    display(&ht);
    return 0;
}
