typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef Node *list;


void init(list *head );
void append(list *head, int data);
void display(list head);   
void insertAtBeginning(list *head, int data);
void insertAtPosition(list *head, int data, int position);
void insertAtEnd (list *head, int data);
int count(list head);
int Rsum(list head);
int sums(list head);
int Max (list head);
int search(list head, int element);
int isSorted(list head);
void sortedinsert(list *head, int element);
void insert(list *head, int index, int data);
void deleteFromFirst(list *head);
void deletefromPosition(list *head, int position);
void deletefromEnd(list *head);
void removeDuplicates(list *head);
void ReversingElements(list *head );
void reverselink(list *head);
void concatenating(list *linklist1, list *linklist2);
void sortmerge(list *linklist1, list *linklist2);
void destroy(list *head);