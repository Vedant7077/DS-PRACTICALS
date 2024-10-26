#include<stdio.h>
int queue[100];
int front = -1,rear = -1;
int n;

void insertq(){
    if(rear == n-1)
    {
        printf("Queue is full");
    }
    else
    {
        int x;
        rear++;
        printf("Enter the element u want to insert:");
        scanf("%d",&x);
        queue[rear] = x;
        printf("Element inserted!!\n");
        if(front == -1)
            front = 0;
    }
}

void deleteq(){
    if(front == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        int x = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        printf("Element deleted :%d\n",x);
    }
}

void display(){
    for(int i = front;i<=rear;i++){
        printf("%d\t",queue[i]);
    }
}
int main(){
    int ch;
    printf("Enter size of queue:");
    scanf("%d",&n);
    while(1){
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:insertq(); break;
        case 2:deleteq(); break;
        case 3:display(); break;
        case 4:return 0;
        }
    }
}