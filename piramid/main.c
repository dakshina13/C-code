#include<stdio.h>
int main(){
    int n,a=1,i=1,j=1;
    printf("Enter the number of rows:\n");
    scanf("%d",&n);
    for(i;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%d\t",a);
            a++;
        }
        printf("\n");
    }
    return 0;
}