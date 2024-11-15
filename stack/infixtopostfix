#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack is full \n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is empty \n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int isBalanced(char *exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *IntoPost(char *infix) {
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc(len + 1 * sizeof(char));
    
    push('#');
    
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (pre(infix[i]) <= pre(top->data)) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }

    while (top != NULL && top->data != '#') {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
    return postfix;
}

int main() {
    char *infix = "((a+b))*((c-d))";
    char *postfix;
    
    postfix = IntoPost(infix);
    printf("Postfix: %s\n", postfix);
    
    free(postfix);
    return 0;
}
