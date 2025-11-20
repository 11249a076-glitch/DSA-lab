//Aim: To perform double linked list operations
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;  
    struct Node *next;  
};


// Function to create a new node with given data
struct Node *CreateNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

                                     // Initialize new node
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


                                     // Insert node at the beginning of the list
void InsertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);

                                      // If list is empty
    if (*head == NULL) {
        *head = newNode;
    } 
    else {
                                      // Link new node with current head
        newNode->next = *head;
        (*head)->prev = newNode;

                                       // Move head to new node
        *head = newNode;
    }

    printf("Node %d inserted at beginning.\n", data);
}


void InsertAtEnd(struct Node **head, int data) {
    struct Node *newNode = CreateNode(data);

                                            // If list is empty → new node becomes head
    if (*head == NULL) {
        *head = newNode;
        printf("Node %d inserted at end.\n", data);
        return;
    }

                                             // Traverse to the last node
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

                                              // Insert new node at end
    temp->next = newNode;
    newNode->prev = temp;

    printf("Node %d inserted at end.\n", data);
}

void InsertAtPosition(struct Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

                                     // If position is 1 → insert at beginning
    if (position == 1) {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;
    int i;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node *newNode = CreateNode(data);

                                 // Adjust links for insertion
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node %d inserted at position %d.\n", data, position);
}


                                       // Delete a node by value
void DeleteNode(struct Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node *temp = *head;

    if (temp->data == value) {
        *head = temp->next;                // Move head to next node

        if (*head != NULL)
            (*head)->prev = NULL;

        free(temp);
        printf("Node %d deleted.\n", value);
        return;
    }

                                   // Traverse to find the node to delete
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", value);
        return;
    }

                                     // Adjust surrounding links
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node %d deleted.\n", value);
}


void DisplayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nDoubly Linked List: \n");

    while (temp != NULL) {
        printf("|Prev=%p| %d |Next=%p| <-> ", temp->prev, temp->data, temp->next);
        temp = temp->next;
    }
}


int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;

        case 3:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;

        case 5:
            DisplayList(head);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
