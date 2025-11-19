//Aim:To find required element using linear search
#include<stdio.h>
int main()
{
	int n,key,i,found=0;
	printf("enter how many elements do you want to store:\n");
	scanf("%d",&n);
	int a[n];
	printf("\n enter the %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n enter the key value to search:\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		{
			printf("\nkey found at index %d\n",i);
			found=1;
		}
	}
	if(found==0)
	{
		printf("\nkey not found");
	}
}
