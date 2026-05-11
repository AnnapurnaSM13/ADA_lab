#include <stdio.h>
#define INF 99999
int V;
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[20][20];
    printf("enter number of points:");
    scanf("%d",&V);
    printf("enter distance matrix:");
    for(int i=0;i<V;i++){
        for(int j=0;j<V                ;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
