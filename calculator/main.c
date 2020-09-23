#include <stdio.h>

void add(){
    int a,b;
    printf("Please enter the numbers to add\n");
    scanf("%d,%d",&a,&b);
    printf("The sum of the numbers is %d\n",a+b);
}
void subtract(){
    int a,b;
    printf("Please enter the numbers to subtract\n");
    scanf("%d,%d",&a,&b);
    printf("The diff of the numbers is %d\n",a-b);
}
void multiply(){
    int a,b;
    printf("Please enter the numbers to multiply\n");
    scanf("%d,%d",&a,&b);
    printf("The product of the numbers is %d\n",a*b);
}
void divide(){
    int a,b;
    printf("Please enter the numbers to divide\n");
    scanf("%d,%d",&a,&b);
    printf("The qoutient of the numbers is %f\n",(float)a/b);
}
void less(){
    int a,b;
    printf("Please enter the numbers to compare less than\n");
    scanf("%d,%d",&a,&b);
    if(a<b){
        printf("The %d is less than %d\n",a,b);
    }else{
        printf("The %d is not less than %d\n",a,b);
    }
}
void great(){
    int a,b;
    printf("Please enter the numbers to compare greater than\n");
    scanf("%d,%d",&a,&b);
    if(a>b){
        printf("The %d is greater than %d\n",a,b);
    }else{
        printf("The %d is not greater than %d\n",a,b);
    }
}
void equal(){
    int a,b;
    printf("Please enter the numbers to compare equal to\n");
    scanf("%d,%d",&a,&b);
    if(a==b){
        printf("The %d is equal to %d\n",a,b);
    }else{
        printf("The %d is not equal to %d\n",a,b);
    }
}
void notequal(){
    int a,b;
    printf("Please enter the numbers to compare not equal\n");
    scanf("%d,%d",&a,&b);
    if(a!=b){
        printf("The %d is not equal to %d\n",a,b);
    }else{
        printf("The %d is equal to %d\n",a,b);
    }
}
void modulus(){
    int a,b;
    printf("Please enter the numbers to get the modulus\n");
    scanf("%d,%d",&a,&b);
    printf("The modulus od the numbers %d  and %d is %d \n",a,b,a%b);
}
void increment(){
    int a;
    printf("Please enter the number to be incremented\n");
    scanf("%d,%d",&a);
    printf("The increment number is %d \n",++a);
}
int main(){
    int a=0;
    do{
    printf("Please choose one of the following\n");
    printf("1.Addition\n");
    printf("2.Subtract\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("5.Less Than\n");
    printf("6.Greater Than\n");
    printf("7.Equal to\n");
    printf("8.Not Equal\n");
    printf("9.Modulus\n");
    printf("10.Increment\n");
    printf("11.Exit\n");
    printf(" Please enter the option \n");
    scanf("%d",&a);
    switch(a){
        case 1:add();break;
        case 2:subtract(); break;
        case 3:multiply();break;
        case 4:divide();break;
        case 5:less();break;
        case 6:great();break;
        case 7:equal();break;
        case 8:notequal();break;
        case 9:modulus();break;
        case 10:increment();break;
        case 11:break;
        default:printf("Enter valid input");
    }
    }while(a!=11);
    return 0;
}