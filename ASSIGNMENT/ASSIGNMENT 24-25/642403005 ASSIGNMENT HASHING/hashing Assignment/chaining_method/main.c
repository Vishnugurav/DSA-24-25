#include"header.h"

int main(){
    hashTable ht;
    init(&ht, 10);
    insertVal(&ht, 45);
    insertVal(&ht, 56);
    insertVal(&ht, 63);
    insertVal(&ht, 72);
    insertVal(&ht, 33);
    insertVal(&ht, 149);
    display(&ht);
    deleteVal(&ht, 56);
    deleteVal(&ht, 149);
    display(&ht);
    return 0;
}
