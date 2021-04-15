#include<stdio.h>
int gcd(int a,int b){
    if(a==0)
        return b;
    else if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    int a,b,g;
    printf("Enter two Numbers\n");
    scanf("%d %d",&a,&b);
    g=gcd(a,b);
    printf("GCD of the two numbers %d and %d is %d",a,b,g);
    return 0;
}