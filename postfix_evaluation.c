#include <stdio.h>
#define MAX 50
int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow!!");
    }
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow!!");
        return -1;
    }
    int el = stack[top--];
    return el;
}

int is_digitchar(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

int main()
{
    char exp[20];
    char *e;
    int n1, n2, n3, num;

    printf("Enter expression:");
    scanf("%s", &exp);
    e = exp;
    while (*e != '\0')
    {
        if (is_digitchar(*e))
        {
            num = *e - '0';
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();

            switch (*e)
            {
            case '+':
                n3 = n2 + n1;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            case '*':
                n3 = n2 * n1;
                break;
            default:
                printf("invalid case");
            }
            push(n3);
        }
        e++;
    }
    printf("The result of expression : %d\n", pop());
    return 0;
}
