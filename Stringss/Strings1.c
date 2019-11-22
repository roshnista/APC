#include<stdio.h>
#include<string.h>
int main()
{
	char *arr[100];
	gets(arr);
	char **res=(char **)malloc(sizeof(char *)*100);
	int start=0;
	int end=0;
	int i=0;
	while(arr[end] != '\0' )
	{	
		while(arr[end]!=' ' && arr[end]!='\0')
		{
			end++;
		}
		
		for(i=start;i<end;i++)
		{
			res[i]=arr[i];
		}
			res[end]='\0';
			if(arr[end]=='\0')
				break;
			else
				{
					start=end+1;
					end=start;
				}
}
			puts(res);

		
		return 0;
}
