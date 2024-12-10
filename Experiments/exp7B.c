// implement binary tree using array
#include <stdio.h>
#define MAX_NODES 100 // Maximum number of nodes in the tree

// Binary Tree represented as an array
int tree[MAX_NODES];

// Initialize the tree with -1 (to indicate empty nodes)
void initializeTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = -1;
    }
}

// Insert a value into the binary tree at a given index
void insertNode(int value, int index) {
    if (index >= MAX_NODES) {
        printf("Index out of bounds!\n");
        return;
    }
    tree[index] = value;
}

// Display the binary tree in a tree-like format
void displayTree(int index, int level) {
    if (index >= MAX_NODES || tree[index] == -1) {
        return;
    }
    displayTree(2 * index + 2, level + 1); // Right child
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%d\n", tree[index]); // Current node
    displayTree(2 * index + 1, level + 1); // Left child
}

// Pre-order traversal (Root -> Left -> Right)
void preOrder(int index) {
    if (index >= MAX_NODES || tree[index] == -1) {
        return;
    }
    printf("%d ", tree[index]);
    preOrder(2 * index + 1); // Left child
    preOrder(2 * index + 2); // Right child
}

// In-order traversal (Left -> Root -> Right)
void inOrder(int index) {
    if (index >= MAX_NODES || tree[index] == -1) {
        return;
    }
    inOrder(2 * index + 1); // Left child
    printf("%d ", tree[index]);
    inOrder(2 * index + 2); // Right child
}

// Post-order traversal (Left -> Right -> Root)
void postOrder(int index) {
    if (index >= MAX_NODES || tree[index] == -1) {
        return;
    }
    postOrder(2 * index + 1); // Left child
    postOrder(2 * index + 2); // Right child
    printf("%d ", tree[index]);
}

// Extract left child of a given node
int leftChild(int parentIndex) {
    int leftIndex = 2 * parentIndex + 1;
    if (leftIndex < MAX_NODES && tree[leftIndex] != -1) {
        return tree[leftIndex];
    }
    return -1; // No left child
}

// Extract right child of a given node
int rightChild(int parentIndex) {
    int rightIndex = 2 * parentIndex + 2;
    if (rightIndex < MAX_NODES && tree[rightIndex] != -1) {
        return tree[rightIndex];
    }
    return -1; // No right child
}

int main() {
    // Initialize the tree
    initializeTree();

    // Insert nodes into the tree
    insertNode(1, 0); // Root
    insertNode(2, 1); // Left child of root
    insertNode(3, 2); // Right child of root
    insertNode(4, 3); // Left child of node 2
    insertNode(5, 4); // Right child of node 2

    // Display the tree
    printf("Binary Tree:\n");
    displayTree(0, 0);

    // Traversals
    printf("\nPre-order Traversal: ");
    preOrder(0);
    printf("\nIn-order Traversal: ");
    inOrder(0);
    printf("\nPost-order Traversal: ");
    postOrder(0);

    // Extract left and right child of a node
    int parent = 1; // Node at index 1
    printf("\n\nLeft child of node %d: %d\n", tree[parent], leftChild(parent));
    printf("Right child of node %d: %d\n", tree[parent], rightChild(parent));

    return 0;
}
