#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Twostacks *stack = createTwostacks(10);
    push1(stack, 10);
    push2(stack, 20);
    displayStack(stack);
    printf("Popped from stack 1: %d\n", pop1(stack));
    printf("Popped from stack 2: %d\n", pop2(stack));
    displayStack(stack);

    char exp1[] = "[()]{}{[()()]()}";
    char exp2[] = "[(])";
    printf("Is balanced (exp1): %d\n", isBalanced(exp1));
    printf("Is balanced (exp2): %d\n", isBalanced(exp2));

    char original[] = "Data Structures Algo";
    char reversed[MAX];
    reverseString(original, reversed);
    displayReversedString(reversed);

    int decimalValue = 10;
    char binary[MAX];
    decimalToBinary(decimalValue, binary);
    printf("Decimal %d to binary is: %s\n", decimalValue, binary);

    free(stack->data);
    free(stack);

    return 0;
}
