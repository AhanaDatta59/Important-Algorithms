

#include<stdio.h>
#include<stdlib.h>
#define V 4
#define INF 99999

void floydWarshal(int graph[][V]){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(graph[i][k]+graph[k][j]<graph[i][j])
                graph[i][j]=graph[i][k]+graph[k][j];
            }
        }
    }

    printf(
		"The following matrix shows the shortest distances"
		" between every pair of vertices \n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j]==INF)
            printf("%7s","INF");
            else
            printf("%7d",graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };
    floydWarshal(graph);
    return 0;
}