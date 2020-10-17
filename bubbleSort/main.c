#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter the number of numbers\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the numbers\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            printf("At element %d\n",j+1);
            if(a[j]>a[j+1]){
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
        printf("%d",a[i]);
    return 0;
}