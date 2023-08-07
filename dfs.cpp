#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
    int visited[MAX_NODES];
} Graph;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
void dfsUtil(Graph* graph, int currentNode) {
    graph->visited[currentNode] = 1;
    printf("%d ", currentNode);
    Node* temp = graph->adjList[currentNode];
    while (temp != NULL) {
        int adjNode = temp->data;
        if (!graph->visited[adjNode]) {
            dfsUtil(graph, adjNode);
        }
        temp = temp->next;
    }
}
void dfs(Graph* graph, int startNode) {
    dfsUtil(graph, startNode);
    printf("\n");
}
int main() {
    int numNodes = 6;
    Graph* graph = createGraph(numNodes);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    printf("DFS traversal starting from node 0: ");
    dfs(graph, 0);
    return 0;
}
