#include<stdio.h>
#include<stdlib.h>
#include "header.h"

void init(list *head){
    *head = NULL ;
    return ;
}

void append(list *head, int data){

    Node *newnode, *temp;

    newnode = (Node*)malloc(sizeof(Node));
    
    if(!newnode) return ;

    newnode->data = data;
    newnode->next = NULL;
    
   

    if (*head == NULL){
        *head = newnode;
        return ;
    }
    
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = newnode;
    return ;   
}

void display(list head){
    printf("linkedlist = ");
    Node* temp = head;
    while(temp){
        printf(" %d -> ", temp->data);
        temp = temp ->next; 
    }
    printf("NULL  \n");
    return ;
}

void RDisplay(list head){

    Node *temp = head;
    
    if(temp != NULL){             
        printf("%d -> ",temp->data);  
        RDisplay(temp->next);  
    }
    if(temp==NULL){
        printf("\b NULL  \n");
    }
    
    return ;
}

void insertAtBeginning(list *head, int data){
    Node * newnode = (Node*)malloc(sizeof(Node));
    
    if(newnode==NULL) return ;

    newnode -> data = data ;
    newnode -> next = *head ;

    *head = newnode;
    return ;    
}

void insertAtPosition(list *head,int data, int position ){
    if(position<0 || position > count(*head)) return ;
        
    Node *newnode, *temp;

    newnode = (Node*)malloc(sizeof(Node));
    
    if(newnode!= NULL){
        newnode ->data =data;
        newnode ->next = NULL;
    }
    else return;

    if(position==0){
        newnode->next = *head;
        *head = newnode;
    }
    else {
        temp =  *head;
        for(int i = 0; i<position-1 ; i++){
            temp = temp-> next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return ;
}

void insertAtEnd(list *head, int data){

    Node *newnode, *temp;
    newnode = (Node*)malloc(sizeof(Node));
    if(newnode){
        newnode -> data = data;
        newnode -> next = NULL;
    }
    else return ;
    

    if(*head == NULL){
        *head = newnode;
        return ;
    }
    temp = *head;
    while(temp->next!= NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    return ;
}


int count(list head){
    int c = 0;
    Node *temp = head;

    while(temp != NULL ){
        c++;
        temp = temp -> next;
    }
    return c;

}

int sums(list head){
    int sum = 0;
    Node *temp = head;
    while(temp != NULL){
        sum = sum + temp->data;
        temp = temp -> next;
    }
    return sum; 
}

int Rsum(list head) {
    Node *temp = head;  // No need to dereference head, it's already a pointer
    if(temp == NULL) {
        return 0;  // Return 0 when the list is empty
    } else {
        return Rsum(temp->next) + temp->data;  // Recursively add the data of the nodes
    }
}

int Max(list head){
    int m; 
    Node *temp = head;
    while(temp){
        if(temp->data > m){
            m = temp-> data;
        }
        temp = temp -> next; 
    }
    return m;
}

int search(list head, int element){
    Node *temp;
    temp = head;
    int count = 0;
    while(temp!=NULL){
        if(element == temp-> data){
            count++;
            return count;
        }
        else{
            temp = temp-> next; 
            count++; 
        }
        
    }
    
    printf(" This element is not found ");
    return -1;
}

int isSorted(list head){
    int x=-65536;
    Node *temp = head;   
    while(temp!=NULL){
        if(temp->data < x)
            return 0;        
        x=temp->data;        
        temp = temp -> next;    
    }
    return 1;
}

void sortedinsert(list *head, int element) {
    Node *newnode, *p, *q;
    newnode = (Node*)malloc(sizeof(Node));
    
    if (!newnode) return;  // Check memory allocation failure
    
    newnode->data = element;
    newnode->next = NULL;  // Initialize next to NULL
    
    if (*head == NULL) {  // If the list is empty
        *head = newnode;
        return;
    }

    p = *head;
    q = NULL;

    // Traverse to find the correct position
    while (p && p->data < element) {
        q = p;
        p = p->next;
    }

    if (p == *head) {  // Insertion at the head
        newnode->next = *head;
        *head = newnode;
    } else {  // Insertion in the middle or end
        q->next = newnode;
        newnode->next = p;  // Connect to the remaining list
    }
}

void insert(list *head, int index, int data){
    Node *newnode, *temp;
    if(index < 0 || index > count(*head)){
        printf("invalid index\n");
        return ;
    }

    newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> next = NULL;

    temp = *head;
    
    if(index == 0){
        newnode -> next = *head ;
        *head = newnode ;
    }
    else{
        for(int i = 0; i < index-1  ; i++){
            temp = temp -> next;
        }
        newnode -> next = temp -> next ;
        temp -> next = newnode ;
    }
}

void deleteFromFirst(list *head){
    Node *temp;
    temp = *head;
    if(*head != NULL){
        *head = temp -> next;
    }
    free(temp);
    return ;

}

void deletefromPosition(list *head, int position){
    if(position < 0 || position > count(*head)){
        printf("invalid position\n");
        return ;
    }
    Node *p, *q;
    p = *head;
    q = NULL;

    if(position == 0){
        *head = p-> next;
        free(p);
        return;
    }
    for(int i = 0; i< position-1; i++){
        q = p;
        p = p-> next;
    }
    q -> next = p ->next;
    free(p); 
    return;
    
}

void deletefromEnd(list *head){
    Node *temp, *q;
    temp =*head;
    q = NULL;

    if (*head == NULL) return ;

    while(temp->next!=NULL){
        q = temp;
        temp = temp -> next;
    }
    free(temp);
    q-> next = NULL;
    
}

void removeDuplicates(list *head){
    Node *p, *q, *temp;
    p = *head;
    

    while (p!=NULL && p -> next != NULL){
        q = p;
        while(q->next!= NULL){
            if(p->data == q->next->data){
                temp = q-> next;
                q-> next = temp -> next;
                free (temp);
            } 
            else{
                q = q-> next;
            }
        }
        p = p->next;
    }
}

void ReversingElements(list *head ){
    Node *temp = *head;
    int *A;
    int i = 0;

    A = (int*)malloc(sizeof(int)*count(*head));

    while(temp!= NULL){
        A[i] = temp->data;
        i++;
        temp = temp->next;
    }

    temp = *head;
    i--;
    while(temp != NULL){
        temp->data = A[i--];
        temp = temp -> next;    
    }
    return ;
}

void reverselink(list *head){ 
    Node *temp,*p, *q;
    temp = *head;
    p = NULL;
    q = NULL;

    while(temp != NULL){
        q = p;
        p = temp;
        temp = temp ->next;
        p ->next = q;
    }
    *head = p;
    return ;
}

void concatenating(list *linklist1, list *linklist2){
    Node *temp;
    
    if(linklist1 == NULL){
        *linklist1 = *linklist2;
    }
    temp = *linklist1;
  
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp ->next = *linklist2;
   // *linklist2 = NULL;

    return ;
}

void sortmerge(list *linklist1, list *linklist2){
    Node *temp, *p , *linklist3, *q;
    temp = *linklist1;
    p = *linklist2;
    linklist3 = NULL;
    q = NULL;
    
    if( temp -> data < p->data){
        linklist3 = q = temp;
        temp = temp -> next;
        q -> next = NULL ;
    }else{
        linklist3 = q = p;
        p = p->next;
        q->next = NULL ;
    }
    

   while(temp != NULL && p != NULL){
        if(temp->data < p->data){
            q->next = temp;
            q = temp;

            temp = temp -> next;
            q->next = NULL; 
        }else{
            q -> next = p;
            q = p;
         
            p = p -> next;
            q -> next =NULL;
        }
    }

    *linklist1 = linklist3;;

    return ;
    
}

void destroy(list *head){
    Node *p = *head;
    Node *q = NULL;
    while(p){
        q=p;
        p = p -> next ; 
        free (q);
    }
    *head = NULL;
}
