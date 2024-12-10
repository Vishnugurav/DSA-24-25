#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

typedef struct Stack{
    int top;
    char *A;
    int size;
}Stack;


void init(Stack *s, int size){
    s->A = (char*)malloc(sizeof(char) * size);
    s->top = -1;
    s->size = size;
}

void push(Stack *s, char data){
    if(s->top == s->size-1) return;

    s->A[++s->top] = data;
}

char pop(Stack *s){

    if(s->top == -1) return '\0' ;
    return s->A[s->top--];
}

char peek(Stack *st) {
    if (st->top == -1) {  
        return '\0';  // Empty stack
    }
    return st->A[st->top];
}

int prec(char oprnd){
    if(oprnd == '+' || oprnd == '-') return 1;
    if(oprnd == '*' || oprnd == '/') return 2;
    return 0;
}


void infixtopostfix(char infix[], char postfix[]){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init(s, 100);  // Initialize stack with size 100
    
    int i = 0, j = 0;

    while(infix[i] != '\0'){

        if(isalnum(infix[i])){
            postfix[j++] = infix[i];
        }else if(infix[i] == '('){
            push(s, infix[i]);
        }else if(infix[i]== ')'){
            while(peek(s) != '(' && s->top != -1){
                postfix[j++] = pop(s);
            }
            pop(s);
        }else{
            while(s->top != -1 && prec(peek(s)) >= prec(infix[i])){
                postfix[j++] =  pop(s);
            }
            push(s, infix[i]);
        }
        i++;
    }
    while(s->top != -1){
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
    
    free(s->A);
    free(s);
    return ;
}


int main(){
    char infix[100] = "A+B/C*(D+C)-F";
    char postfix[100]; 
    infixtopostfix(infix,postfix);
    printf("Post Expression %s\n", postfix);
    return 0;
}