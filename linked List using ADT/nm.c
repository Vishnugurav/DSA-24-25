#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef Node *list;

void init(list *l){
    *l = NULL;
    return;
}

void append(list *l, int data){
    Node *nn = (Node*)malloc(sizeof(Node));
    if(!nn) return;
    nn->data = data;
    nn->next = *l;

    if(*l == NULL){
        *l = nn;
        nn->next = *l;
        return;
    }
    Node *temp =*l;
    while(temp->next != *l){
        temp = temp->next;
    }
    temp->next = nn;
    return ;
}

void removefromindex(list *l, int index){
    Node *p, *q;
    p = *l;
    if(index == 0){
        while(p->next != *l){
            p = p->next;
        }
            if(p->next == *l){
                *l = NULL;
                free(p);
                
            }else{
                q = p->next;
                p->next = q->next;
                free(q);
                
            }
            return ;
        }
       
    
    p = *l;
    int i = 0;
    while(i< index || p->next != *l){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        free(q);
        return ;
}

void display(list l){
    if(l == NULL) return;

    Node * temp = l;
    do{
        printf("%d->", temp->data);
        temp = temp->next;
    }while(temp != l);
    printf("\n");
    return ;
}

int main(){
    list l;
    init(&l);
    append(&l, 10);
    display(l);
    append(&l, 18);
    append(&l, 19);
    append(&l, 11);
    append(&l, 12);

    display(l);

    removefromindex(&l, 1);
    display(l);
    return 0;

}