#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Twostacks* createTwostacks(int capacity){
    Twostacks *stack = (Twostacks *)malloc(sizeof(Twostacks));
    if (!stack) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->maxCapacity = capacity;
    stack->data = (int *)malloc(capacity * sizeof(int));
    if (!stack->data) {
        printf("Memory allocation for data array failed\n");
        free(stack);
        exit(1);
    }
    stack->leftTop = -1;
    stack->rightTop = capacity;
    return stack;
}

void push1(Twostacks *stack, int value){
    if (stack->leftTop + 1 < stack->rightTop) {
        stack->data[++stack->leftTop] = value;
    } else {
        printf("Stack Overflow in stack 1\n");
    }
}

void push2(Twostacks *stack, int value){
    if (stack->leftTop + 1 < stack->rightTop) {
        stack->data[--stack->rightTop] = value;
    } else {
        printf("Stack Overflow in stack 2\n");
    }
}

int pop1(Twostacks *stack){
    if (stack->leftTop >= 0) {
        return stack->data[stack->leftTop--];
    } else {
        printf("Stack Underflow in stack 1\n");
        return -1;
    }
}

int pop2(Twostacks *stack) {
    if (stack->rightTop < stack->maxCapacity) {
        return stack->data[stack->rightTop++];
    } else {
        printf("Stack Underflow in stack 2\n");
        return -1;
    }
}

void displayStack(Twostacks *stack) {
    printf("Stack 1: ");
    for (int i = 0; i <= stack->leftTop; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");

    printf("Stack 2: ");
    for (int i = stack->maxCapacity - 1; i >= stack->rightTop; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int isBalanced(char *expression){
    char stack[MAX];
    int stackTop = -1;
    for (int i = 0; expression[i]; i++){
        char current = expression[i];
        if (current == '(' || current == '{' || current == '[') {
            stack[++stackTop] = current;
        } else if (current == ')' || current == '}' || current == ']') {
            if (stackTop == -1) return 0;
            char lastBracket = stack[stackTop--];
            if ((current == ')' && lastBracket != '(') ||
                (current == '}' && lastBracket != '{') ||
                (current == ']' && lastBracket != '[')) {
                return 0;
            }
        }
    }
    return stackTop == -1;
}

void reverseString(char *input, char *output){
    char stack[MAX];
    int stackTop = -1;
    for (int i = 0; input[i]; i++){
        stack[++stackTop] = input[i];
    }
    for (int i = 0; i <= stackTop; i++){
        output[i] = stack[stackTop - i];
    }
    output[stackTop + 1] = '\0';
}

void displayReversedString(char *reversed){
    printf("Reversed string: %s\n", reversed);
}

void decimalToBinary(int number, char *binary){
    int stackTop = -1;
    while(number > 0){
        binary[++stackTop] = (number % 2) + '0';
        number /= 2;
    }

    for(int i = 0; i <= stackTop / 2; i++){
        char temp = binary[i];
        binary[i] = binary[stackTop - i];
        binary[stackTop - i] = temp;
    }
    binary[stackTop + 1] = '\0';
}
