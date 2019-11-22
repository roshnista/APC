//using sliding window 
//no. of subarrays having sum < k
#include<iostream>
using namespace std;

int sumof(int a[],int n,int k)
{
	int sum=a[0];
	int count=0;
	int start=0,end=0;
	while(start<n && end<n)
	{
		if(sum<k)
		{
			end++;
			if(end>=start)
			{
				count=count+(end-start);
			}
			if(end<n)
			{
				sum=sum+a[end];
			}
			
		}
		else
		{
			sum=sum-a[start];
			start++;
		}
	}
	return count;
}


int main()
{
	int k=10;
	int a[] = {1,11,2,3,15};
	int n=sizeof(a)/sizeof(a[0]);
	int d=sumof(a,n,k);
	cout<<d;
	return 0;
}
