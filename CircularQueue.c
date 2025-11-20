//Aim:- To perform circular queue operations using array
#include<stdio.h>
#include<string.h>

int main()
{
    int n, rear, front, max, item, max_size, op;
    char choice[5];

    // Ask user for queue size
    printf("\nEnter the size of queue:\n");
    scanf("%d", &n);

    int queue[n];                   // Circular queue implemented using array

    rear = -1;                      // rear = index of last inserted element
    front = -1;                     // front = index of first element
    max_size = n;                   // store the capacity of queue

    do
    {
        // Menu of operations
        printf("\nEnter the operation of queue:\n1. Enqueue\n2. Dequeue\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
            {
                // Check full condition in circular queue
                if ((rear + 1) % max_size == front)
                {
                    printf("\nQueue Overflow! No more insertion possible.\n");
                    return 0;
                }
                else
                {
                    // If queue is empty initially
                    if (front == -1)
                    {
                        front = 0;
                        rear = 0;
                    }
                    else
                    {
                        // Move rear circularly
                        rear = (rear + 1) % max_size;
                    }
                }

                // Insert the element at rear
                printf("Enter the item:\n");
                scanf("%d", &queue[rear]);

                printf("\nEntered item: %d\nRear index: %d\n", queue[rear], rear);
                break;
            }

            case 2:
            {
                // Check underflow condition
                if (front == -1)
                {
                    printf("\nQueue Underflow! No item to delete.\n");
                    break;
                }
                else
                {
                    // Item to delete
                    item = queue[front];

                    // When only one element is left
                    if (front == rear)
                    {
                        front = -1;
                        rear  = -1;
                    }
                    else
                    {
                        // Move front circularly
                        front = (front + 1) % max_size;
                    }
                }

                printf("\nDeleted item = %d\nFront index after deletion: %d", item, front);
                break;
            }

            default:
            {
                printf("Invalid operation");
                return 0;
            }
        }

                                     // Ask user whether to continue or stop
        printf("\nDo you want to repeat? (yes or no):\n");
        scanf("%s", choice);

    } while (strcmp(choice, "no"));  // Loop continues until choice = "no"

    return 0;
}
