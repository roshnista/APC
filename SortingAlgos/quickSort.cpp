//quick sort
#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
} 

int partition(int a[],int low,int high)
{
	int pivot=a[high];
	int i=low-1;
	
	for(int j=low;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}	
	}	
	swap(&a[i+1],&a[high]);
	return (i+1) ;
}
 
void quicksort(int a[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(a,low,high);	
		quicksort(a,low,pi-1);
		quicksort(a,pi+1,high);
	}
}

int main()
{
	int n=10;
	int a[]={1,3,0,99,55,3,7,9,4,505};
	quicksort(a,0,n-1);
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	return 0;
}
