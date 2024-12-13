#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct node {
    int data;
    struct node *left, *right;
};

// Create a new tree node
struct node *createNode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node into the BST
struct node *insertNode(struct node *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

// Function to calculate the height of the tree
int height(struct node *root) {
    if (root == NULL) {
        return -1;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

// Preorder traversal
void preorderTraversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal
void inorderTraversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Level-order display
void displayTreeLevelOrder(struct node *root) {
    if (root == NULL) {
        return;
    }

    struct node* queue[100];  // Fixed-size queue
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node *current = queue[front++];

        printf("%d ", current->data);

        if (current->left) {
            queue[rear++] = current->left;
        }
        if (current->right) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

// Find and print the left and right children of a given parent node
void printLeftRight(struct node *root, int parentData) {
    if (root == NULL) {
        return;
    }

    if (root->data == parentData) {
        if (root->left) {
            printf("Left child of %d is %d\n", parentData, root->left->data);
        } else {
            printf("Left child of %d is NULL\n", parentData);
        }

        if (root->right) {
            printf("Right child of %d is %d\n", parentData, root->right->data);
        } else {
            printf("Right child of %d is NULL\n", parentData);
        }
        return;
    }
    printLeftRight(root->left, parentData);
    printLeftRight(root->right, parentData);
}

// Main function
int main() {
    struct node *root = NULL;
    int n, key;

    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insertNode(root, key);
    }

    printf("\nTree structure (level-order display):\n");
    displayTreeLevelOrder(root);

    printf("\nPreorder traversal of the binary tree:\n");
    preorderTraversal(root);

    printf("\n\nInorder traversal of the binary tree:\n");
    inorderTraversal(root);

    printf("\n\nPostorder traversal of the binary tree:\n");
    postorderTraversal(root);

    printf("\n\nHeight of the tree: %d\n", height(root));

    printf("\nEnter a parent node to extract its left and right children: ");
    int parentData;
    scanf("%d", &parentData);
    printLeftRight(root, parentData);

    printf("\n");
    return 0;
}
