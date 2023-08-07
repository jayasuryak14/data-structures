#include <stdio.h>
#include <stdlib.h>
#define MAX_EDGES 100
typedef struct {
    int src, dest, weight;
} Edge;
typedef struct {
    int numNodes, numEdges;
    Edge edges[MAX_EDGES];
} Graph;
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}
void unionSets(int parent[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);
    parent[xRoot] = yRoot;
}
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}
void kruskalMST(Graph* graph) {
    int parent[graph->numNodes];
    for (int i = 0; i < graph->numNodes; i++)
        parent[i] = i;
    qsort(graph->edges, graph->numEdges, sizeof(Edge), compareEdges);
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < graph->numEdges; i++) {
        int srcRoot = find(parent, graph->edges[i].src);
        int destRoot = find(parent, graph->edges[i].dest);
        if (srcRoot != destRoot) {
            printf("%d - %d\n", graph->edges[i].src, graph->edges[i].dest);
            unionSets(parent, srcRoot, destRoot);
        }
    }
}
int main() {
    int numNodes = 5;
    Graph graph = {numNodes, 0};
    // Add edges to the graph (src, dest, weight)
    graph.edges[graph.numEdges++] = (Edge){0, 1, 2};
    graph.edges[graph.numEdges++] = (Edge){0, 3, 6};
    graph.edges[graph.numEdges++] = (Edge){1, 2, 3};
    graph.edges[graph.numEdges++] = (Edge){1, 3, 8};
    graph.edges[graph.numEdges++] = (Edge){1, 4, 5};
    graph.edges[graph.numEdges++] = (Edge){2, 4, 7};
    graph.edges[graph.numEdges++] = (Edge){3, 4, 9};
    kruskalMST(&graph);
    return 0;
}
