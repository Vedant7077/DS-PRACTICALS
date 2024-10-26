#include<stdio.h>
#include<stdlib.h>
struct queue
{
    /* data */
    int data;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;

void enqueue(int el){
    struct queue *new  = malloc(sizeof(struct queue));
    new->data = el;
    new->next = NULL;

    if(front == NULL){
        front = rear = new;
    }
    rear->next = new;
    rear = new;
    
    printf("Element inserted!!");
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty");
    }
    struct queue *temp = front;
    front = front->next;
    printf("Deleted Element : %d",temp->data);
    free(temp);
}

void display(){
    struct queue *temp = front;
    printf("Queue Elements are: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int ch,el;
    printf("Queue operations:\n");
    while(1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Elment u want to insert:");
                    scanf("%d",&el);
                    enqueue(el);
                    break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid case");
        }
    }
    return 0;
}