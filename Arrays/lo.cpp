//max j-i using structures 

#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
	
struct elem
{
	int val;
	int index;
};

bool cmp(const void * a,const void * b)
{
	if(( (((struct elem *)a)->val)  -  ( ((struct elem *)b)->val)  )>=0)
		return 1;
	else
		return 0;
}

int main()
{
	
	struct elem arr[10];
	int a[]={34, 8, 10, 3, 2, 80, 30, 33, 1};
	int n=9;

	for(int i=0;i<n;i++)
	{
		arr[i].val=a[i];
		arr[i].index=i;
	}
	qsort(arr,n,sizeof(arr[0]),cmp);
	
	int max=0;
	int min=arr[0].index;
	
	for(int i=1;i<n;i++)
	{
		if(arr[i].index-min>max)
			max=arr[i].index-min;
		if(arr[i].index<min)
			min=arr[i].index;
	}
	cout<<max;

return 0;
}
