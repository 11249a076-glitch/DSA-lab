//Aim:- To perform infix to postfix conversions using stack
#include<stdio.h>
#include<stdlib.h>

int top = -1, max;     // Global stack top and max size
char *stack;           // Dynamically allocated stack (char array)

void push(char item)
{
    if (top == max - 1)       // If stack is full
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = item;    // Insert item at top
    }
}


char pop()
{
    char item;
    if (top == -1)            // If stack is empty
    {
        printf("\nStack Underflow\n");
        return '\0';          // Return null char
    }
    else
    {
        item = stack[top];
        top--;
        return item;          // Return removed character
    }
}


// Returns the top element without popping
char peek()
{
    if (top == -1)
        return '\0';
    else
        return stack[top];
}

int getprecedence(char op)
{
    switch (op)
    {
        case '+':
        case '-': return 1;

        case '*':
        case '/': return 2;

        case '^': return 3;

        default:  return 0;   // For non-operators
    }
}


int main()
{
    printf("Enter the size of infix expression:\n");
    scanf("%d", &max);

    stack = (char*)malloc(max * sizeof(char));    // Allocate stack memory

    char infix[max];     // Input expression
    char postfix[max];   // Output expression

    printf("\nPlease enter infix string (size %d): ", max);
    scanf("%s", infix);

    int tokenprecedence, j = 0, i = 0;
    char c, temp;

    while ( (c = infix[i]) != '\0' )  // Read character by character
    {
        tokenprecedence = getprecedence(c);

        // Case 1: Character is an operator (+,-,*,/,^)
        if (tokenprecedence > 0)
        {
            // Pop operators with higher or equal precedence
            while (tokenprecedence <= getprecedence(peek()))
            {
                postfix[j++] = pop();
            }
            push(c);   // Push current operator
        }

        // Case 2: Character is NOT an operator
        else
        {
            switch (c)
            {
                // Opening bracket → push it
                case '(':
                    push(c);
                    break;

                // Closing bracket → pop until '(' is found
                case ')':
                    while (peek() != '(')
                    {
                        postfix[j++] = pop();
                    }
                    pop(); // Remove '('
                    break;

                // Operand → directly move to postfix
                default:
                    postfix[j++] = c;
                    break;
            }
        }

        i++;
    }

    while (peek() != '\0')
    {
        char c = pop();
        printf("Popped char: %c\n", c);
        postfix[j++] = c;
    }

    postfix[j] = '\0';   // End postfix string

    printf("\nPostfix notation is: %s\n", postfix);

    return 0;
}
