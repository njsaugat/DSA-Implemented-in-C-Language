#include <stdio.h>
#include <stdlib.h>
#define n 6

int graph[n][n] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 5, 1, 0, 0},
    {0, 5, 0, 8, 2, 7},
    {0, 1, 8, 0, 6, 9},
    {0, 0, 2, 6, 0, 3},
    {0, 0, 7, 9, 3, 0}};
int dist[n] = {__INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__, __INT_MAX__};
int visited[n] = {0};

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

void dijkistra(int start)
{
    dist[start] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = find_min();
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            if (graph[u][v] != 0)
            {
                if (dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
}

void display(int start)
{
    for (int i = 1; i < n; i++)
    {
        printf("shortest distance from %d to %d is %d   ", start, i, dist[i]);
        printf("\n");
    }
}

void main()
{
    dijkistra(5);
    display(5);
}