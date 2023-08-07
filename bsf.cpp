#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;
typedef struct Graph {
    int numNodes;
    Node* adjList[MAX_NODES];
    int visited[MAX_NODES];
} Graph;
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}
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
void bfs(Graph* graph, int startNode) {
    Queue* queue = createQueue();
    graph->visited[startNode] = 1;
    enqueue(queue, startNode);
    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        printf("%d ", currentNode);
        for (Node* temp = graph->adjList[currentNode]; temp != NULL; temp = temp->next) {
            int adjNode = temp->data;
            if (!graph->visited[adjNode]) {
                graph->visited[adjNode] = 1;
                enqueue(queue, adjNode);
            }
        }
    }
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
    printf("BFS traversal starting from node 0: ");
    bfs(graph, 0);
    return 0;
}
