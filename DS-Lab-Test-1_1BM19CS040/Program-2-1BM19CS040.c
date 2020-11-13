#include<stdio.h>
int topMainStack=-1;
int topTable1=-1;
int topTable2=-1;
void push(int stack[],int identifier,int ele,int n);
int pop(int stack[]);
void display(int stack[],int identifier);
int main(){
    int n,i;
    printf("Enter the number plates in main stack\n");
    scanf("%d",&n);
    int mainStack[n],table1[n],table2[n];
    printf("Enter the plate number in main Stack\n");
    for(i=0;i<n;i++){
        int p;
        scanf("%d",&p);
        push(mainStack,0,p,n);
    }
    for(i=0;i<n;i++){
        int ele;
        ele=pop(mainStack);
        if(ele%2==0)
            push(table1,1,ele,n);
        else
            push(table2,2,ele,n);
    }
    display(table1,1);
    display(table2,2);
    return 0;
}
void push(int stack[],int identifier,int ele,int n){
    if(identifier==0){
        if(topMainStack==n){
            printf("Main Stack Overflow \n");
            return;
        }
        topMainStack++;
        stack[topMainStack]=ele;
    }else if(identifier==1){
        if(topTable1==n){
            printf("Stack Overflow \n");
            return;
        }
        topTable1++;
        stack[topTable1]=ele;
    }else{
        if(topTable2==n){
            printf("Stack Overflow\n");
            return;
        }
        topTable2++;
        stack[topTable2]=ele;
    }
}
int pop(int stack[]){
    if(topMainStack==-1){
        printf("Stack empty\n");
        return -1;
    }   
    int ele=stack[topMainStack];
    topMainStack--;
    return ele;
}
void display(int stack[],int identifier){
    int i;
    if(identifier==1){
        printf("Table 1\nTop\n");
        for(i=topTable1;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }else{
        printf("Table 2\nTop\n");
        for(i=topTable2;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    } 
}