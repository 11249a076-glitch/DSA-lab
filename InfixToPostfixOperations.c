//Aim:- To perform infix to postfix conversions using stack
#include<stdio.h>
#include<stdlib.h>
int top=-1,max;
char *stack;

void push(char item)
{
	if(top==max-1)
	{
		printf("\n stack is overflow\n");
	}
	else
	{
		top++;
		stack[top]=item;
	}
}
char pop()
{
	char item;
	if(top==-1)
	{
		printf("\n stack under flow\n");
		return '\0';
	}
	else
	{
		item=stack[top];
		top--;
		return item;
	}
}
char peek()
{
	if(top==-1)
	{
		return '\0';
	}
	else
	{
		return stack[top];
	}
}
int getprecedence(char op)
{
	switch (op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
}
int main()
{
	printf("enter the size of infix expression:\n");
	scanf("%d",&max);
	stack=(char*)malloc(max*sizeof(char));
	char infix[max];
	char postfix[max];
	printf("\nplease enter infix string size %d:",max);
	scanf("%s",infix);
	int tokenprecedence,j=0,i=0;
	char c,temp;
	while(c=infix[i]!='\0')
	{
		tokenprecedence=getprecedence(c);
		if(tokenprecedence>0)
		{
			while(tokenprecedence<=getprecedence(peek()))
			{
				postfix[j]=pop();
				j++;
			}
			push(c);
		}
		else
		{
			switch(c)
			{
				case'(':
					{
						push(c);
						break;
					}
				case ')':
					{
						while(peek()!="(")
						{
							postfix[j++]=pop();
						}
						pop();
						break;
					}
				default:
					{
						postfix[j++]=c;
						break;
					}
			}
		}
		i++;
		while(peek()!='\0')
		{
			char c=pop();
			printf("poped char %c",c);
			postfix[j++]=c;
		}
		postfix[j]='\0';
		printf("postfix notation is %s",postfix);
		return 0;
	}
}
