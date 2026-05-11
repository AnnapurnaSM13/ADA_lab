#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX], result[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int i, int j) {
    parent[i] = j;
}

void sortEdges(int e) {
    int i, j;
    Edge temp;
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, e, i, j, u, v;
    int count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(e);

    for (i = 0; i < e && count < n - 1; i++) {
        u = find(edges[i].u);
        v = find(edges[i].v);

        if (u != v) {
            result[count++] = edges[i];
            cost += edges[i].w;
            unionSet(u, v);
        }
    }

    printf("\nMinimum Spanning Tree:\n");
    for (i = 0; i < count; i++) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].w);
    }

    printf("Total cost = %d\n", cost);

    return 0;
}
