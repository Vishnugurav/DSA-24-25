typedef struct heap {
    int *h;
    int size;
    int rear;
} heap;

void init_heap(heap *h1, int v);          
void insert_heap(heap *h1, int v);        
void delete_max(heap *h1);                
void print_heap(heap h1);                 
void heap_sort(heap *h1);                 
void heapify(heap *h1);                   
int parent(int index);                     
void swap(heap *h1, int a, int b);
void readfileandinsert(heap *h1, const char *filename);