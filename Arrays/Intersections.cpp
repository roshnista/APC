//intersection
#include<iostream>
using namespace std;

int main()
{
	int a[]={1,1,2,2,3,3,4,5,6};
	int b[]={3,3,5};
	
	int i=0,j=0;
	int n=sizeof(a)/sizeof(a[0]);
	int m=sizeof(b)/sizeof(b[0]);
	
	while(i<n && j<m)
	{
		if(a[i]<b[j])
			i++;
		else
		{
			cout<<a[i];
			i++;
			j++;
		}
	}
	
	
	
return 0;
}
