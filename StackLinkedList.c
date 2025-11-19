//Aim: To perform stack operations using Linked list 
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node* CreateNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void Push(struct Node **top, int data) {
    struct Node *newNode = CreateNode(data);

    newNode->next = *top;
    *top = newNode;

    printf("Pushed %d successfully.\n", data);
}


void Pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow! POP not possible.\n");
        return;
    }

    struct Node *temp = *top;
    printf("Popped %d.\n", temp->data);

    *top = (*top)->next;
    free(temp);
}


void Peek(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element = %d\n", top->data);
    }
}


void Display(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;

    printf("\nStack (Top to Bottom):\n");
    while (temp != NULL) {
        printf("|%d| -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *top = NULL;
    int choice, data;

    while (1) {
        printf("\n--- Stack Using Singly Linked List ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &data);
            Push(&top, data);
            break;

        case 2:
            Pop(&top);
            break;

        case 3:
            Peek(top);
            break;

        case 4:
            Display(top);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
