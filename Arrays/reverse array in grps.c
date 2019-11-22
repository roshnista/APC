//reverse in grps in c
//1234567891011 in grp of 3
//op: 3216549871110
#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int  main()
{
	int n,i,j,k;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	for(i=0;i<n;i+=k)
	{
		if((i+k)<=n)
		{
			for(j=0;j<k/2;j++)
			{
				swap(&a[i+j],&a[i+k-1-j]);
			}
		}
		else
		{
			swap(&a[i+j],&a[n-i]);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	
	
	return 0;
}
