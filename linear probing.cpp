#include <stdio.h>
#include <stdbool.h>
#define SIZE 10
// Define the hash table and initialize all keys to -1 (empty slot)
int hashTable[SIZE] = {-1};
// Hash function (simple modulo division)
int hashFunction(int key) {
    return key % SIZE;
}
// Insert a key-value pair into the hash table using linear probing
void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    // Linear probing to find an empty slot or the slot containing the same key
    while (hashTable[hashIndex] != -1) {
        if (hashTable[hashIndex] == key) {
            printf("Key %d already exists in the hash table. Cannot insert.\n", key);
            return;
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }
    hashTable[hashIndex] = key;
    printf("Inserted key %d with value %d into the hash table.\n", key, value);
}
// Search for a key in the hash table and return its value if found
int search(int key) {
    int hashIndex = hashFunction(key);
    // Linear probing to find the key
    while (hashTable[hashIndex] != -1) {
        if (hashTable[hashIndex] == key) {
            return hashTable[hashIndex];
        }
        hashIndex = (hashIndex + 1) % SIZE;
    }
    return -1; // Key not found
}
// Print the contents of the hash table
void printHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] -> %d\n", i, hashTable[i]);
    }
}
int main() {
    insert(10, 100);
    insert(25, 250);
    insert(6, 60);
    insert(19, 190);
    insert(14, 140);
    insert(33, 330);
    printHashTable();
    int keyToSearch = 14;
    int value = search(keyToSearch);
    if (value != -1) {
        printf("Value for key %d: %d\n", keyToSearch, value);
    } else {
        printf("Key %d not found in the hash table.\n", keyToSearch);
    }
    return 0;
}
