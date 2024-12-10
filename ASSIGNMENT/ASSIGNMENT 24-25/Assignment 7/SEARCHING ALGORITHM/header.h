typedef struct Array{
    int * A;
    int size;
    int len;
    
}Array;

void init(Array * arr, int size);
void append(Array * arr, int data);
void display(Array *arr);
void sort(Array * arr);
void Linear_Search(Array * arr, int element);
void Binary_Search(Array * arr, int element);
