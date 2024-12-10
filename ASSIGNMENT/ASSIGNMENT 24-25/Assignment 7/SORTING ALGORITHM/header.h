typedef struct Array{
    int * A;
    int size;
    int len;
    
}Array;

void init(Array * arr, int size);
void append(Array * arr, int data);
void display(Array *arr);
void Bubble_Sort(Array * arr);
void Selection_Sort(Array * arr);
void Insertion_Sort(Array * arr);
void swap(int* a, int* b);
int partition(Array * arr, int low, int high);
void quick_sort(Array * arr, int low, int high);
void heap_sort(Array * arr);
void heapify(Array * arr, int n, int i);
