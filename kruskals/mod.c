// Kruskal's algorithm in C

#include <stdio.h>

#define MAX 30
// To store data related to each node
typedef struct edge
{
    int u, v, w;
} edge;
// to store data related to all nodes in graph and selected edges
typedef struct edge_list
{
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo()
{
    int belongs[MAX], i, j, cno1, cno2, k;
    elist.n = 0;
    //considering  only the lower triangular matrix since it is symmeteric
    //creates a list of all edges and weights
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
        {
            if (Graph[i][j] != 0)
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }
    //Sorts the list of edges according to their weights
    sort();
    //Initializing each node to say that it parent is itself
    //once each edge is added to selected array belongs is updated to one of the nodes
    for (i = 0; i < n; i++)
        belongs[i] = i;
    //Span list contains the list of all selected edges
    spanlist.n = 0;

    for (i = 0; i < elist.n; i++)
    {
        // printf("\nPrinting belongs\n");
        // for (j = 0; j < n; j++)
        // {
        //     printf("%d\t", belongs[j]);
        // }
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);
        //Checking if the node selected is already connected
        if (cno1 != cno2)
        {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2);
        }
        else
        {
            printf("Edge from %d to %d forms a cycle nodes\n", elist.data[i].u, elist.data[i].v);
            printf("%d\t", elist.data[i].u);
            printf("%d\t", elist.data[i].v);
            for (j = 0; j < spanlist.n; j++)
            {
                if (spanlist.data[j].u == elist.data[i].u)
                {
                    for (k = 0; k < spanlist.n; k++)
                    {
                        if (spanlist.data[j].v == spanlist.data[k].v && spanlist.data[k].u == elist.data[i].u)
                        {
                            printf("%d\t", elist.data[k].v);
                        }
                    }
                }
            }
            printf("\n");
        }
    }
}

int find(int belongs[], int vertexno)
{
    return (belongs[vertexno]);
}
//Updating belongs that there was an edge between c1 and c2
void applyUnion(int belongs[], int c1, int c2)
{
    int i;

    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}

// Sorting algo
void sort()
{
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w)
            {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}

// Printing the result
void print()
{
    int i, cost = 0;

    for (i = 0; i < spanlist.n; i++)
    {
        printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }

    printf("\nSpanning tree cost: %d", cost);
}

int main()
{
    int i, j, total_cost;

    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &Graph[i][j]);
        }
    printf("The graph:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", Graph[i][j]);
        printf("\n");
    }

    kruskalAlgo();
    print();
}