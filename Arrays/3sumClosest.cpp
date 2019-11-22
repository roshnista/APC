//3 sum closest
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[]	= {-1,2,1,-4};
	int n=4;
	int x,aa,bb,cc,sum;
	cin>>x;
	sort(a,a+n);
	int i,j,k;
	for(int i=0;i<n-2;i++)
	{
		j=i+1;
		k=n-1;
		while(j<k)
		{
			sum=a[i]+a[k]+a[j];
			if(abs(sum)<x)
				j++;
			else if(abs(sum)>x)
				k--;
			if(abs(sum)==x)
			{   aa=a[i];bb=a[j];cc=a[k];
			
			}
		}
	}
	cout<<sum;
	return 0;
}
