#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
} *top = NULL;

void push(char x) {
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

char pop() {
    struct Node *t;
    char x = -1;
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

int isBalanced(char *infix) {
    int i;
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    return top == NULL;
}

int pre(char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
        return 0;
    return 1;
}

char *IntoPost(char *infix) {
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 1) * sizeof(char));
    
    push('#');
    
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(') {
            push(infix[i++]);
        } else if (infix[i] == ')') {
            while (top != NULL && top->data != '(') {
                postfix[j++] = pop();
            }
            if (top != NULL && top->data == '(')
                pop();
            i++;
        } else {
            while (top != NULL && pre(infix[i]) <= pre(top->data)) {
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

    if (!isBalanced(infix)) {
        printf("The infix expression is not balanced.\n");
        return 1;
    }

    postfix = IntoPost(infix);
    printf("Postfix: %s\n", postfix);
    
    free(postfix);
    return 0;
}
