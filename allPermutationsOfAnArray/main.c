#include<stdio.h>
int a[10],d[10],n;
int hasMobile(){
    int i,mobile=-1;
    for(i=0;i<n;i++){
        //Taking the direction of elemnt in the array 
        //and checking if it is left or right
        //If left then checking if it is not the first element
        if(d[a[i]-1]==0&&i!=0){
            //Checking if the element being pointed to ie left
            //is smaller than the current element
            //And if the current element is larger than the previous mobile
            if(a[i]>a[i-1]&&a[i]>mobile){
                mobile=a[i];
            }
        }
        //If it is right then checking if it is the last element
        else if(d[a[i]-1]==1&&i!=n-1){
            //Checking if the element being pointed to ie right
            //is smaller than the current element
            //And if the current element is larger than the previous mobile
            if(a[i]>a[i+1]&&a[i]>mobile)
                mobile=a[i];
        }
    }
    //Returning the mobile number it self
    return mobile;
}
int getMobileIndex(int mobile){

    //Just to find the index if the mobile number
    int i;
    for(i=0;i<n;i++){
        if(a[i]==mobile)
            return i;
    }
    return -1;
}
void printPermutation(){
    int mobile=hasMobile();
    int mobileIndex=getMobileIndex(mobile);
    int i,count=1;
    printf("The all possible permutations are\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    while(mobileIndex!=-1){
        //Checking the direction of the mobile
        //And swapping with the corresponding element
        int dir=d[mobile-1];
        //Swapping with left
        if(dir==0){
            int temp=a[mobileIndex];
            a[mobileIndex]=a[mobileIndex-1];
            a[mobileIndex-1]=temp;
        }
        //Swapping with right
        else{
            int temp=a[mobileIndex];
            a[mobileIndex]=a[mobileIndex+1];
            a[mobileIndex+1]=temp;
        }

        //Changing the direction of all the numbers 
        //greater than the mobile number
        for(i=0;i<n;i++){
            if(a[i]>mobile){
                if(d[a[i]-1]==0){
                    d[a[i]-1]=1;
                }else if(d[a[i]-1]==1){
                    d[a[i]-1]=0;
                }
            }
        }
        //Printing the list as output
        for(i=0;i<n;i++){
            printf("%d\t",a[i]);
        }
        printf("\n");
        mobile=hasMobile();
        mobileIndex=getMobileIndex(mobile);
        count++;
    }
    printf("Count= %d\n",count);
}
int main(){
    int i;
    printf("Enter the length of the array\n");
    scanf("%d",&n);
    //Initializing both the main array and direction array
    for(i=1;i<=n;i++){
        a[i-1]=i;
        d[i-1]=0;
    }
    printPermutation();
    return 0;
}