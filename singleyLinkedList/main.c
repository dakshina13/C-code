#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
void create();
void display();
void delete();
int displayMenu();
void insertAtPosition();
int main(){
    int c;
    do{
        c=displayMenu();
        
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
            insertAtPosition();
            break;
        case 999:
            break;
        default:
            printf("Enter valid choice\n");
        }
    }while(c!=999);
    return 0;
}
int displayMenu(){
    int c;
    printf("Please choose one of the following\n");
    printf("1.Add to list\n");
    printf("2.Display list\n");
    printf("3.Delete from list\n");
    printf("4.Insert at specific position\n");
    printf("999.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    return c;
}
void insertAtPosition(){
    int p,count=0,i=0,ele;
    struct Node *temp,*after,*before,*newNode;
    temp=head;
    printf("Enter the position at which the element should be inserted\n");
    scanf("%d",&p);
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(p>count-1){
        if(count==0)
            printf("List is empty");
        else
            printf("Invalid position\n");
        return;
    }
    printf("Enter the element to be inserted:\n");
    scanf("%d",&ele);
    temp=head;
    if(p==0){
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=ele;
        newNode->next=head;
        head=newNode;
        printf("Element %d is successfully inserted at position 0\n",ele);
    }else{
        while(i<count){
        if(i==p-1){
            before=temp;
            after=temp->next;
            break;
        }
            temp=temp->next;
            i++;
        }
        newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=ele;
        before->next=newNode;
        newNode->next=after;
        printf("Element %d is successfully inserted at position %d\n",ele,p);
    }
}
void create(){
    int ele;
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number to be added to list\n");
    scanf("%d",&ele);
    newNode->data=ele;
    newNode->next=NULL;
    if(head==NULL){
       head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void display(){
    struct Node *temp=head;
    if(head==NULL){
        printf("No element in the list\n");
        return;
    } 
    printf("Element in the list are :\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void delete(){
    if(head==NULL){
        printf("No elements in array\n");
        return;
    }
    struct Node *temp=head,*found=NULL;
    int ele;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    if(head->data==ele){
        printf("Element %d is deleted \n",ele);
        head=head->next;
        return;
    }
    while(temp!=NULL){
        if(temp->next->data==ele){
            found=temp->next;
            break;
        }
        temp=temp->next;
    }
    if(found==NULL){
        printf("Element is not found\n");
        return;
    }
    if(found->next==NULL)
        temp->next=NULL;
    else{
        temp->next=found->next;
    }  
    printf("Element %d is deleted \n",ele);
}