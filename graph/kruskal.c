#include <stdio.h>
#include <stdio.h>
#define n 6
#define edge 8
int edges[3][edge] = {
    {1, 1, 2, 2, 2, 3, 3, 4},
    {2, 3, 3, 4, 5, 4, 5, 5},
    {5, 1, 8, 2, 7, 6, 9, 3}
};


int set[n]={-1,-1,-1,-1,-1,-1};

int visited[edge]={0};

int parent[2][n-1];
int parent1[3][n-1];

void unions(int s, int u){
    if(set[s]<set[u]){
        set[s]=set[s]+set[u];
        set[u]=s;
    }else{
        set[u]=set[u]+set[s];
        set[s]=u;
    }
}

int find_parent(int x){
    while(set[x]>0){
        x=set[x];
    }return x;
}

int find_min(){
    int min=__INT_MAX__,min_index;
    for(int v=1;v<=edge;v++){
        if(visited[v]==0 && edges[2][v]>min){
            min=edges[2][v];
            min_index=v;
        }
    }return min_index;

}



void kruskal(){
    int i=1,u,v,min,min_index;
    while(i<n-1){
        int min=__INT_MAX__;

        for(int count=0;count<edge;count++){            
            if(visited[count]==0 && edges[2][count]<min){
                min=edges[2][count];
                min_index=count;

            }
        }
        u =edges[0][min_index];
        v=edges[1][min_index];
        visited[min_index]=1;

        if(find_parent(u)!=find_parent(v)){
            unions(u,v);
            parent[0][i]=u;// 1st edge, 2nd edge yesari add garne
            parent[1][i]=v;
        }
        i++;
    }
}


void kruskal_extended(){
    int i=1,u,v,min,min_index;
    while(i<n-1){
        int min=__INT_MAX__;

        for(int count=0;count<edge;count++){            
            if(visited[count]==0 && edges[2][count]<min){
                min=edges[2][count];
                min_index=count;

            }
        }
        min=edges[2][min_index];
        u =edges[0][min_index];
        v=edges[1][min_index];
        visited[min_index]=1;

        if(find_parent(u)!=find_parent(v)){
            unions(u,v);
            parent1[0][i]=u;// 1st edge, 2nd edge yesari add garne
            parent1[1][i]=v;
            parent1[2][i]=min;
        }
        i++;
    }
}


void parent_display(){
    for(int i=1;i<n-1;i++){
        printf("%d  --- %d  ", parent[0][i],parent[1][i]);
        printf("\n");
    }
}
void parent1_display(){
    for(int i=1;i<n-1;i++){
        printf("%d  --- %d          %d", parent1[0][i],parent1[1][i],parent1[2][i]);
        printf("\n");
    }
}

void main(){
    kruskal_extended();
    parent1_display();
}

