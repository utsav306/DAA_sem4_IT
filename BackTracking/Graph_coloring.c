#include <stdio.h>

#define V 4  // Number of vertices
#define COLORS 3  // Number of colors

int isPossible(int ind, int graph[V][V], int color[], int c) {
    for (int k = 0; k < V; k++) {
        if (graph[ind][k] && color[k] == c) {
            return 0;
        }
    }
    return 1;
}

int coloring(int ind, int graph[V][V], int color[]) {
    if (ind == V) {
        return 1;
    }

    for (int c = 1; c <= COLORS; c++) {
        if (isPossible(ind, graph, color, c)) {
            color[ind] = c;
            if (coloring(ind + 1, graph, color)) {
                return 1;
            }
            color[ind] = 0;  // BACKTRACK
        }
    }

    return 0;
}

int main() {
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {1, 1, 1, 0}};

    int color[V] = {0};

    if (coloring(0, graph, color)) {
        printf("Solution exists:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
