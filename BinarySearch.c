//Aim:- To find the element using binary search
#include<stdio.h>
int main()
{
	int i,j,low=0,high,mid,n,key,sort,found=0;
	printf("\n enter how many elements do you want to store:\n");
	scanf("%d",&n);
	int a[n];
	printf("\n enter %d elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n given data:\n");
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i+1;j++)
		{
			if(a[i]<a[j])
			{
				sort=a[i];
				a[i]=a[j];
				a[j]=sort;
			}
		}
	}
	printf("\nsorted array:\n");
	for(i=0;i<n;i++)
	{
		printf("\n %d",a[i]);
	}
	printf("\n enter the key to search:\n");
	scanf("%d",&key);
	low=0;
	high=n-1;
	while(low<high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			printf("\n key found at index: %d",mid+1);
			found=1;
			break;
		}
		if(a[mid]<key)
		{
			low=mid+1;
			high=n-1;
		}
		if(a[mid]>key)
		{
			low=0;
			high=mid-1;
		}
	}
	if(found==0)
	{
		printf("\n element not found");
	}
}
