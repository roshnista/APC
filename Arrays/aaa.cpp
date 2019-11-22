//reverse array in grps in cpp
#include<iostream>
using namespace std;

void swap(int *c,int *b);

int main()
{
	int n,k;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cin>>k;
	
	for(int i=0;i<n;i+=k)
		for(int j=0;j<k/2;j++)
			if(i+k<=n)
			{
				swap(&a[i+j],&a[i+k-1-j]);
			}
			else
			{
				for(int j=i;j<n;j++)
					swap(&a[j],&a[n-1]);
			}
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}	
	
	return 0;
}
void swap(int *c,int *b)
	{
		int t;
		t=*c;
		*c=*b;
		*b=t;
	}
