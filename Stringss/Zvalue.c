//Z VALUE ALGORITHM
#include<stdio.h>
#include<string.h>
int main()
{
	char a[]="baabaa";
	char b[]="aab";
	char c[100];
	int ll=strlen(b);
	strcpy(c,b);
	strcat(c,"$");
	strcat(c,a);


	int z[strlen(c)];
	z[0]=0;
	int l=1,r=1;
	int i=0;
	
	for(i=1;i<strlen(c);i++)
	{
		if(i>=r)
		{
			l=r=i;
			while(c[r]==c[r-l])
				r++;
			z[i]=r-l;
		}
		else
		{
			if(i+z[i-l] < r)
				z[i]=z[i-l];
			else
				{
					l=i;
					while(c[r]==c[r-l])
						r++;
					z[i]=r-l;
					
				}
		}
	}
	
	
	for(i=0;i<strlen(c);i++)
	{
		if(z[i]==ll)
		{
		printf("true  %d" ,i-ll-1);
		break;
		}
	}
	
	
	return 0;
}
