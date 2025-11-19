//Aim:- To Perform Linked List using Queue
#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Function to create a new node
struct Node *CreateNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert element into the queue (Enqueue)
void Enqueue(int data) {
    struct Node *newNode = CreateNode(data);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Node with data %d enqueued successfully.\n", data);
}

// Function to delete element from queue (Dequeue)
void Dequeue() {
    if (front == NULL) {
        printf("Queue is empty, deletion cannot be performed.\n");
        return;
    }
    struct Node *temp = front;
    printf("Node with data %d dequeued successfully.\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Function to display all nodes in the queue
void DisplayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("\nQueue Nodes:\n");
    while (temp != NULL) {
        printf("| Address=%p | Data=%d | Next=%p |\n", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                Enqueue(data);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                DisplayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    
    return 0;
}
