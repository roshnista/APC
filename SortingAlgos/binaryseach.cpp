//binary search
#include<iostream>
using namespace std;

int main()
{
	int n,no;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>no;
	int l=0,r=n;
	
	while(l<=r)
	{
	int mid=(l+r)/2;
	if(a[mid]==no)
	{
	cout<< mid;
	break;
	}
	else if(a[mid]>no)
		r=mid-1;
	else
		l=mid+1;
	}
	return 0;
}
