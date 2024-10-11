#include <stdio.h>
#include <limits.h>

void printSolution(int V,int dist[][V]);

void floydWarshall(int V,int graph[][V]) {
    int dist[V][V];
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(V,dist);
}

void printSolution(int V,int dist[][V]) {
    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int V;
    int x;
    printf("Enter the number of vertices: "); 
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter the cost(weight) matrix (Use -1 to denote 'No Edge' or INF):\n");
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            scanf("%d",&x);
            graph[i][j] = ((x == -1) ? INT_MAX : x);
        }
    }
    floydWarshall(V,graph);
    
    return 0;
}