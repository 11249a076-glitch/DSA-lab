//Aim:- To perform stack operations using array
#include<stdio.h>
#include<string.h>
int main()
{
	int n,max,choice,items;
	printf("enter the size of stack:\n");
	scanf("%d",&n);
	int stack[n];
	max=n-1;
	int top=-1;
	char op[5];
	do
	{
		printf("\n 1. push\n 2. pop\n 3. exit\n");
		printf("\n choose the operation to be done:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					if(top==max-1)
					{
						printf("\n stack is overflow");
					}
					else
					{
						top++;
						printf("\n enter the element to be push:\n");
						scanf("%d",&stack[top]);
						printf("\n entered element: %d\n top value: %d\n",stack[top],top);
					}
					break;
				}
			case 2:
			{
				if(top==-1)
				{
					printf("\n stack is underflow\n");
				}
				else
				{
					items=stack[top];
					top--;
					printf("\n items %d has been poped out of stack\n top value is %d ",items,top);
				}
				break;
			}
			case 3:
			{
				printf("\n exiting of stack");
				return 0;
			}
			default:
			{
				printf("invalid operation");
			}	
		}
		printf("\n enter your choice to repeat yes or no:\n");
		scanf("%s",op);
	}
	while(strcmp(op,"no"));
}
