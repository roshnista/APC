#include<stdio.h>
#include<string.h>

void kmp(char *a,char *b)
{
	int n1=strlen(a);
	int n2=strlen(b);
	int lps[n1];
	lps[0]=0;
	int i=0,j=1;
			
	//lps table
			while(j<n2)
			{
				if(b[i]==b[j])
				{
					lps[j]=i+1;
					i++;
					j++;
				}
				else
				{
					if(i==0)
						{
							lps[j]=0;
							j++;
						}
					else
						{
							i=lps[i-1];
						}
				}
			}
	
	//compare substring
	
	i=0;j=0;
	while(i<n1)
	{
		if(a[i]==b[j])
		{
			i++;j++;
		}
		if(j==n2)
		{
			printf("pattern found at %d   ",i-j);
			j=lps[j-1];
		}
		else if(a[i]!=b[j])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i=i+1;
		}
	}
	
	
	
}

int main()
{
	char a[]="bbaaabaaaaababbaaaaaba"	;
	char b[]="abbbbaaab";
	kmp(a,b);
	return 0;
}
