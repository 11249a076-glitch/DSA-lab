//Aim: To perform stack operations using Linked list 
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a Node in the linked list
struct Node {
    int data;              // Stores the data value
    struct Node *next;     // Pointer to the next node
};

// Function to create a new node
struct Node* CreateNode(int data) {
    // Allocate memory dynamically
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation failed
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;   // Assign data
    newNode->next = NULL;   // Initialize next pointer to NULL
    return newNode;         // Return newly created node
}

// PUSH operation: Insert element at the top of stack
void Push(struct Node **top, int data) {
    struct Node *newNode = CreateNode(data); // Create a new node

    // Link new node to current top
    newNode->next = *top;

    // Update top pointer
    *top = newNode;

    printf("Pushed %d successfully.\n", data);
}

// POP operation: Remove the element from the top
void Pop(struct Node **top) {
    // Check if stack is empty
    if (*top == NULL) {
        printf("Stack Underflow! POP not possible.\n");
        return;
    }

    struct Node *temp = *top;   // Store the top node temporarily
    printf("Popped %d.\n", temp->data);

    *top = (*top)->next;        // Move top pointer to next node
    free(temp);                 // Free memory of removed node
}

// PEEK operation: Display top element without removing it
void Peek(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element = %d\n", top->data);
    }
}

// DISPLAY operation: Print all elements from top to bottom
void Display(struct Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;

    printf("\nStack (Top to Bottom):\n");
    // Traverse the list and print each node
    while (temp != NULL) {
        printf("|%d| -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  // End of stack
}

int main() {
    struct Node *top = NULL;  // Initialize top pointer of stack
    int choice, data;

    while (1) {
        // Menu-driven program
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
            // Insert element in stack
            printf("Enter value to push: ");
            scanf("%d", &data);
            Push(&top, data);
            break;

        case 2:
            // Remove element from stack
            Pop(&top);
            break;

        case 3:
            // Show top element
            Peek(top);
            break;

        case 4:
            // Display stack
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
