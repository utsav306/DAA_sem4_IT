#include <stdio.h>
#include <stdbool.h>
#define v 6
#define INFINITY 9999

int mindis(bool vis[], int dist[]) {
    int min_index = -1;
    int min = INFINITY;
    for (int i = 0; i < v; i++) {
        if (!vis[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < v; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[v][v], int src) {
    bool vis[v];
    int dist[v];

    for (int i = 0; i < v; i++)
        dist[i] = INFINITY, vis[i] = false;

    dist[src] = 0;

    for (int i = 0; i < v - 1; i++) {
        int u = mindis(vis, dist);
        vis[u] = true;

        for (int j = 0; j < v; j++) {
            if (!vis[j] && graph[u][j] && dist[u] != INFINITY && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
        }
    }

    printSolution(dist);
}

int main() {
    int graph[v][v] = { { 0, 2, 0, 4, 0, 0, },
                        { 0, 0, 3, 1, 0, 0, },
                        { 0, 0, 0, 0, 0, 4,  },
                        { 0, 0, 0, 0, 2, 0, },
                        { 0, 0, 0, 0, 0, 1  },
                        { 0, 0, 0, 0, 0, 0  }
    };

    dijkstra(graph, 0);

    return 0;
}
