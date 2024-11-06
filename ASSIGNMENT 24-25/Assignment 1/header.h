typedef struct Array{
	int *A;
	int size;
	int length;
	
}Array;

void init(Array *arr, int size);
void append (Array *arr, int element);
void insert_at_index(Array *arr, int index, int element);
void remove_at_index(Array *arr, int index);
void display(Array arr);
int Max(Array *arr);
int Min(Array *arr);
void reverse(Array *arr);
Array merge(Array *arr1, Array *arr2);