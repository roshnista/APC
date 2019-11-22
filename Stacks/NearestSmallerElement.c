//nearest smaller element
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


int main()
{
	int n=9,i=0,x,min=1234,d;
	int a[n];
	int res[n];
	
	for(i=0;i<n;i++)
		{
			res[i]=-1;
			scanf("%d",&a[i]);
		}
		
	for(i=n-1;i>=0;i--)
	{	
		if( isEmpty(s) || a[top(s)]<a[i] )
		{
			push(&s,i); 
			
		}
	
		else
		{
			while(a[i]<a[top(s)] && !isEmpty(s))
			{
				res[top(s)]=a[i];
				pop(&s);
			}
			push(&s,i);
		}
	}	

	
	
	for(i=0;i<n;i++)
		printf("%d",res[i]);
	
	return 0;
}
