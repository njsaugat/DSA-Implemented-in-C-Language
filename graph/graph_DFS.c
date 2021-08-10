#include<stdio.h>
#include<stdlib.h>
#define n 6
void set_edge(){

}
int graph[n][n]={
    {0,0,0,0,0,0},
    {0,0,1,1,0,0},
    {0,1,0,1,1,1},
    {0,1,1,0,1,1},
    {0,0,1,1,0,1},
    {0,0,1,1,1,0}
};
int visited[n];
void DFS(int u){
    if(u){
        printf("%d  ",u);
        visited[u]=1;
        for(int v=1;v<=n;v++){
            if(graph[u][v]==1 && visited[v]==0){
                DFS(v);
            } 
        }
    }
}


void main(){
    DFS(3);
}