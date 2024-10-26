#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top = NULL;

void push(int el){
    struct stack *new = malloc(sizeof(struct stack));
    new->data = el;
    new ->next = top;
    top = new;
    printf("New node Inserted!!");
}

void pop(){
    struct stack *temp = top;
    if(top == NULL){
        printf("Stack underflow");
    }
    top = top->next;
    printf("Node deleted!!");
    free(temp);
}

void display(){
    if(top == NULL){
        printf("Satck is empty!!");
    }
    struct stack *ptr = top;
    printf("\nElements in satck:\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    int ch,el;
    printf("Stack operations :-");
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Elment u want to insert:");
                    scanf("%d",&el);
                    push(el);
                    break;
            case 2:pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid case");
        }
    }
    return 0;
}