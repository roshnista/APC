//arrival and departure for booking of rooms
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a[]={1,3,5},b[]={2,6,8};
	int k,n=3,x=1;
	cout<<"enter no. of rooms";
	cin>>k;
	
	//sort 
	sort(a,a+n);
	sort(b,b+n);
			
	for(int i=0;i<n-1;i++)
	{
	    if(b[i]>a[i+1])
	        x++;
	    else
	    	{
			x--;
			break;
			}	
	}
	if(x>k)
		cout<<"false";
	else
		cout<<"TRUE";

return 0;	
}
