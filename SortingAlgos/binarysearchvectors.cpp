//binary search 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarysearch(vector<int>v1,int l,int r,int x)
{
	while(l<=r)
	{
		int mid=(l+r)/2;
		
		if(v1[mid]<x)
			l=mid+1;
			
		else if(v1[mid]>x)
			r=mid-1;
		
		else
			return mid;
	}
	
	return -1;
}

int main()
{
	int n=5;
	vector <int>v1;
	v1.push_back(1);
	v1.push_back(333);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(505);
		
	//int a[]={1,333,6,77,505};
	int x=7;
	
	sort( v1.begin(),v1.end() );
	
	int j=binarysearch(v1,0,n,x);
	cout<<j;
	return 0;
}
