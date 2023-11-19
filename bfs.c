
#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

struct adj_list{
    struct node *head;
};

struct graph{
    int numVertices;
    struct adj_list* adj_lists;
    int *visited;
};

//create node function
struct node* createNode(int v){
    struct node* newNode=malloc(sizeof(struct node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}

//create graph
struct graph* createGraph(int n){
    struct graph* g=(struct graph*)malloc(sizeof(struct graph));
    g->numVertices=n;
    g->adj_lists = (struct adj_list*)malloc(n * sizeof(struct adj_list)); 
    g->visited=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
    g->adj_lists[i].head=NULL;
    g->visited[i]=0;
    }
    return g;
}

//adding and edge
void addEdge(struct graph* graph, int s,int d){
    //s->d
    struct node* newNode=createNode(d);
    newNode->next=graph->adj_lists[s].head;
    graph->adj_lists[s].head=newNode;

    //d->s
    newNode=createNode(s);
    newNode->next=graph->adj_lists[d].head;
    graph->adj_lists[d].head=newNode;

}

//bfs traversal
void bfs(struct graph* graph, int v){
    int queue[1000];
    int rear=-1;
    int front=-1;

    graph->visited[v]=1;
    queue[++rear]=v;

    while(front!=rear){
        int temp=queue[++front];
        printf("%d ",temp);

        struct node* pop=graph->adj_lists[temp].head;
        while(pop!=NULL){
            int t=pop->vertex;
            if(graph->visited[t]!=1){
                graph->visited[t]=1;
                queue[++rear]=t;
            }
            pop=pop->next;
        }
    }
}
int main(){
    struct graph* graph=createGraph(6);
addEdge(graph, 0, 1);  
addEdge(graph, 0, 2);  
addEdge(graph, 1, 3);  
addEdge(graph, 1, 4);  
addEdge(graph, 2, 4);  
addEdge(graph, 3, 4);  
addEdge(graph, 3, 5);  
addEdge(graph, 4,5); 
bfs(graph,0);
}
