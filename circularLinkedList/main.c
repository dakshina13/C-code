#include<stdio.h>
#include<stdlib.h>
typedef struct DQ{
    int data;
    struct DQ *next;
}Node;
int displayMenu();
void create();
Node *head=NULL;
void display();
void delete();
void insert();
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
            insert();
            break;
        case 999:
            break;
        default:
            printf("Enter valid choice!\n");
        }
    }while(c!=999);
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
void create(){
    Node *newNode,*temp=head;
    printf("Enter the value to be inserted\n");
    newNode=(Node*)malloc(sizeof(Node));
    scanf("%d",&newNode->data);
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
}
void display(){
    if(head==NULL){
        printf("List is empty!\n");
        return;
    }
    Node *temp=head;
    //Cause initially temp is equal to head
    printf("The items in the list are \n");
    do{
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
void delete(){
    int ele;
    Node *temp=head,*found=NULL;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    if(temp->data==ele){
        Node* first=head;
        if(head->next==head){
            head=NULL;
            free(head);
            return;
        }
        while(temp->next!=first){
            temp=temp->next;
        }
        head=first->next;
        temp->next=head;
        return;
    }
    do{
        if(temp->next->data==ele){
            found=temp->next;
            break;
        }
        temp=temp->next;
    }while(temp->next!=head);
    if(found==NULL){
        printf("Element not in list\n");
    }else{
        temp->next=found->next;
        free(found);
    }
}
void insert(){
    int p,count=0,i=0;
    Node *temp=head,*after,*before,*newNode;
    printf("Enter the position at which the element should be inserted\n");
    scanf("%d",&p);
    if(head==NULL)
        count=0;
    do{
        count++;
        temp=temp->next;
    }while(temp->next!=head);
    if(p>count){
        printf("Invalid position\n");
        return;
    }
    temp=head;
    newNode=(Node*)malloc(sizeof(Node));
    printf("Enter the element to be inserted:\n");
    scanf("%d",&newNode->data);
    if(p==0){
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next=head;
        head=newNode;
        temp->next=head;
        printf("Element %d is successfully inserted at position 0\n",newNode->data);
    }
    else if(p==count){
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next=head;
        temp->next=newNode;
        printf("Element %d is successfully inserted at position %d\n",newNode->data,p);
    }
    else{
        for(i=0;i<p;i++){
            if(i==p-1){
                before=temp;
                after=temp->next;
                break;
            }
            temp=temp->next;
        }
        newNode->next=after;
        before->next=newNode;
        printf("Element %d is successfully inserted at position %d\n",newNode->data,p);
    }
}