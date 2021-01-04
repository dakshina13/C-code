#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *previous;
    struct Node *next;
};
int displayMenu();
struct Node *head;
void create();
void display();
void removeDuplicate();
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
            removeDuplicate();
        case 999:
            break;
        default:
            printf("Enter vaild input");
        }
    }while(c!=999);
}
int displayMenu(){
    int c;
    printf("Please choose one of the following\n");
    printf("1.Add to list\n");
    printf("2.Display list\n");
    printf("3.Remove Duplicate\n");
    printf("999.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    return c;
}
void create(){
    int ele;
    struct Node *newNode,*temp;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element\n");
    scanf("%d",&ele);
    newNode->data=ele;
    newNode->next=NULL;
    if(head==NULL){
        newNode->previous=NULL;
        head=newNode;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->previous=temp;
    temp->next=newNode;
}
void display(){
    if(head==NULL){
        printf("No elements in array\n");
        return;
    }
    struct Node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void removeDuplicate(){
    if(head==NULL){
        printf("The List is empty\n");
        return;
    }
    struct Node *temp;
    temp=head;
    while (temp!=NULL){
        struct Node *innerTemp;
        innerTemp=temp->next;
        while(innerTemp!=NULL){
            if(innerTemp->data==temp->data){
                struct Node *before =innerTemp->previous;
                struct Node *after= innerTemp->next;
                before->next=after;
                if(after!=NULL)
                    after->previous=before;
                innerTemp=before;
            }
            innerTemp=innerTemp->next;
        }
        temp=temp->next;
    }
}