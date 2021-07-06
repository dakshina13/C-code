#include <stdio.h>
int sum(int a[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}
int main()
{
    int periodN, i, nonPeriodN, total;
    printf("Enter the total time share of the CPU\n");
    scanf("%d", &total);
    printf("Enter the number of processes that periodically required the cpu\n");
    scanf("%d", &periodN);
    int sharedTimePeriod[periodN];
    for (i = 0; i < periodN; i++)
    {
        printf("Enter the time for process %d\n",i+1);
        int temp;
        scanf("%d", &temp);
        if ((sum(sharedTimePeriod, i)+temp) <= total)
            sharedTimePeriod[i] = temp;
        else
        {
            printf("Total shares exceed the total CPU time\n");
            periodN=i;
            break;
        }
    }
    printf("Enter the non periodic proccess time that want the cpu\n");
    scanf("%d", &nonPeriodN);
    printf("Total is %d\n",sum(sharedTimePeriod,periodN));
    int time = total - (sum(sharedTimePeriod, periodN) + nonPeriodN);
    if (time >= 0)
        printf("The process with time %d can be included\n", nonPeriodN);
    else
        printf("The process with time %d can not be included\n", nonPeriodN);
}