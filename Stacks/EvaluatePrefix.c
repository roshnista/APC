//evaluate prefic expp
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define max 100
char st[max];
int top=-1;
void push(int st[],int val)
{
	top++;
	st[top]=val;
}

int pop(int st[])
{
	int v= st[top];
	top--;
	return v;
}
int gettype(char c)
{
	if(c=='+' ||c=='/' ||c=='*' || c=='-')
		return 1;
	else return 0;
}

int expp(char ch[])
{
	int i=0;
	int op1=0,op2=0;
	int s=0;
	int l=strlen(ch);
	for(i=l-1;i>=0;i--)
	{
		if(!gettype(ch[i]))
			push(st,(int)(ch[i]-'0'));
		else
		{
			op2=pop(st);
			op1=pop(st);
			
			switch(ch[i])
			{
				case '+':
					s=op1+op2;
					break;		
				case '-':
					s=op1-op2;
					break;
				case '*':
					s=op1-op2;
					break;
				case '/':
					s=op1-op2;
					break;
				
			}	
			push(st,s);
		}		
		
	}
	return (pop(st));
}

int main()
{
	char ch[100];
	gets(ch);
	int val=expp(ch);
	printf("%d",val);
	getch();
	return 0;
}

