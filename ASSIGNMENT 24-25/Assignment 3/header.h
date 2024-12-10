#define MAX 100

typedef struct{
    int *data;
    int leftTop;
    int rightTop;
    int maxCapacity;
}Twostacks;

Twostacks* createTwostacks(int capacity);
void push1(Twostacks *stack, int value);
void push2(Twostacks *stack, int value);
int pop1(Twostacks *stack);
int pop2(Twostacks *stack);
void displayStack(Twostacks *stack);
int isBalanced(char *expression);
void reverseString(char *input, char *output);
void displayReversedString(char *reversed);
void decimalToBinary(int number, char *binary);