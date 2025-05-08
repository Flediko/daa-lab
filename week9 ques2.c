#include<stdio.h>
#include<stdlib.h>
struct sack{
	int val,w;
};
int cmp(const void *a,const void *b)
{
	double r1=(double)((struct sack *)a)->val/((struct sack *)a)->w;
	double r2=(double)((struct sack *)b)->val/((struct sack *)b)->w;
	return (r2>r1)-(r2<r1);
}
int main()
{
	int n,cap;
	printf("enter number of items");
	scanf("%d",&n);
	struct sack items[n];
	printf("enter weights");
	for(int i=0;i<n;i++)
		scanf("%d",&items[i].w);
	printf("enter value");
	for(int i=0;i<n;i++)
		scanf("%d",&items[i].val);
	printf("enter capacity");
	scanf("%d",&cap);
	qsort(items,n,sizeof(struct sack),cmp);
	double tv=0.0;
	for(int i=0;i<n&& cap>0;i++)
	{
		if(items[i].w<=cap)
		{
			tv+=items[i].val;
			cap-=items[i].w;
		}
		else
		{
			tv+=(double)items[i].val*cap/items[i].w;
			break;
		}
	}
	printf("Max value=%.2f",tv);
	return 0;
}
