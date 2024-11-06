#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
    }Node;

typedef struct stack{
    Node *top;
}Stack;

void init(Stack *s){
    s->top = NULL;
}
    
void push(Stack *s,char x){
    struct Node *t;    
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    printf("stack is full\n");
    else{  
        t->data=x;        
        t->next=s->top;
        s->top=t;    
        }
    }

char pop(Stack *s){
    Node *temp;
    char x=-1;
    if(s->top==NULL)
    printf("Stack is Empty\n");
    else{        
        temp=s->top;
        s->top=s->top->next;
        x=temp->data;
        free(temp);    
    }return x;
}

void Display(Stack *s){
    Node *temp;
    temp=s->top;
    
    while(temp !=NULL){
        printf("%c ",temp->data);
        temp=temp->next;    
    }
    printf("\n");
    }
    
int isBalanced(Stack *s,char *exp){
    int i;
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i] == '['){
            push(s,exp[i]);
            Display(s);
        }
        
        else if(exp[i]==')' || exp[i] == ']'){
            if(s->top==NULL) return 0;
            pop(s); 
            Display(s);       
        }    
    }
    if(s->top==NULL) return 1;
    else return 0 ;
}
int main(){
    Stack s;
    char *exp="[((a+b)*(c-d)))]";
    Display(&s);
    printf("%d ",isBalanced(&s,exp));
    Display(&s);
    return 0;
}