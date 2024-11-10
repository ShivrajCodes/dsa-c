/*{Write a program to implement Binary Search Tree using Linked List along with the following functions: 
To create a binary tree.
To display tree using inorder.
To display tree using preorder.
To display tree using postorder.
To count number of node present in the tree.
To find the height of the tree. 
To find the number of leaf node.
To find the number of internal node.
To search a data present in the tree}*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into the tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Count number of nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Find the height of the tree
int findHeight(struct Node* root) {
    if (root == NULL) return -1;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Count internal nodes
int countInternalNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

// Search a data in the tree
int search(struct Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\nNumber of nodes: %d", countNodes(root));
    printf("\nHeight of tree: %d", findHeight(root));
    printf("\nNumber of leaf nodes: %d", countLeafNodes(root));
    printf("\nNumber of internal nodes: %d", countInternalNodes(root));

    int key = 60;
    if (search(root, key))
        printf("\n%d is found in the tree.", key);
    else
        printf("\n%d is not found in the tree.", key);

    return 0;
}

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Insert a node in the Binary Search Tree
def insert(root, data):
    if root is None:
        return Node(data)
    if data < root.data:
        root.left = insert(root.left, data)
    else:
        root.right = insert(root.right, data)
    return root

# Inorder Traversal
def inorder(root):
    if root:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)

# Preorder Traversal
def preorder(root):
    if root:
        print(root.data, end=" ")
        preorder(root.left)
        preorder(root.right)

# Postorder Traversal
def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=" ")

# Count number of nodes
def count_nodes(root):
    if root is None:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)

# Find the height of the tree
def find_height(root):
    if root is None:
        return -1
    return max(find_height(root.left), find_height(root.right)) + 1

# Count leaf nodes
def count_leaf_nodes(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 1
    return count_leaf_nodes(root.left) + count_leaf_nodes(root.right)

# Count internal nodes
def count_internal_nodes(root):
    if root is None or (root.left is None and root.right is None):
        return 0
    return 1 + count_internal_nodes(root.left) + count_internal_nodes(root.right)

# Search a data in the tree
def search(root, key):
    if root is None:
        return False
    if root.data == key:
        return True
    if key < root.data:
        return search(root.left, key)
    return search(root.right, key)

# Main program
if __name__ == "__main__":
    root = None
    root = insert(root, 50)
    insert(root, 30)
    insert(root, 70)
    insert(root, 20)
    insert(root, 40)
    insert(root, 60)
    insert(root, 80)

    print("Inorder traversal: ", end="")
    inorder(root)
    print("\nPreorder traversal: ", end="")
    preorder(root)
    print("\nPostorder traversal: ", end="")
    postorder(root)

    print(f"\nNumber of nodes: {count_nodes(root)}")
    print(f"Height of tree: {find_height(root)}")
    print(f"Number of leaf nodes: {count_leaf_nodes(root)}")
    print(f"Number of internal nodes: {count_internal_nodes(root)}")

    key = 60
    if search(root, key):
        print(f"\n{key} is found in the tree.")
    else:
        print(f"\n{key} is not found in the tree.")
