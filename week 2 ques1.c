#include<stdio.h>
int fo(int arr[],int n,int key)
{
	int low=0,high=n-1,f=-1;
	while (low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==key)
		{
			f=mid;
			high=mid-1;
		}
		else if(arr[mid]<key)
		{
			low=mid+1;
		}
		else
			high=mid-1;
	}
	return f;
}
int lo(int arr[],int n,int key)
{
	int low=0,high=n-1,l=-1;
	while (low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==key)
		{
			l=mid;
			low=mid+1;
		}
		else if(arr[mid]<key)
		{
			low=mid+1;
		}
		else
			high=mid-1;
	}
	return l;
}
void main()
{
	int n,l,key;
	int arr[100];
	printf("enter the number of arrays to input");
	scanf("%d",&l);
	for (int i=0;i<l;i++)
	{
		printf("enter the size of the array");
		scanf("%d",&n);
 		printf("enter the array");
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[j]);
		}
		printf("enter the key");
		scanf("%d",&key);
		int f=fo(arr,n,key);
		int l=lo(arr,n,key);
		if(f==-1)
		{
			printf("not found\n");
		}
		else
		{
			printf(" Found %d-%d\n",key,l-f+1);
		}
	}
}
	
