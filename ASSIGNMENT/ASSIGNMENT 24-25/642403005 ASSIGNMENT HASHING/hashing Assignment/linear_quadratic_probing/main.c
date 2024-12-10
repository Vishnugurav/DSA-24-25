#include"probing.c"

int main(){
    // linear probing
    hashTable ht;
    init(&ht, 10);
    insertUsingLinear(&ht, 35);
    insertUsingLinear(&ht, 40);
    insertUsingLinear(&ht, 45);
    insertUsingLinear(&ht, 50);
    insertUsingLinear(&ht, 30);
    insertUsingLinear(&ht, 132);
    insertUsingLinear(&ht, 102);
    display(&ht);
    deleteUsingLinear(&ht, 40);
    display(&ht);

    // quadratic probing
//     init(&ht, 10);
//     insertUsingQuadratic(&ht, 35);
//     insertUsingQuadratic(&ht, 40);
//     insertUsingQuadratic(&ht, 45);
//     insertUsingQuadratic(&ht, 50);
//     insertUsingQuadratic(&ht, 30);
//     insertUsingQuadratic(&ht, 132);
//     insertUsingQuadratic(&ht, 102);
//     display(&ht);
//     deleteUsingQuadratic(&ht, 40);
//     display(&ht);
    return 0;
}
