//median of array
#include<iostream>
using namespace std;

int main()
{
	int a[] = {10, 12, 14, 16, 18, 20};
	int b[] = {2,3,5,8};
	int n1=6,n2=4;
	
	int mid1,mid2;
		mid1=n1/2;
		mid2=(mid1+n2)/2;
	
	while(a[mid1]>b[mid2+1] || b[mid2]>a[mid1+1])
	{
	
		if(a[mid1]>b[mid2+1])
			{
		       mid1--;
		       mid2++;
			}
		
		if(b[mid2]>a[mid1+1])
			{
				mid1++;
				mid2--;	
			}
		
		
	}
	//cout<<mid1<<" "<<mid2<<endl;
	if((n1+n2)%2!=0)
		cout<<(a[mid1]<b[mid2]?a[mid1]:b[mid2]);
	else
		a[mid1]=(a[mid1]+b[mid2])/2;
		cout<<a[mid1];
	
	
	return 0;
}
