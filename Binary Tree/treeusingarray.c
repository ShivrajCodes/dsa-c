/*1. Write a program to implement Binary Tree using array along with the     
     following functions: 
To create a binary tree.
To display tree using inorder.
To display tree using preorder.
To display tree using postorder.
To count number of node present in the tree.
To find the height of the tree. 
To find the number of leaf node.
To find the number of internal node.
To search a data present in the tree.*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

int tree[MAX];
int size = 0;  // Number of nodes

// Create a binary tree by inserting data at available position
void createTree(int data) {
    if (size == MAX) {
        printf("Tree is full!\n");
        return;
    }
    tree[size++] = data;
}

// Inorder traversal: left, root, right
void inorder(int index) {
    if (index >= size) return;
    inorder(2 * index + 1);  // Left child
    printf("%d ", tree[index]);  // Root
    inorder(2 * index + 2);  // Right child
}

// Preorder traversal: root, left, right
void preorder(int index) {
    if (index >= size) return;
    printf("%d ", tree[index]);  // Root
    preorder(2 * index + 1);  // Left child
    preorder(2 * index + 2);  // Right child
}

// Postorder traversal: left, right, root
void postorder(int index) {
    if (index >= size) return;
    postorder(2 * index + 1);  // Left child
    postorder(2 * index + 2);  // Right child
    printf("%d ", tree[index]);  // Root
}

// Count the number of nodes
int countNodes() {
    return size;
}

// Find the height of the tree
int treeHeight(int index) {
    if (index >= size) return 0;
    int leftHeight = treeHeight(2 * index + 1);
    int rightHeight = treeHeight(2 * index + 2);
    return fmax(leftHeight, rightHeight) + 1;
}

// Count the number of leaf nodes
int countLeafNodes(int index) {
    if (index >= size) return 0;
    if (2 * index + 1 >= size && 2 * index + 2 >= size) return 1;
    return countLeafNodes(2 * index + 1) + countLeafNodes(2 * index + 2);
}

// Count the number of internal nodes
int countInternalNodes(int index) {
    if (index >= size || (2 * index + 1 >= size && 2 * index + 2 >= size))
        return 0;
    return 1 + countInternalNodes(2 * index + 1) + countInternalNodes(2 * index + 2);
}

// Search for a data in the tree
bool searchTree(int data) {
    for (int i = 0; i < size; i++) {
        if (tree[i] == data)
            return true;
    }
    return false;
}

int main() {
    createTree(1);
    createTree(2);
    createTree(3);
    createTree(4);
    createTree(5);
    createTree(6);

    printf("Inorder Traversal: ");
    inorder(0);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(0);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(0);
    printf("\n");

    printf("Number of nodes: %d\n", countNodes());
    printf("Height of tree: %d\n", treeHeight(0));
    printf("Number of leaf nodes: %d\n", countLeafNodes(0));
    printf("Number of internal nodes: %d\n", countInternalNodes(0));

    int data = 4;
    printf("Search for %d: %s\n", data, searchTree(data) ? "Found" : "Not Found");

    return 0;
}
