//Aim:- To perform string reversal using stack operations
#include<stdio.h>
#include<string.h>

int main()
{
    int n, op, top, max, letters, i;
    char choice[5];

    // Ask user for number of elements (size of stack)
    printf("enter how many elements do you want to store:\n");
    scanf("%d", &n);

    char stack[n];     // Character stack
    top = -1;          // Stack initially empty
    max = n - 1;       // Maximum valid index of stack

    do
    {
        // Display menu options
        printf("\n 1. push\n 2.pop\n 3. exit\n");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
            {
                // Check for overflow condition
                if (top == max)
                {
                    printf("\n stack is full\n");
                    break;
                }
                else
                {
                    top += 1;   // Move to next empty position

                    printf("\n enter the element to push:\n");
                    scanf("%s", &stack[top]);  // Read a single character into stack

                    printf("\n entered char : %c\n top value:%d\n", stack[top], top);
                }
                break;
            }

            case 2:
            {
                // Check for underflow condition
                if (top == -1)
                {
                    printf("\n stack is underflow\n");
                    break;
                }
                else
                {
                    // Print the character being popped
                    printf("\n poped value in reversed order: %c", stack[top]);
                    top--;   // Remove top element
                }
                break;
            }

            default:
            {
                printf("\n invalid\n");
            }
        }

        // Ask user if they want to continue
        printf("\n enter your choice to repeat it again yes or no:\n");
        scanf("%s", choice);

    }
    // Loop continues until user types "no"
    while (strcmp(choice,"no"));

}
