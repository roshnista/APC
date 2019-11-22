//maximum sum of contigous sub-arrays 
#include<iostream>
using namespace std;

int main()
{
	int a[]={-2,1,-3,4,-1,2,1,-5,4};	
	int n=sizeof(a)/sizeof(a[0]);
	int m[n];
	int max=a[0],sum=0,k=0;
	
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum>=a[i])
		{
			m[k]=sum;
			k++;
			if(sum>max)
				max=sum;
			
		}
		else
		{
			sum=0;
			i--;
		}
	}
	cout<<max;
	
	return 0;
}
