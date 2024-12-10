#include"header.h"

void init(List *l){
    *l = NULL;
}

void display(List l){

    printf("circular LL :\n");
    if(l==NULL) return;

    Node *p = l;
    printf("%d-> ",l->data);
    p = p->next ;
    while(p != l){
        printf("%d-> ",p->data);
        p = p->next;
    }
    printf("\n");
    return ;
}

void append(List *l, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));

    if(newnode== NULL) return ;

    newnode -> data = data; 
    newnode-> next = *l;

    if(*l== NULL){
        *l = newnode;
        newnode -> next = newnode;
        return ;
    }

    Node *temp = *l;
    while(temp -> next != *l){
        temp = temp -> next ;
    }
    temp -> next = newnode ;
    return ;

}

void insertAtBeg(List *l, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));

    if(newnode == NULL) return ;

    newnode -> data = data;
    newnode -> next = *l;

    Node *temp = *l;
    while(temp->next != *l){
        temp = temp->next;
    }
    temp->next = newnode;
    *l = newnode ;
    return ;
}

void insertAtpos(List *l, int index, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));

    if(!newnode) return ;
    newnode->data =data;
    newnode->next = NULL;

    if(index<0) return ;

    if(index==0){
        insertAtBeg(l,data);
    }
    
    Node *temp = *l;
    if(temp->next==*l){
        append(l, data);        
    }

    for(int i = 0; i<index-1; i++){
        temp = temp -> next;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
    return ;
}

int removefromFirst(List *l){
    Node *p, *q;
    int removeElement;
    if(*l == NULL) return -1 ;
    p = *l;
    if(p->next == NULL){
        removeElement = p->data;
        *l = NULL;
        free(p);
        return removeElement;
    }

    while(p->next != *l){
        p = p->next;
    }
    q = p->next;
    removeElement = q->data;
    p->next =p->next->next;
    *l = p->next;
   
    free(q);

    return removeElement;
}

int removefromEnd(List *l){
    Node *p, *q;
    int removeElement;

    if(*l== NULL) return -1 ;
    p = *l;
    if(p->next == NULL){
        removeElement = p->data;
        *l = NULL;
        free(p);
        return removeElement;
    }
    while(p->next->next != *l){
        p = p->next;
    }
    q=p->next;
    p->next =p->next->next;
    *l = p->next;
    removeElement = q->data;
    free(q);
    return removeElement;
}

int removefromposition(List *l,int index){
    Node *p, *q;
    int removeElement;

    if(*l== NULL) return -1;
    p = *l;
    if(p->next == NULL){
        removeElement= p->data;
        *l = NULL;
        free(p);
        return removeElement;
    }
    if(p->next==*l){
        removefromFirst(l);
    }
    if(p->next->next == *l){
        removefromEnd(l);
    }
    while(p->next < index-1){
        p = p->next;
    }
    q = p->next;
    removeElement = q->data;
    p->next = p->next->next;
    *l = p->next;
    free(q);
    return removeElement;
}
int length(List l){
    Node *p =l->next;
    int count = 1;
    
    while(p != l){
        count++;
        p=p->next;
    }
    return count;
}

void destroy(List *l){
    if(*l == NULL) return ;
    
    Node *p = (*l)-> next;
    (*l)-> next =NULL;

    while (p != *l)
    {
        Node *q  = p;
        p = p->next;
        free(q);
    }
    free(p);
    *l = NULL;

    return ;
}

void fill (List *l, int num){
    if(num < 1) return ;
   
    for(int i = 0; i< num; i++){
        append(l,rand()%100 +1);
    }
    return ;
}

void reverse(List *l) {
    if (*l == NULL || (*l)->next == *l) return;  // If list is empty or has only one node, return

    Node *p = NULL, *q = NULL, *temp = *l;

    do {
        q = p;             // Move q to p
        p = temp;          // Move p to temp
        temp = temp->next; // Move temp to next node
        p->next = q;       // Reverse the link
    } while (temp != *l);  // Continue until you reach the original head again
    printf("%d\n", temp->data);
    // Fix the last node to point to the new head
    (*l)->next = p;

    // Update head to the new reversed head
    *l = p;

    return;
}
