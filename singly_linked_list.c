#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginnning(struct Node **head,int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        newNode->next = *head;
        *head = newNode;
    }
    printf("Elmement %d Inserted\n",data);
}

void insertAtEnd(struct Node **head, int data){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    if(*head == NULL){
    *head = newNode;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Elmement %d Inserted\n",data);
}

void insertAfter(struct Node **head,int data,int x){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while(temp->next!=NULL){
        if(temp->data == x){
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
    printf("Element %d inserted after a given %d",data,x);
}

void insertBefore(struct Node **head,int data,int x){
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    struct Node* temp2 = NULL;
    while(temp->next!=NULL){
        if(temp->data == x){
            temp2 ->next = newNode;
            newNode->next = temp;
        }
        temp2 = temp;
        temp = temp->next;
    }
    printf("Element %d inserted after a given %d",data,x);
}

void deleteFromBeginning(struct Node **head){
    if(*head == NULL){
        printf("List is Empty!!");
    }
    else{
    struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Elmement Deleted\n");
}

void deleteFromEnd(struct Node **head){
    if(*head == NULL){
        printf("List is Empty!!");
    }
    else{
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    }
    printf("Elmement Deleted\n");
}


void traverse(struct Node **head){
    struct Node *temp = *head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = NULL;
    int ch,x,y;
    while(1){
    printf("\n1.InsertatBeg\n2.InsertatEnd\n3.DeleteBefore\n4.display\n5.Exit\n6.insertAfter\n7.insertBefore\n8.DeleteEnd\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1 : printf("Enter elemnt to be inserted:");
                 scanf("%d",&x);
                 insertAtBeginnning(&head,x);
                 break;
        case 2: printf("Enter elemnt to be inserted:");
                scanf("%d",&x);
                insertAtEnd(&head,x);
                break;
        case 3: deleteFromBeginning(&head); break;
        case 4 : traverse(&head); break;
        case 5: exit(0);
        case 6 :
                printf("Enter elemnt to be inserted:");
                scanf("%d",&x);
                printf("Enter the position:");
                scanf("%d",&y);
                insertAfter(&head,x,y);
                break;
        case 7:
                printf("Enter elemnt to be inserted:");
                scanf("%d",&x);
                printf("Enter the position:");
                scanf("%d",&y);
                insertBefore(&head,x,y);
                break;
        case 8: deleteFromEnd(&head);break;
        default: printf("Invalid choice");
    }
    }
    return 0;
}