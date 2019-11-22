//change rows and cols to 0

#include<iostream>
using namespace std;

void change(int a[][5])
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)	
			{
				if(a[i][j]==2)
				{
					a[i][j]=0;
					for(int k=0;k<5;k++)
					{
					    if(a[k][j]==1) a[k][j]=0;
					    if(a[i][k]==1) a[i][k]=0;
					}
						
				}
			}
}
int main()
{
	int a[][5]={{ 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1 }
	};
	
	for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]==0)
            {
            a[i][j]=2;
            }
        }
    }
    
	change(a);
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}
