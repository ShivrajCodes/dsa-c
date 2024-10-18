#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(struct Node* node) {
    if (node == NULL)
        return;
    
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(struct Node* node) {
    if (node == NULL)
        return;
    
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void postorder(struct Node* node) {
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Preorder traversal: \n");
    preorder(root);

    printf("\nInorder traversal: \n");
    inorder(root);

    printf("\nPostorder traversal: \n");
    postorder(root);

    return 0;
}
