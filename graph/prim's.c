#include <stdlib.h>
#include <stdio.h>
#define n 6
int graph[n][n] = {{0, 0, 0, 0, 0, 0},
                   {0, 0, 2, 0, 6, 0},
                   {0, 2, 0, 3, 8, 5},
                   {0, 0, 3, 0, 0, 7},
                   {0, 6, 8, 0, 0, 9},
                   {0, 0, 5, 7, 9, 0}};
;
int dist[n] = {__INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__};
int visited[n] = {0};
int parent[n] = {0}; // we dont need 2D array here

int find_min()
{
    int min = __INT_MAX__, min_index;
    for (int v = 1; v <= n; v++)
    {
        if (dist[v] < min && visited[v] == 0)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void prim(int start)
{
    dist[start] = 0;
    parent[start] = -1;
    for (int i = 1; i < n; i++)
    {
        int u = find_min();
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] != 0)
            {
                if (graph[u][v] < dist[v])
                {
                    dist[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}

void display(int start)
{
    for (int i = 1; i < n; i++)
    {
        printf("parent of  %d is %d   ", i, parent[i]);
        printf("\n");
    }
}

int printMST()
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void main()
{
    prim(1);
    printMST();
}