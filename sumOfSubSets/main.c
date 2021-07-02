#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE(a) (sizeof(a)) / (sizeof(a[0]))

static int total_nodes;
// prints subset found
void printSubset(int A[], int size)
{
    int i;
    printf("\nPrinting subset\n");
    for (i = 0; i < size; i++)
    {
        printf("%*d", 5, A[i]);
    }

    printf("\n");
}

// inputs
// s            - set vector
// t            - tuplet vector
// s_size       - set size
// t_size       - tuplet size so far
// sum          - sum so far
// ite          - nodes count
// target_sum   - sum to be found
void subset_sum(int s[], int t[],
                int s_size, int t_size,
                int sum, int ite,
                int const target_sum)
{
    int i;
    total_nodes++;
    if (target_sum == sum)
    {
        // We found subset
        printSubset(t, t_size);
        // Exclude previously added item and consider next candidate
        subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
    }
    else
    {
        // generate nodes along the breadth
        for (i = ite; i < s_size; i++)
        {
            t[t_size] = s[i];
            // consider next level node (along depth)
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
        }
    }
}

// Wrapper to print subsets that sum to target_sum
// input is weights vector and target_sum
void generateSubsets(int s[], int size, int target_sum)
{
    int *tuplet_vector = (int *)malloc(size * sizeof(int));

    subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);

    free(tuplet_vector);
}

int main()
{
    int size, i, sum;
    printf("enter the size of the set\n");
    scanf("%d", &size);
    int weights[size];
    printf("enter the elements in set\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &weights[i]);
    }
    printf("enter the sum \n");
    scanf("%d", &sum);

    generateSubsets(weights, size, sum);
    printf("\nNodes generated %d  \n", total_nodes);
    return 0;
}