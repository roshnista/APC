//remove duplicates
#include<iostream>
#include<vector>
using namespace std;

int fu(int a[],int n)
{
	int j=0;
	for(int i=1;i<n;i++)
	{
		if(a[j]!=a[i])
		{
			j++;
			a[j]=a[i];
		}	
	}	
	return j;


}

int main()
{
	int a[]={1,1,1,2,2,3,3,4,5,6,6,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	int x=fu(a,n);
	cout<<x<<endl;
	for(int i=0;i<=x;i++)
		cout<<a[i];
	return 0;
}

