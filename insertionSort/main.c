#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, count, temp;
    float start, end;

    printf("How many numbers u are going to enter?: ");
    scanf("%d", &count);
    int number[count];

    for (i = 0; i < count; i++)
        number[i] = rand();
    start = clock();
    for (i = 1; i < count; i++)
    {
        temp = number[i];
        j = i - 1;
        while ((temp < number[j]) && (j >= 0))
        {
            number[j + 1] = number[j];
            j = j - 1;
        }
        number[j + 1] = temp;
    }
    end=clock();
    printf("\n Time taken to sort %d numbers is %f Secs",count, (((double)(end-start))/CLOCKS_PER_SEC));
    return 0;
}