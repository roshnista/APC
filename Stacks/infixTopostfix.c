//infix to postfix
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define max 5
int st[max];
struct stack
{
	int d;
	struct stack *next;
};
struct stack *s=NULL;

void push(struct stack **top,int x)
{
	struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
	s1->d=x;
	if(*top==NULL)
	{
		s1->next=NULL;
		*top=s;
	}
	else
	{
		s1->next=*top;
		*top=s;
	}
}

struct stack * pop(struct stack *top)
{
	if(top==NULL)
	{
		printf("nothing to pop");
	}
	else
	{
		struct stack *p=top;
		top=(top)->next;
		free(p);
	}
return top;
}

int topp(struct stack *top)
{
	if(top==NULL)
		return -1;
	else
		return top->d;
}

int getpriority(char op)
{
	if(op=='/' ||op=='*' || op=='%')
		return 1;
	else if(op=='+' || op=='-')
		return 0;
}

void infixtopostfix(char src[],char trg[])
{
	int i=0,j=0;
	char temp;
	strcpy(trg,"");
	
	while(src[i]!='\0')
	{
		if(src[i]=='(')
		{
			push(&s,src[i]);
			i++;
		}
		else if(src[i]==')')
		{
			while((topp(s)!=-1) && (topp(s)!='('))
			{
				trg[j]=pop(s);
				j++;
			}
			if(topp(s)==-1)
			{
				printf("wrong");
				exit(1);
			}
			temp=pop(s);
			i++;
		}
		else if( (isdigit(src[i])) || (isalpha(src[i])))
		{
			trg[j]=src[i];
			i++;
			j++;		
		}
		else if(src[i]=='+' || src[i]=='-' || src[i]=='*' || src[i]=='/' ||src[i]=='%')
		{
			while((topp(s)!=-1) && (topp(s)!='(' ) && (getpriority(topp(s))>getpriority(src[i])))			
			{
				trg[j]=pop(s);
				j++;
			}
			push(&s,src[i]);
			i++;
		}
		else
		{
			printf("wrong");
				exit(1);
		}
	}
	
	while((topp(s)!=-1) || (topp(s)!='('))
	{
		trg[j]=pop(s);
		j++;
	}
	trg[j]='\0';
	
	
}


int main()
{
	char infix[100],postfix[100];
	gets(infix);
	strcpy(postfix,"");
	infixtopostfix(infix,postfix);
	puts(postfix);
	return 0;
}
