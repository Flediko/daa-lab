#include<stdio.h>
void check(int arr[],int n)
{
	int i,j,k,c=0;
	for(i=n-1;i>1;i--)
	{
		j=0;
		k=i-1;
		while(j<k)
		{
			if(arr[j]+arr[k]==arr[i])
			{
				printf("%d + %d =%d \n",j,k,i);
				j++;
				k--;
				c++;
			}
			else if(arr[j]+arr[k]>arr[i])
				k--;
			else if(arr[j]+arr[k]<arr[i])
				j++;
		}
	}
	if(c==0)
		printf("no sequemce found\n");
}
int main()
{
	int arr[100],n,l;
	printf("enter the number of arrays to check");
	scanf("%d",&l);
	for(int i=0;i<l;i++)
	{
		printf("enter the size of array");
		scanf("%d",&n);
		printf("enter the array");
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[j]);
		}
		check(arr,n);
	}
	return 0;
}
