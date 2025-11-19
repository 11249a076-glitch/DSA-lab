//Aim:- To perform string reversal using stack operations
#include<stdio.h>
#include<string.h>
int main()
{
	int n,op,top,max,letters,i;
	char choice[5];
	printf("enter how many elements do you want to store:\n");
	scanf("%d",&n);
	char stack[n];
	top=-1;
	max=n-1;
	do
	{
		printf("\n 1. push\n 2.pop\n 3. exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					if(top==max)
					{
						printf("\n stack is full\n");
						break;
					}
					else
					{
						top+=1;
						printf("\n enter the element to push:\n");
						scanf("%s",&stack[top]);
						printf("\n entered char : %c\n top value:%d\n",stack[top],top);
					}
					break;
				}
			case 2:
				{
					if(top==-1)
					{
						printf("\n stack is underflow\n");
						break;
					}
					else
					{
						printf("\n poped value in reversed order: %c",stack[top]);
						top--;
					}
					break;
				}
			default:
			{
				printf("\n invalid\n");
			}	
		}
		printf("\n enter your choice to repeat it again yes or no:\n");
		scanf("%s",&choice);
	}
	while(strcmp(choice,"no"));
}
