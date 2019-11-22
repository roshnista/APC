//concatenate string with its reverse and "$"
//make lps table
//length-lps[n-1] will be minimum no. of char required to make string palendromic

#include<stdio.h>
#include<string.h>

int main()
{
	char a[100]="aacecaaaa";
	int l=strlen(a);
	char b[strlen(a)];
	strcpy(b,a);
	strrev(b);
	
	strcat(a,"$");
	strcat(a,b);
	
	int lps[strlen(a)];
	int j=0,i=0;
	lps[0]=0;
	for(j=1;j<strlen(a);)
	{
		if(a[i]==a[j])
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
	
//	for(j=0;j<strlen(a);j++)
//		printf("%d",lps[j]);

	int n=l-lps[strlen(a)-1];
	printf("%d",n);
	return 0;
}
