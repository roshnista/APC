//right rotation 997 times
#include<iostream>
using namespace std;

void rotate(int *arr,int s)
{
	int temp=arr[s-1];
	for(int i=1;i<s;i++)
	{
		arr[s-i]=arr[s-i-1];
	}
	arr[0]=temp;
}
int main()
{
	int arr[]={1,2,3,4,5};
	int s=sizeof(arr)/sizeof(arr[0]);
	
	int k;
	cin>>k;
	
	int n=k%s;
	
	for(int i=0;i<n;i++)
	{
		rotate(arr,s);
	}
	
	for(int i=0;i<s;i++)
	{
		cout<<arr[i];
	}
	
	
	return 0;
}
