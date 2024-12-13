#include <stdio.h>
#include <stdlib.h>

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
int height(struct node* root) {
    if (root == NULL)
        return -1;

    // compute the height of left and right subtrees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

// Insert nodes into the tree with user input
struct node *insertNode(struct node *root) {
    int data;
    printf("Enter the data (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;  // Return NULL if data is -1, indicating no node here
    }

    struct node *newNode = createNode(data);

    // Insert left child
    printf("Enter data for the left child of %d\n", data);
    newNode->left = insertNode(newNode->left);

    // Insert right child
    printf("Enter data for the right child of %d\n", data);
    newNode->right = insertNode(newNode->right);

    return newNode;
}

// Preorder traversal
void preorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal
void inorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Display the tree level-by-level
void displayTreeLevelOrder(struct node *root) {
    if (root == NULL)
        return;

    struct node* queue[100]; // Fixed-size queue for simplicity
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* current = queue[front++];

        printf("%d ", current->data);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
    printf("\n");
}

// Find and print the left and right children of a given parent node
void printLeftRight(struct node *root, int parentData) {
    if (root == NULL)
        return;

    if (root->data == parentData) {
        if (root->left)
            printf("Left child of %d is %d\n", parentData, root->left->data);
        else
            printf("Left child of %d is NULL\n", parentData);
        
        if (root->right)
            printf("Right child of %d is %d\n", parentData, root->right->data);
        else
            printf("Right child of %d is NULL\n", parentData);
        return;
    }
    printLeftRight(root->left, parentData);
    printLeftRight(root->right, parentData);
}

int main() {
    struct node *root = NULL;
    printf("Building the binary tree...\n");
    root = insertNode(root);

    printf("\nTree structure (level-order display):\n");
    displayTreeLevelOrder(root);

    printf("\nPreorder traversal of the binary tree:\n");
    preorderTraversal(root);

    printf("\n\nInorder traversal of the binary tree:\n");
    inorderTraversal(root);

    printf("\n\nPostorder traversal of the binary tree:\n");
    postorderTraversal(root);

    printf("\n\nEnter a parent node to extract its left and right children: ");
    int parentData;
    scanf("%d", &parentData);
    printLeftRight(root, parentData);

    printf("\n");
    return 0;
}
