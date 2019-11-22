//rabin karp
#include<stdio.h>
#include<string.h>
#define d 256

void src(char *a,char *b)
{
	int q=101;
	int n=strlen(a);
	int m=strlen(b);
	int p=0,t=0,h=1;
	int i=0,j=0;
	//pow of h
	for(i=0;i<m-1;i++)
		h=(h*d)%q;
	
	//hash value for pattern
	for(i=0;i<m;i++)
	{
		p=(d*p+b[i])%q;
		t=(d*t+a[i])%q;
	}
	
	for(i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				if(a[j]!=b[j])
					break;
			}
			if(j==m)
				printf("true at %d ",i);
		}
		
		if(i<n-m)
		{
			t=(d*(t-a[i]*h)+a[i+m])%q;
			if(t<0)
				t=t+q;
		}
	}
}


int main()
{
	char a[]="geeks for geeks";
	char b[]="geeks";
	src(a,b);	
	return 0;
}
