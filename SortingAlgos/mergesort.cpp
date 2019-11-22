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
	
	if(l>=r)
		return;
	//sort
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	
	//merge
	merge(a,l,r);
}

int main()
{
	int n=6;
	int a[]={1,2,3,2,4,3};


	mergesort(a,0,n-1);
	
	for(int i=0;i<n;i++)
		cout<<a[i];
	
	
	return 0;
}
