#include<stdio.h>
#include<stdlib.h>
int findParent(int parent[],int val){
    if(parent[val]==val)
    return val;
    return parent[val]=findParent(parent,parent[val]);
}
void unionSet(int u, int v, int parent[], int rank[]) 
{ 
    // Finding the parents 
    u = findParent(parent, u); 
    v = findParent(parent, v); 
  
    if (rank[u] < rank[v]) { 
        parent[u] = v; 
    } 
    else if (rank[u] > rank[v]) { 
        parent[v] = u; 
    } 
    else { 
        parent[v] = u; 
  
        // Since the rank increases if 
        // the ranks of two sets are same 
        rank[u]++; 
    } 
} 
int comparator(const void *p1, const void *p2){
    const int(*x)[3]=p1;
    const int(*y)[3]=p2;
    return (*x)[2]-(*y)[2];
}
void krushkals(int n,int graph[n][3]){
    //sort graph
    qsort(graph,n,sizeof(graph[0]),comparator);

    int parent[n];
    int rank[n];

    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }

    int minCost=0;
    printf("\nThe edges constructed: \n");
    for(int i=0;i<n;i++){
        int v1=findParent(parent, graph[i][0]);
        int v2=findParent(parent,graph[i][1]);
        int wt=graph[i][2];

        if(v1!=v2){
            //include
            unionSet(v1,v2,parent,rank);
            minCost+=wt;
            printf("\n%d -- %d == %d\n",graph[i][0],graph[0][i],wt);
        }
    }
    printf("%d",minCost);
}
int main(){
    int graph[5][3] = { { 0, 1, 10 }, 
                       { 0, 2, 6 }, 
                       { 0, 3, 5 }, 
                       { 1, 3, 15 }, 
                       { 2, 3, 4 } }; 
    krushkals(5,graph);
    return 0;
}