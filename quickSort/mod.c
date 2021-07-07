#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void quickSort(int a[],int f,int l,int key){
    if(f<l){
        //Assigning the pivot to the first element of array
        int povit=f;
        int i=f;
        int j=l;
        while(i<j){
            //Finding a number greater than or equal to  pivot number
            while(a[i]<=a[povit]&&i<l)
                i++;
            //Finding a number less than pivot number
            while(a[j]>a[povit]&&j>=f)
                j--;
            //Swapping the i and j elements
            if(i<j){
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
        //Swapping Pivot Element
        int temp=a[j];
        a[j]=a[povit];
        a[povit]=temp;
        if(j+1==key){
            printf("The %dth minimum number is %d\n",key,a[j]);
            return;
        }
        //Breaking the array at the position the pivot was moved to
        quickSort(a,f,j-1,key);
        quickSort(a,j+1,l,key);
    }
}
int main(){
    int n,i,key;
    printf("Enter the number of element in array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the kth minimum element to be found\n");
    scanf("%d",&key);
    quickSort(a,0,n-1,key);
    return 0;
}