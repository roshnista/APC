#include<iostream>
using namespace std;

void merge(int *a,int l,int r)
{
	int mid=(l+r)/2;
	int i=l;
	int j=mid+1;
	int k=l;
	
	int ab[100];
	
	while(i<=mid && j<=r)
	{
		if(a[i]<a[j])
			ab[k++]=a[i++];
		else
			ab[k++]=a[j++];
	}
	while(i<=mid)
		ab[k++]=a[i++];
	
	while(j<=r)
		ab[k++]=a[j++];
		
		
	for(int i=l;i<=r;i++)
		a[i]=ab[i];
			
}

void mergesort(int a[],int l, int r)
{
	//divide
	int mid=(l+r)/2;
	
	//sort
	if(l>=r)
		return;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	
	//merge
	merge(a,l,r);
}


int countp(int n,int *a,int k)
{
	int c=0;
	int j=0;
	//sort
	mergesort(a,0,n-1);
	 
	//remove duplicates
	for(int i=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1])
			{
				a[j]=a[i];
				j++;
			}
		
	}
	a[j]=a[n-1];
	
	n=j;
	for(int i=0;i<n;i++)
	{
		if(a[i+1]-a[i]==k)
			c++;
	}
	return c;
}
int main()
{
	int n=6;
	int a[6]={1,2,3,2,4,3};
	int k=1;
	int x=countp(n,a,k);
	printf("%d",x);
	return 0;
}
