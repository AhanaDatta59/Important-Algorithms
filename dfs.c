
#include<stdio.h>
#include<stdlib.h>

int vis[100];
struct Graph{
  int V;
  int **adj;
};

struct Graph* adjMatrix(int v){
    struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
    g->V=v;

    g->adj=(int **)malloc((g->V)*sizeof(int *));
    for(int i=0;i<g->V;i++){
        g->adj[i]=(int *)malloc((g->V)*sizeof(int));
    }

    for(int i=0;i<g->V;i++){
        for(int j=0;j<g->V;j++){
            g->adj[i][j]=0;
        }
    }
    g->adj[0][1] = g->adj[1][0] = 1;
    g->adj[0][2] = g->adj[2][0] = 1;
    g->adj[1][3] = g->adj[3][1] = 1;
    g->adj[1][4] = g->adj[4][1] = 1;
    g->adj[1][5] = g->adj[5][1] = 1;
    g->adj[1][6] = g->adj[6][1] = 1;
    g->adj[6][2] = g->adj[2][6] = 1;

    return g;
}
void DFS(struct Graph* g, int i){
    vis[i]=1;
    printf("%d ",i);
    for(int j=0;j<g->V;j++){
        if(g->adj[i][j]==1&&vis[j]==0)
        DFS(g,j);
    }
}
void DFStraversal(struct Graph* graph){
    for(int i=0;i<100;i++){
        vis[i]=0;
    }
    for(int i=0;i<graph->V;i++){
        if(!vis[i]){
            DFS(graph,i);
        }
    }
}

int main(){
    struct Graph* g=adjMatrix(7);
    DFStraversal(g);
}