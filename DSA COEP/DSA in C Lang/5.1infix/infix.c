#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define Stack structure using typedef
typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Function to create a stack
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an item to the stack
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1; // Should not happen in valid postfix expressions
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression[], int length) {
    Stack* stack = createStack(length); // Create a stack

    for (int i = 0; i < length; i++) {
        char* token = expression[i];

        // If the token is a number, push it to the stack
        if (isdigit(token[0])) {
            push(stack, atoi(token));
        } else {
            // Token is an operator, pop two elements and apply the operator
            int val2 = pop(stack); // Second operand
            int val1 = pop(stack); // First operand

            switch (token[0]) {
                case '+': push(stack, val1 + val2); break;
                case '-': push(stack, val1 - val2); break;
                case '*': push(stack, val1 * val2); break;
                case '/': push(stack, val1 / val2); break;
            }
        }
    }

    // The final result will be at the top of the stack
    return pop(stack);
}

int main() {
    // Postfix expression
    char* expression[] = {"4", "2", "+", "3", "5", "1", "-", "*", "+"};
    int length = sizeof(expression) / sizeof(expression[0]);

    // Evaluate and print the result
    int result = evaluatePostfix(expression, length);
    printf("Result: %d\n", result);

    return 0;
}


