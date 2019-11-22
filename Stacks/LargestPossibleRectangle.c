//max possible rectangle area using stacks
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
	return top->d;
}

int main()
{
	int n=5,i=0;
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int area,dist,x,max=0;
	for(i=0;i<n;i++)
	{	
		if(isEmpty(s) || arr[i]>=arr[top(s)])
		{
			
			push(&s,i);
			
		}
		else
		{
			while(!isEmpty(s) && arr[top(s)]>arr[i])
			{
				x=arr[top(s)];
				pop(&s);
				
				dist=isEmpty(s)?i:i-top(s)-1;
				
				area=x*dist;
				if(max<area)
					max=area;
			}
			push(&s,i);
		}
	}
	
	while(!isEmpty(s))
	{
		int y=arr[top(s)];
		pop(&s);
		dist=isEmpty(s)?n:n-top(s)-1;
		area=dist*y;
		if(max<area)
			max=area;
	}
		
		printf("%d",max);

return 0;
}
