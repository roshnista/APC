#include<stdio.h>
#include<string.h>
#define max 100

//
//struct stack
//{
//	char d;
//	struct stack *next;	
//};
//struct stack *top=NULL;
//
//void push(char c)
//{
//	struct stack *n=(struct stack *)malloc(sizeof(struct stack));
//	n->d=c;
//	if(top==NULL)
//	{
//		n->next=NULL;
//		top=n;
//	}
//	else
//	{
//		n->next=top;
//		top=n;
//	}
//}
//
//char pop()
//{
//	struct stack *l=top;
//	if(top!=NULL)
//	{
//		top=top->next;
//		free(l);
//		}
//	
//}
//
//int topp()
//{
//	if(top==NULL)
//		return -1;
//	else 
//		return (int)top->d;
//}

int stk[max];
int top=-1;

void push(char c)
{
	stk[++top]=c;
}

char pop()
{
	return stk[top--];
}

int main()
{
	char exp[max],temp=0;
	int i,flag=1;
	gets(exp);
	
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
			push(exp[i]);
		if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if(top==-1)
				flag=0;
			else
			{
				temp=pop();
				if(exp[i]==')' && (temp=='{' || temp=='['))
					flag=0;
				if(exp[i]==']' && (temp=='{' || temp=='('))
					flag=0;
				if(exp[i]=='}' && (temp=='(' || temp=='['))
					flag=0;
			}
		}
	}
	
	if(top>=0)
		flag=0;
	
	if(flag==1)
		printf("valid");
	else
		printf("invalid");
	
	return 0;
}
