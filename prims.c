
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#define INF 99999
int minimum(int arr[],bool mst[6]){
    int min=INT_MAX,ind;
    for(int i=0;i<6;i++){
        if(arr[i]<min&&mst[i]==false){
            min=arr[i];
            ind=i;
        }
    }
    return ind;
}
void prims(int graph[6][6],int s){
    int dist[6], parent[6];
    bool mst[6];
    for(int i=0;i<6;i++){
        dist[i]=INF,parent[i]=-1,mst[i]=false;
    }
    dist[s]=0;
    for(int i=0;i<6-1;i++){
        int ind=minimum(dist,mst);
        mst[ind]=true;

        for(int j=0;j<6;j++){
            if(graph[ind][j]!=INF&&mst[j]==false&&graph[ind][j]<dist[j]){
                parent[j]=ind;
                dist[j]=graph[ind][j];
                
            }
        }
    }
    int mincost=0;
    for(int i=0;i<6;i++){
        if(parent[i]!=-1){
        printf("%d->%d %d\n",parent[i],i,graph[i][parent[i]]);
        mincost+=graph[i][parent[i]];
        }
    }
    printf("\n%d",mincost);
}
int main(){
     int graph[6][6]={{0,6,5,INF,7,INF},
                    {6,0,4,2,INF,5},
                    {5,4,0,5,8,INF},
                    {INF,2,5,0,INF,2},
                    {7,INF,8,INF,0,INF},
                    {INF,5,INF,2,INF,0}};

     prims(graph,3);
}