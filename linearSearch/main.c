#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(){
    int n,ele,i,found=-1;
    double timeStart,timeEnd;
    timeStart=clock();
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int a[n];
    //printf("Enter the elements of the array\n");
    //for(i=0;i<n;i++)
    //    scanf("%d",&a[i]);
    srand(time(0));
    for(i=0;i<n;i++)
        a[i]=rand();
    printf("Enter the number to be searched\n");
    scanf("%d",&ele);
    for(i=0;i<n;i++)
        if(a[i]==ele){
            found=i;
            break;
        }
    if(found==-1)
        printf("Element not found\n");
    else
        printf("Element %d found in position %d\n",ele,found);
    timeEnd=clock();
    printf("%lf\n",timeStart);
    printf("%lf\n",timeEnd);
    printf("Time taken %lf\n",(timeEnd-timeStart)/CLOCKS_PER_SEC);

}