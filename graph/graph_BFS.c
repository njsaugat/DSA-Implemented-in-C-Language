#include<stdlib.h>
#include<stdio.h>
#include "E:\c progamming\DSA\graph\queue_graph.h"
#define n 6
int graph[n][n]={
    {0,0,0,0,0,0},
    {0,0,1,1,0,0},
    {0,1,0,1,1,1},
    {0,1,1,0,1,1},
    {0,0,1,1,0,1},
    {0,0,1,1,1,0}
};
int visited[n]={0};

void BFS(int u){
    printf("%d  ",u);
    enqueue(u);
    visited[u]=1;
    while(!isEmpty()){
        u=dequeue();
        for(int v=1;v<=n;v++){
            if(graph[u][v]==1 && visited[v]==0){
                printf("%d  ", v);
                enqueue(v);
                visited[v]=1;
            }
        }
    }
}

void main(){
    BFS(5);
}