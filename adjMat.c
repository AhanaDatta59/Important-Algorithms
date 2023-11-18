#include<stdio.h>
#include<stdlib.h>
#define V 4

void printMat(int arr[][V]){
    for(int i=0;i<V;i++){
        printf("%d: ",i);
        for(int j=0;j<V;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void addEdge(int arr[][V],int i,int j){
    arr[i][j]=1;
    arr[j][i]=1;
}
int main(){
    int adjMat[V][V];
    
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            adjMat[i][j]=0;
        }
    }

    addEdge(adjMat,0,1);
    addEdge(adjMat,0,2);
    addEdge(adjMat,1,2);
    addEdge(adjMat,2,0);
    addEdge(adjMat,2,3);

    printMat(adjMat);
}