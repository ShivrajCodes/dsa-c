#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

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

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int count(struct Node *p) {
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

int Delete(struct Node *p, int index) {
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;

    if (index == 1) {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    } else {
        for (i = 0; i < index - 1 && p; i++) {
            q = p;
            p = p->next;
        }
        if (p) {
            q->next = p->next;
            x = p->data;
            free(p);
        }
        return x;
    }
}
void Delete (struct Node *p, int index )
{
    struct Node *t;
    int x=-1;
    if (index < 1 )
       return -1;
    for (int i=1; index-1; i+=2)
    {
        t=p;
        p=p->next;
    }
    t->next=p->next;
    x=p->data;
    free(p);
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    printf("The deleted element is : %d\n", Delete(first, 3));
    display(first);

    return 0;
}
