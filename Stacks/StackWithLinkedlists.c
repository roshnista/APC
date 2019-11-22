//stacks using linked lists
#include<stdio.h>
typedef struct stack
{
	int data;
	struct stack *next;	
};
struct stack *top=NULL;


struct stack *push(struct stack *a,int val)
{
	struct stack *p=(struct stack*)malloc(sizeof(struct stack));
	p->data=val;
	if(a==NULL)
	{
		p->next=NULL;
		a=p;
	}
	else
	{
		p->next=a;
		a=p;
	}
	
return a;
}

struct stack *pop(struct stack *a)
{
	if(a==NULL)
		printf("nothing to pop");
	else
	{
		struct stack *x=a;
		a=a->next;
		free(x);
	}
return a;
}

int peek(struct stack *a)
{
	if(a!=NULL)
	return a->data;
	else
	return -1;	
}
void display(struct stack *a)
{
	if(a==NULL)
	{
		printf("nothing here");
	}
	else
	{
		while(a!=NULL)
		{
			printf("%d",a->data);
			a=a->next;
		}
	}
}

int main()
{
	struct stack *a=(struct stack *)malloc(sizeof(struct stack));
	int val;
	scanf("%d",&val);
	while(val!=-1)
	{
		top=push(top,val);
		scanf("%d",&val);
	}
	
	int x=peek(top);
	printf("%d\n",x);
	
	while(top!=NULL)
	{
		top=pop(top);
		display(top);
		printf("\n");
	}
	
	return 0;
}
