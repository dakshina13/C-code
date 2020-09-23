#include<stdio.h>
float sumaver(int a,int b){
    printf("The sum of the two numbers is %d \n",a+b);
    return (float)(a+b)/2;
}
void printeven(int a,int b){
    printf("The even numbers between %d and %d is \n",b,a);
    int i=b+1;
    for(i;i<a;i++){
        if(i%2==0){
            printf("%d\t",i);
        }
    }
    printf("\n");
}
int main()
{
    int a,b,c;
    float avg;
    printf("Enter 3 numbers \n");
    scanf("%d,%d,%d",&a,&b,&c);
    if(a>b && a>c){
        if(b>c){
            avg=sumaver(a,b);
            printeven(a,b);
        }else{
            avg=sumaver(a,c);
            printeven(a,c);
        }
    }else if(b>c){
        if(a>c){
            avg=sumaver(b,a);
            printeven(b,a);
        }else{
            avg=sumaver(b,c);
            printeven(b,c);
        }
    }else{
        if(a>b){
            avg=sumaver(c,a);
            printeven(c,a);
        }else{
            avg=sumaver(c,b);
            printeven(c,b);
        }
    }
    printf("The average of the two greatest numbers is %f",avg);
    return 0;
}