#include <stdio.h>
// Function to perform binary search
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Return the index where the element is found
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half of the array
        } else {
            high = mid - 1; // Search in the left half of the array
        }
    }
    return -1; // Return -1 if the element is not found
}
int main() {
    int arr[] = {1, 3, 4, 6, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, size, key);
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
    return 0;
}
