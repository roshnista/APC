//rotation by 90degree of 2d Array anticlockwise
#include<iostream>
using namespace std;

void rotate(int a[][3])
{
	int n=3;
	
	for(int x=0;x<n/2;x++)
		for(int y=x;y<n-x-1;y++)
			{
				int temp=a[x][y];
				a[x][y]=a[y][n-1-x];
				a[y][n-1-x]=a[n-1-x][n-1-y];
				a[n-1-x][n-1-y]=a[n-1-y][x];
				a[n-1-y][x]=temp;	
			}	
}


int main()
{
	int a[][3]={ {1,2,3},
			     {4,5,6},
				 {7,8,9}
			   };
	
	rotate(a);
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

return 0;
}
