#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isFull(Queue* q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}
int isEmpty(Queue* q) {
    return (q->front == -1 && q->rear == -1);
}
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->data[q->rear] = value;
}
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return dequeuedValue;
}
int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued value: %d\n", dequeue(&q));
    printf("Dequeued value: %d\n", dequeue(&q));
    printf("Dequeued value: %d\n", dequeue(&q));
    printf("Dequeued value: %d\n", dequeue(&q)); // Trying to dequeue an empty queue
    return 0;
}
