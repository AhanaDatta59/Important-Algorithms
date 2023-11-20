
#include<stdio.h>
#include<stdlib.h>

struct Edge{
    int s,d,w;
};

struct Graph{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V,int E){
    struct Graph* g=(struct Graph*)malloc(sizeof(struct Graph));
    g->V=V;
    g->E=E;
    g->edge=(struct Edge*)malloc(E*sizeof(struct Graph));
    return g;
}

void BellmanFord(struct Graph* graph,int src){
    int V=graph->V;
    int E=graph->E;
    int dist[V];
    for(int i=0;i<V;i++)
    dist[i]=INT_MAX;
    dist[src]=0;

    for(int i=1;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=graph->edge[j].s;
            int v=graph->edge[j].d;
            int wt=graph->edge[j].w;
            if(dist[u]!=INT_MAX&&dist[u]+wt<dist[v])
            dist[v]=dist[u]+wt;
        }
    }

    for(int i=0;i<E;i++){
        int u=graph->edge[i].s;
        int v=graph->edge[i].d;
        int wt=graph->edge[i].w;
        if(dist[u]!=INT_MAX&&dist[u]+wt<dist[v]){
            printf("\nNegative cycle\n");
            return;
        }
    }

    for(int i=0;i<V;i++){
        printf("%d ---------- %d\n",i,dist[i]);
    }
}

int main() {
    int V = 5;
    int E = 8;
    struct Graph* graph = createGraph(V, E);

	graph->edge[0].s = 0;
	graph->edge[0].d = 1; 
	graph->edge[0].w = -1;

	graph->edge[1].s = 0;
	graph->edge[1].d = 2;
	graph->edge[1].w = 4;

	graph->edge[2].s = 1;
	graph->edge[2].d = 2;
	graph->edge[2].w = 3;

	graph->edge[3].s = 1;
	graph->edge[3].d = 3;
	graph->edge[3].w = 2;

	graph->edge[4].s = 1;
	graph->edge[4].d = 4;
	graph->edge[4].w = 2;

	graph->edge[5].s = 3;
	graph->edge[5].d = 2;
	graph->edge[5].w = 5;

	graph->edge[6].s = 3;
	graph->edge[6].d = 1;
	graph->edge[6].w = 1;

	graph->edge[7].s = 4;
	graph->edge[7].d = 3;
	graph->edge[7].w = -3;

    BellmanFord(graph, 0);

    free(graph->edge);
    free(graph);

    return 0;
}