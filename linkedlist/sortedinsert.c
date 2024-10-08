#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL; 
        last->next = t;
        last = t;
    }
}

void sortedInsert(struct Node *p, int x) {
    struct Node *t, *q = NULL;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL) {
        first = t;
    } else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (q == NULL) {
            t->next = first;
            first = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    sortedInsert(first, 15); 
    display(first); 
    return 0;
}
