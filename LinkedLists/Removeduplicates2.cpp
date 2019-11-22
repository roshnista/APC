//remove duplicates after 2 times
#include<iostream>
using namespace std;

int fu(int a[],int n)	
{
	int j=0,c=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1] && a[i+1]==a[i+2] && i<n-2)
			continue;
		else
			a[j++]=a[i];	
	}
 	return j;
}

int main()
{
	int a[]={1,1,1,2,2,3,3,4,4,5,6,6,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	int x=fu(a,n);
	for(int i=0;i<x;i++)
		cout<<a[i];
	return 0;
}
