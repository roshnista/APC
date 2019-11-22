//count consecutive 1s
#include<iostream>
using namespace std;
int main()
{
	int n,mac=0,c=0;
	cin>>n;
	for(int i=0;i<32;i++)
	{
		if(n&(1<<i))
			c++;
		else
		{
			if(c>mac)
				{
				mac=c;
				c=0;
				}	
		}
	}
	cout<<mac;
return 0;
}
