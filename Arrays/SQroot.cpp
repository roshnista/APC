//nearest sqroot using binary search
#include<iostream>
using namespace std;
int main()
{
	int k;
	cin>>k;
	int a[k];
	for(int i=0;i<k;i++)
		a[i]=i;
		
	int mid, l=0,h=k;
	while(l<=h)
	{
		mid=(l+h)/2;
		if((a[mid]*a[mid])==k)
		{
			break;
		}
		else if((a[mid]*a[mid]) >k)
			h=mid-1;
		else
			l=mid+1;		
	}
	cout<<mid;
	return 0;
}
