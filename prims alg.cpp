#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define INF 9999999
typedef struct {
    int u;
    int v;
    int weight;
} Edge;
typedef struct {
    int vertices;
    int edges;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    g->edges = 0;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjacencyMatrix[i][j] = INF;
        }
    }
}
void addEdge(Graph* g, int u, int v, int weight) {
    g->adjacencyMatrix[u][v] = weight;
    g->adjacencyMatrix[v][u] = weight;
    g->edges++;
}
void printMST(Edge* mstEdges, int numEdges) {
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("(%d, %d) Weight: %d\n", mstEdges[i].u, mstEdges[i].v, mstEdges[i].weight);
    }
}
int findMinKeyVertex(int key[], bool mstSet[], int vertices) {
    int minKey = INF;
    int minKeyVertex;
    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == false && key[v] < minKey) {
            minKey = key[v];
            minKeyVertex = v;
        }
    }
    return minKeyVertex;
}
void primMST(Graph* g) {
    Edge mstEdges[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    for (int i = 0; i < g->vertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < g->vertices - 1; count++) {
        int u = findMinKeyVertex(key, mstSet, g->vertices);
        mstSet[u] = true;
        for (int v = 0; v < g->vertices; v++) {
            if (g->adjacencyMatrix[u][v] != INF && mstSet[v] == false && g->adjacencyMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adjacencyMatrix[u][v];
            }
        }
    }
    int mstEdgeIndex = 0;
    for (int i = 1; i < g->vertices; i++) {
        mstEdges[mstEdgeIndex].u = parent[i];
        mstEdges[mstEdgeIndex].v = i;
        mstEdges[mstEdgeIndex].weight = g->adjacencyMatrix[i][parent[i]];
        mstEdgeIndex++;
    }
    printMST(mstEdges, g->vertices - 1);
}
int main() {
    int numVertices = 5;
    Graph g;
    initGraph(&g, numVertices);
    addEdge(&g, 0, 1, 2);
    addEdge(&g, 0, 3, 6);
    addEdge(&g, 1, 2, 3);
    addEdge(&g, 1, 3, 8);
    addEdge(&g, 1, 4, 5);
    addEdge(&g, 2, 4, 7);
    addEdge(&g, 3, 4, 9);
    primMST(&g);
    return 0;
}
