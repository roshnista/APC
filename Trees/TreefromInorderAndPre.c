#include<stdio.h>
struct node 
{
	int data;
	struct node *left,*right;	
};

typedef struct stack
{
	struct node *data;
	struct stack *next;	
};
struct stack *s=NULL;


void push(struct stack **a,struct node *val)
{
	struct stack *p=(struct stack*)malloc(sizeof(struct stack));
	p->data=val;
	if(*a==NULL)
	{
		p->next=NULL;
		*a=p;
	}
	else
	{
		p->next=*a;
		*a=p;
	}
	
}

void pop(struct stack **a)
{
	if(*a==NULL)
		printf("nothing to pop");
	else
	{
		struct stack *x=*a;
		*a=(*a)->next;
		free(x);
	}

}

struct node * peek(struct stack *a)
{
	if(a!=NULL)
	return a->data;
	else
	return -1;	
}

int isempty(struct stack *a)
{
	if(a==NULL)
		return 1;
	else 
		return 0;
}


struct node* newNode(int data) 
{ 
  struct node* Node = (struct node*)malloc(sizeof(struct node)); 
  Node->data = data; 
  Node->left = NULL; 
  Node->right = NULL; 
  
  return(Node); 
  
}

void inorder(struct node *curr)
{
		
//	struct node *curr=root;
	
	while(!isempty(s) || curr )
	{
		while(curr)
		{
			printf("%d",curr->data);
			push(&s,curr);
			curr=curr->left;
		}
			
  	
		curr=peek(s)->right;
		pop(&s);	
	}
	
}
int search(int in[],int s,int e,int data)
{
	int i=0;
	for( i=s;i<=e;i++)
	{
		if(in[i]==data)
			return i;
	}
}

struct node * treee(int in[],int pre[],int s,int e)
{
	static int ind=0;
	struct node *t=newNode(pre[ind++]);
	
	if(s>e)
		return NULL;
	
	if(s==e)
		return t;
	
	int i=search(in,s,e,t->data);
	t->left=treee(in,pre,s,i-1);
	t->right=treee(in,pre,i+1,e);
	return t;
}


int main()
{
	int in[] = {4, 2, 5, 1, 3}; 
    int pre[] = {1, 2, 4, 5, 3}; 
    int l=5;
    
	struct node *n=	treee(in,pre,0,l-1);
	inorder(n);
	return 0;
}
