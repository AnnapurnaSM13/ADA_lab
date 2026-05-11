#include <stdio.h>

#define MAX 100

int main() {
    int n, i, j;
    int graph[MAX][MAX];
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }


    while(front < rear) {
        int vertex = queue[front++];

        topo[count++] = vertex;


        for(i = 0; i < n; i++) {
            if(graph[vertex][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }


    if(count == n) {
        printf("Topological Ordering:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", topo[i]);
        }
    } else {
        printf("Graph has a cycle. Topological ordering not possible.\n");
    }

    return 0;
}