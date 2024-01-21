#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int vertex = queue[front];
    front++;

    if (front > rear) {
        front = rear = -1;
    }

    return vertex;
}

bool isEmpty() {
    return front == -1;
}

void breadthFirstSearch(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    bool visited[MAX_VERTICES] = {false};

    enqueue(startVertex);
    visited[startVertex] = true;

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }

    printf("\n");
}

int main() {
    int graph[7][7] = { {0, 1, 1, 0, 0, 0, 0},
                        {1, 0, 0, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 1},
                        {0, 1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 0, 0, 0} };

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    breadthFirstSearch(graph, 7, startVertex);

    return 0;
}
