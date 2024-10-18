#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->data) {
        root->lchild = insert(root->lchild, key);
    } else if (key > root->data) {
        root->rchild = insert(root->rchild, key);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d, ", root->data);
        inorder(root->rchild);
    }
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->lchild, key);
    }
    return search(root->rchild, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 8);
    insert(root, 30);
    inorder(root);
    printf("\n");
    int key = 2;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("Element %d found\n", result->data);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
