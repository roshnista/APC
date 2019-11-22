//reverse level order 
//queue +  stacks
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
struct node * items[100];
int front=0, rear=0;

struct node *newnode(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->left=n->right=NULL;	
	return n;
}

typedef struct stack
{
	struct node *data;
	struct stack *next;	
};
struct stack *s1=NULL;


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


void enq(int *rear,struct node *t)
{
	items[*rear] = t; 
    (*rear)++; 
}

struct node *deq(int *front)
{
	(*front)++;
	return items[*front-1];
}

int emp()
{
	if(rear==front)
		return 1;
	return 0;
}

int main()
{
	struct node *root1 = newnode(1); 
    root1->left        = newnode(2); 
    root1->right       = newnode(3); 
    root1->left->left  = newnode(4); 
    root1->left->right = newnode(5); 
  	
	struct node *root=root1;
	
	enq(&rear,root);
	while(!emp())
	{
		root=deq(&front);
		push(&s1,root);
		if(root->right!=NULL)
			enq(&rear,root->right);
		if(root->left!=NULL)
			enq(&rear,root->left);
				
	}

	while(!isempty(s1))
	{
		root=peek(s1);
		printf("%d",root->data);
		pop(&s1);
	}
	return 0;
}
