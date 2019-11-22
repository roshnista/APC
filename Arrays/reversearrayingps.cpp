#include<iostream>
using namespace std;

int main()
{
	void swap(int *a,int *b)
	{
		int t;
		t=a;
		a=b;
		b=t;
	}
	
	int n,k;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;
	
	for(int i=0;i<n;i+k)
		for(int j=0;j<k/2;k++)
			if(i+k<=n)
			{
				swap(&a[i+j],&a[i+k-1-j]);
			}
			else
			{
				for(int j=i;j<n;j++)
					swap(&a[j],&a[n-1]);
			}
	
	for(i=0;i<n;i++)
	{
		cout<<a[i];
	}	
	
	return 0;
}
