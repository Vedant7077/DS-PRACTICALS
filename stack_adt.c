#include <stdio.h>
int stack[100];
int top = -1;
int n;

void push()
{
    if (top == n - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        int value;
        printf("Enter Element to push : ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("\nElement Inserted.\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("Element Popped..");
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("Stack :\t");
        for (int i = 0; i <= top; i++)
        {
            printf("%d\t", stack[i]);
        }
    }
}

int main()
{
    printf("Enter size of stack : ");
    scanf("%d", &n);
    while (1)
    {
        int ch;
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}