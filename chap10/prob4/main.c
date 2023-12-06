#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct node **top) {
    if (*top == NULL) {
        fprintf(stderr, "The stack is empty.\n");
        exit(EXIT_FAILURE);
    }

    struct node *temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);

    return data;
}

void printStack(struct node *top) {
    printf("Print stack\n");
    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {
    struct node *top = NULL;

    push(&top, 55);
    push(&top, 606);
    push(&top, 808);
    push(&top, 818);
    push(&top, 2);

    printf("Command : ./pp\n");
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));
    printf("%d\n", pop(&top));

    printf("%f\n", 2.3);
    printStack(top);

    return 0;
}

