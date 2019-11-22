#include<iostream>
#include<string.h>
using namespace std;
int change(char r)
{
	if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
  
    return -1; 
}

int main()
{
	string s;
	cin>>s;
	int res=0;
	for(int i=0;i<s.size();i++)
	{
		
		int a1=change(s[i]);
		if(i+1<s.size())
		{
			int a2=change(s[i+1]);
			if(a1>=a2)
				{
					res=res+a1;
				}
			else
				{
					res=res+a2-a1;
					i++;
				}
		}
		else
		{
			res=res+s[i];
		}
	}
	cout<<res;
	return 0;
}



