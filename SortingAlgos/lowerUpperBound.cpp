//upper bound
//lower bound
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
	int l=0,r=n,mid;
	
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]>no)
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	//low
	
	int l1=0,mid1,r1=n;
	while(l1<r1)
	{
		mid1=(l1+r1)/2;
		if(a[mid1]>=no)
			r1=mid1;
		else
			l1=mid1+1;
	}
	cout<<r1;
		
return 0;
}
