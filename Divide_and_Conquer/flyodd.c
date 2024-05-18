#include <stdio.h>
#define INFINITE 999
#define v 4

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

void floyd(int graph[v][v]) {
    int k, i, j;
    int cost[v][v];

  
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (graph[i][j] == 0)
                cost[i][j] = INFINITE;
            else
                cost[i][j] = graph[i][j];
            
            if (i == j)
                cost[i][j] = 0;
        }
    }

    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (cost[i][j] == INFINITE)
                printf("INF\t");
            else
                printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[v][v] = {{0, 5, 0, 10},
                       {0, 0, 3, 0},
                       {0, 0, 0, 1},
                       {0, 0, 0, 0}};

    floyd(graph);

    return 0;
}
