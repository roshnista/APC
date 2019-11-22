//+1 ,-1 max occured integer in array list
#include<iostream>
using namespace std;

int main()
{
	int l[]={2,1,3};
	int r[]={5,3,9};
    
	int arr[40]={0};
	
	for(int i=0;i<sizeof(l)/sizeof(l[0]);i++)
	{
		arr[l[i]]++;
		arr[r[i]+1]--;
	}
	
	int max=arr[0];
	int index;
	
	for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		arr[i]+=arr[i-1];
		if(arr[i]>max)
			{
				max=arr[i];
				index=i;
			}
	}
		
	cout<<index;
	
	return 0;
}
