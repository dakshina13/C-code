#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int i, j, count, min, temp;
   float start, end;

   printf("How many numbers u are going to enter?: \n");
   scanf("%d", &count);
   int number[count];

   //printf("Enter the elements of the array\n");
   //for(i=0;i<count;i++){
   //     scanf("%d",&number[i]);
   //}

   for (i = 0; i < count; i++)
      number[i] = rand();
   printf("Unsorted array\n");
   for (i = 0; i < count; i++)
   {
      printf("%d\t", number[i]);
   }
   printf("\n");
   start = clock();
   for (i = 0; i < count - 1; i++)
   {
      min = i;
      for (j = i + 1; j < count; j++)
      {
         if (number[min] > number[j])
         {
            min = j;
         }
      }
      temp = number[min];
      number[min] = number[i];
      number[i] = temp;
   }
   end = clock();
   printf("Sorted array\n");
   for (i = 0; i < count; i++)
   {
      printf("%d\t", number[i]);
   }
   printf("\n");
   printf("\n Time taken to sort %d numbers is %f Secs", count, (((double)(end - start)) / CLOCKS_PER_SEC));
   return 0;
}