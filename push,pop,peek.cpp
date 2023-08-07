#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
int top = -1;
bool isFull() {
    return top == MAX_SIZE - 1;
}
bool isEmpty() {
    return top == -1;
}
void push(int data) {
    if (isFull()) {
        printf("Stack overflow! Cannot push %d\n", data);
    } else {
        top++;
        stack[top] = data;
        printf("%d pushed to the stack.\n", data);
    }
}
void pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
    } else {
        int popped = stack[top];
        top--;
        printf("%d popped from the stack.\n", popped);
    }
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    } else {
        return stack[top];
    }
}
int main() {
    push(10);
    push(20);
    push(30);
    int topValue = peek();
    printf("Top element: %d\n", topValue);
    pop();
    pop();
    pop();
    pop(); // Trying to pop when the stack is empty.
    return 0;
}
