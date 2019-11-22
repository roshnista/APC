//nearest largest element
#include<stdio.h>
struct stack
{
	int d;
	struct stack *next;
};
struct stack *s=NULL;

void push(struct stack **top,int x)
{
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->d=x;
	if(*top==NULL)
	{
		s->next=NULL;
		*top=s;
	}
	else
	{
		s->next=*top;
		*top=s;
	}
}

void pop(struct stack **top)
{
	if(*top==NULL)
	{
		printf("nothing to pop");
	}
	else
	{
		struct stack *p=*top;
		*top=(*top)->next;
		free(p);
	}
}

int isEmpty(struct stack *top)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int top(struct stack *top)
{
	if(top==NULL)
		return -1;
	else
		return top->d;
}

void ng(int a[],int n)
{
	int i,b[n];
	for(i=n-1;i>=0;i--)
	{
		while(!isEmpty(s) && top(s)<=a[i])
			pop(&s);
		if(isEmpty(s))
			b[i]=-1;
		else
			b[i]=top(s);
		
		push(&s,a[i]);	
	}	
	
	for(i=0;i<n;i++)
		printf("%d ",b[i]);

}

int main()
{
	int n=7;
	int a[]={7,6,5,4,3,2,1};
	ng(a,n);
}
