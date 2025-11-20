//Aim:- To perform stack operations using array
#include<stdio.h>
#include<string.h>

int main()
{
    int n, max, choice, items;

    // Ask user for size of the stack
    printf("enter the size of stack:\n");
    scanf("%d", &n);

    int stack[n];      // Stack array of size n
    max = n - 1;       // Maximum valid index of stack (top position limit)
    int top = -1;      // Initialize top as -1 (empty stack)

    char op[5];        // To store user choice for repeating the loop

    do
    {
        // Display menu
        printf("\n 1. push\n 2. pop\n 3. exit\n");
        printf("\n choose the operation to be done:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:   // PUSH operation
            {
                // Check for stack overflow
                if (top == max - 1)
                {
                    printf("\n stack is overflow");
                }
                else
                {
                    top++;   // Move top to next position

                    printf("\n enter the element to be push:\n");
                    scanf("%d", &stack[top]);   // Insert element

                    printf("\n entered element: %d\n top value: %d\n", stack[top], top);
                }
                break;
            }

            case 2:   // POP operation
            {
                // Check for stack underflow
                if (top == -1)
                {
                    printf("\n stack is underflow\n");
                }
                else
                {
                    items = stack[top];   // Store top element
                    top--;                // Reduce top pointer

                    printf("\n items %d has been poped out of stack\n top value is %d ", items, top);
                }
                break;
            }

            case 3:   // EXIT program
            {
                printf("\n exiting of stack");
                return 0;
            }

            default:
            {
                printf("invalid operation");  // Handling invalid choice
            }
        }

        // Ask user if they want to continue
        printf("\n enter your choice to repeat yes or no:\n");
        scanf("%s", op);

    }
    // Continue loop until user types "no"
    while (strcmp(op, "no"));

}
