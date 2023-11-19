/*

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 9

//for finding min distance
int minDistance(int dist[], bool included[])
{
	// Initialize min value
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (included[v] == false && dist[v] <= min){
			min = dist[v];
			min_index = v;
		}
	return min_index;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the shortest dist from src to i
	bool included[V]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is
	for (int i = 0; i < V; i++){
		dist[i] = INT_MAX;
		included[i] = false;
	}
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int i = 0; i < V - 1; i++) {
		int u = minDistance(dist, included);
		included[u] = true;
		for (int v = 0; v < V; v++)
			if (!included[v] && graph[u][v]!=0&& dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t %d\n", i, dist[i]);
}
int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph, 0);

	return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define V 9

int minimum(int dist[],bool included[]){
    int min=INT_MAX,ind=0;
    for(int i=0;i<V;i++){
        if(!included[i] && dist[i]<=min){
            min=dist[i];
            ind=i;
            }
    }
     return ind;
}
void dijkstras(int graph[V][V],int s){
    int dist[V];
    bool include[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        include[i]=false;
    }
    dist[s]=0;
    for(int i=0;i<V-1;i++){
        int u=minimum(dist,include);
        include[u]=true;
        for(int v=0;v<V;v++){
            if(!include[v]&&graph[u][v]!=0&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    printf("Vertex\t\tSource\n");
    for(int i=0;i<V;i++){
        printf("%d\t\t%d\n",i,dist[i]);
    }
}
int main(){
    int graph[V][V]={{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
					 { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
					 { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
					 { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
					 { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
					 { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
					 { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
					 { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
					 { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
    dijkstras(graph,0);
}