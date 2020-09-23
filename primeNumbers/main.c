#include<stdio.h>
int inputN(int a){
    int n;
    printf("Enter the %d  number\n",a);
    scanf("%d",&n);
    return n;
}
void invalidInput(){
    printf("Invalid input of numbers\n");
}
void printPrime(int a,int b){
    printf("The prime numbers between %d and %d are \n",a,b);
    int i=a,j=2;
    for(i;i<b;i++){
        for(j=2;j<=i/2;j++){
            if(i%j==0)
                break;
            if(j==i/2)
                printf("The number %d is prime\n",i);
        }
        if(i==2)
            printf("The number %d is prime\n",i);
        if(i==3)
            printf("The number %d is prime\n",i);
    }
}
int main(){
    int a,b;
    a=inputN(1);
    b=inputN(2);
    if(a>=b)
        invalidInput();
    else
        printPrime(a,b);
    return 0;   
}