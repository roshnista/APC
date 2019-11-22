//binary search 
#include<stdio.h>

int cmp(const void *a,const void *b)
{
	return ( *((int*)a) - *((int*)b));
}

int binarysearch(int a[],int l,int r,int x)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if(a[mid]<x)
			l=mid+1;
			
		else if(a[mid]>x)
			r=mid-1;
		
		else
			return mid;
	}
	
	return -1;
}

int main()
{
	int n=5;
	
	int a[]={1,333,6,77,505};
	qsort(a,5,sizeof(int),cmp);
	int x=1;
	
	int j=binarysearch(a,0,n-1,x);
	printf("%d",j);
	return 0;
}
