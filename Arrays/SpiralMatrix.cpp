//spiral matrix

#include<iostream>
using namespace std;
int main()
{
	int a,b,c,d,co=0;
	a=d=0;
	c=b=3;
	int arr[4][4];
	
	while(a<=c && d<=b)
	{
		for(int i=d;i<=b;i++)
			arr[a][i]=co++;
		a++;
		for(int i=a;i<=c;i++)
			arr[i][b]=co++;
		b--;
		for(int i=b;i>=d;i--)
			arr[c][i]=co++;
		c--;
		for(int i=c;i>=a;i--)
			arr[i][d]=co++;
		d++;
	}
	for(int i=0;i<4;i++)
	{
			for(int j=0;j<4;j++)
			{
			 cout<<arr[i][j]<<" ";
			}
		cout<<endl;		
	}
	
return 0;
}
