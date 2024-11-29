#include <stdio.h>
#include <string.h>

#define MAX 100

char expression[MAX];
char stack[MAX];
int top = -1;

void checkExpression() {
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '(') {
            if (top == MAX - 1) {
                printf("Stack is full. Can't perform validation.\n");
                return;  // Exit if stack is full
            } else {
                stack[++top] = '(';  // Push to stack
            }
        } else if (expression[i] == ')') {
            if (top == -1) {
                printf("No opening parenthesis found, stack is empty.\n");
                printf("Expression is not well-formed.\n");
                return;  // Exit if no matching opening parenthesis
            }
            top--;  // Pop from stack
        }
        // Ignore all other characters (spaces, symbols, etc.)
    }
    
    // After processing the whole expression
    if (top != -1) {
        printf("Expression is not well-formed.\n");
    } else {
        printf("Expression is well-formed.\n");
    }
}

int main() {
    printf("Enter Expression: ");
    scanf("%[^\n]", expression); // Read the full expression including spaces
    checkExpression();
    
    return 0;
}
