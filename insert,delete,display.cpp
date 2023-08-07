#include <stdio.h>
#define MAX_SIZE 100
// Function to display the array elements
void display(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Function to insert an element at a given position
int insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full, cannot insert element.\n");
        return 0;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return 0;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[position] = element; // Insert the element at the given position
    (*size)++;
    return 1;
}
// Function to delete an element from a given position
int deleteElement(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty, cannot delete element.\n");
        return 0;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return 0;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    (*size)--;
    return 1;
}
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice = -1, element, position;
    while (choice != 4) {
        printf("Enter your choice:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);
            if (insert(arr, &size, element, position)) {
                printf("Element inserted successfully.\n");
            }
        } else if (choice == 2) {
            printf("Enter the position to delete from: ");
            scanf("%d", &position);
            if (deleteElement(arr, &size, position)) {
                printf("Element deleted successfully.\n");
            }
        } else if (choice == 3) {
            display(arr, size);
        } else if (choice == 4) {
            printf("Exiting the program.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
