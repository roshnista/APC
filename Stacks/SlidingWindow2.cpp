//sliding window2
#include<iostream>
using namespace std;
int main()
{
	int left=0,right=0,l,r,max=-1,m=2;
	int a[]={1,0,0,1,0,1,0,1,0,1};
	int n=10;
	int maxi=m;
	
	while(right<n)
	{
		if(a[right]==1)
			right++;
		else if(a[right]==0 && m)
		{
			right++;
			m--;
		}
		else if(a[right]==0)
		{
			while(a[left]!=0)
			{
				left++;					
			}left++;
			
		
		}
		
		if(m<maxi)
			m++;
		if(left<right)
			left=right;
		if(right-left>max)
			max=right-left;
		if(right>max)
		{
			max=right;
			r=right;
			l=left;
		}
	}
	
	cout<<r<<endl<<l;
	return 0;
}
