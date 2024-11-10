/*2. Write a program to implement Binary Tree using linked list along with the     
     following functions: 
To create a binary tree.
 To display tree using inorder.
To display tree using preorder.
To display tree using postorder.
To count number of node present in the tree.
To find the height of the tree.
To find the number of leaf node.
To find the number of internal node.
To search a data present in the tree. */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node in binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

// Inorder traversal: left, root, right
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal: root, left, right
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: left, right, root
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Count the number of nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Find the height of the tree
int treeHeight(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count the number of leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Count the number of internal nodes
int countInternalNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Search for a data in the tree
bool searchTree(struct Node* root, int data) {
    if (root == NULL) return false;
    if (root->data == data) return true;
    if (data < root->data)
        return searchTree(root->left, data);
    return searchTree(root->right, data);
}

int main() {
    struct Node* root = NULL;

    // Creating binary tree
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Number of nodes: %d\n", countNodes(root));
    printf("Height of tree: %d\n", treeHeight(root));
    printf("Number of leaf nodes: %d\n", countLeafNodes(root));
    printf("Number of internal nodes: %d\n", countInternalNodes(root));

    int data = 4;
    printf("Search for %d: %s\n", data, searchTree(root, data) ? "Found" : "Not Found");

    return 0;
}

