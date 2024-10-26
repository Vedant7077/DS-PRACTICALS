#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int rear =-1,front=-1;
int i;

int isFull(){
    if((front==0 && rear == MAX-1)||(rear==front-1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int el){
    if(isFull())
    {
        printf("Queue is full!\n");
    }
    else
    {
        if(front == -1)
            front = 0;
        rear = (rear + 1)% MAX;
        queue[rear] = el;
        printf("Element %d inserted in queue \n", el);
    }
}

int dequeue(){
    if(isEmpty())
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        int x  = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
        front = (front + 1)% MAX;
        printf("Element %d dequed!!\n", x);
        }
    return x;
    }
}

void display(){
    if(isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are :");
    if(rear >= front)
    {
        for(int i = front; i<= rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
    else{
        for(int i = front; i < MAX;i++)
        {
            printf("%d ",queue[i]);
        }
    for(int i =0 ; i<= rear;i++)
    {
        printf("%d ",queue[i]);
    }
    }
    printf("\n");
}

int main(){
    int ch , x;

    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element to be inserted :");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: x = dequeue();
                    if(x!=-1)
                    printf("Elment Dequed %d!!",x);
                    break;
            case 3: display(); break;
            case 4: exit(0);
            default : printf("Invalid choice!");
        }
    }
}