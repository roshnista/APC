#include<stdio.h>

int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int countp(int n,int *a,int k)
{
	int c=0;
	int j=0,i=0;
	//sort
	qsort(a,n,sizeof(int),cmp);
	//remove duplicates
	for( i=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1])
			{
				a[j]=a[i];
				j++;
			}
		a[j]=a[n-1];
	}
	
	n=j;
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]-a[i]==k)
			c++;
	}
	return c;
}
int main()
{
	int n=6;
	int a[6]={1,1,2,2,3,3};
	int k=1;
	int x=countp(n,a,k);
	printf("%d",x);
	return 0;
}
