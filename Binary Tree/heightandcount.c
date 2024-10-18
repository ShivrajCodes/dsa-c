#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node** array;
};

void createQueue(struct Queue* q, int size) {
    q->size = size;
    q->front = q->rear = 0;
    q->array = (struct Node**)malloc(q->size * sizeof(struct Node*));
}

void enqueue(struct Queue* q, struct Node* value) {
    if ((q->rear + 1) % q->size != q->front) {
        q->rear = (q->rear + 1) % q->size;
        q->array[q->rear] = value;
    }
}

struct Node* dequeue(struct Queue* q) {
    struct Node* node = NULL;
    if (q->front != q->rear) {
        q->front = (q->front + 1) % q->size;
        node = q->array[q->front];
    }
    return node;
}

int isEmpty(struct Queue q) {
    return q.front == q.rear;
}

void createTree(struct Node** root) {
    struct Queue q;
    createQueue(&q, 100);

    int x;
    struct Node* p;
    printf("Enter root value: ");
    scanf("%d", &x);

    *root = (struct Node*)malloc(sizeof(struct Node));
    (*root)->data = x;
    (*root)->lchild = (*root)->rchild = NULL;

    enqueue(&q, *root);

    while (!isEmpty(q)) {
        p = dequeue(&q);

        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            struct Node* t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1) {
            struct Node* t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->lchild) + countNodes(root->rchild);
}

int treeHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = treeHeight(root->lchild);
    int rightHeight = treeHeight(root->rchild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct Node* root = NULL;
    createTree(&root);
    printf("Number of nodes: %d\n", countNodes(root));
    printf("Height of tree: %d\n", treeHeight(root));
    return 0;
}
