//adjacency list representation of graph
#include<stdio.h>
#include<stdlib.h>
struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int numVertices;
    struct node** adjLists;
};

//create node
struct node* createNode(int v)
{
    struct node* newNode=malloc(sizeof(struct node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
};

//create graph
struct Graph* createGraph(int Vertices){
    struct Graph* graph=malloc(sizeof(struct Graph));
    graph->numVertices=Vertices;
    graph->adjLists=malloc(Vertices*sizeof(struct node*));

    for(int i=0;i<Vertices;i++)
    graph->adjLists[i]=NULL;

    return graph;
}

//adding an edge
void addEdge(struct Graph* graph, int s,int d){
    //s->d
    struct node* newNode=createNode(d);
    newNode->next=graph->adjLists[s];
    graph->adjLists[s]=newNode;

    //d->s
    newNode=createNode(s);
    newNode->next=graph->adjLists[d];
    graph->adjLists[d]=newNode;
}

//print the graph
void printGraph(struct Graph* graph){
    for(int i=0;i<graph->numVertices;i++){
        struct node* temp=graph->adjLists[i];
        printf("\nVertex: %d \n",i);
        while(temp){
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct Graph* graph=createGraph(4);
    addEdge(graph,0,1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    printGraph(graph);
}
