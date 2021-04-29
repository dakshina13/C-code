#include<stdio.h>
#include<stdlib.h>
#include <time.h>


int main(){
   int i, j, count, temp;
   float start,end;

   printf("How many numbers u are going to enter?: ");
   scanf("%d",&count);
   int number[count];

   for(i=0;i<count;i++)
        number[i]=rand();
    start=clock();
   for(i=0;i<count;i++){
      for(j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }
    end=clock();
    printf("\n Time taken to sort %d numbers is %f Secs",count, (((double)(end-start))/CLOCKS_PER_SEC));
   return 0;
}