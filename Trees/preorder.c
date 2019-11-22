////preorder non recursively 
////root left right
//
//#include<stdio.h>
//
//struct node 
//{
//	int data;
//	struct node *left;
//	struct node *right;
//};
////struct node *curr=NULL;
//
//typedef struct stack
//{
//	struct node *data;
//	struct stack *next;	
//};
//struct stack *s=NULL;
//
//
//void push(struct stack **a,struct node *val)
//{
//	struct stack *p=(struct stack*)malloc(sizeof(struct stack));
//	p->data=val;
//	if(*a==NULL)
//	{
//		p->next=NULL;
//		*a=p;
//	}
//	else
//	{
//		p->next=*a;
//		*a=p;
//	}
//	
//}
//
//void pop(struct stack **a)
//{
//	if(*a==NULL)
//		printf("nothing to pop");
//	else
//	{
//		struct stack *x=*a;
//		*a=(*a)->next;
//		free(x);
//	}
//
//}
//
//struct node * peek(struct stack *a)
//{
//	if(a!=NULL)
//	return a->data;
//	else
//	return -1;	
//}
//
//int isempty(struct stack *a)
//{
//	if(a==NULL)
//		return 1;
//	else 
//		return 0;
//}
//
//struct node* newNode(int data) 
//{ 
//  struct node* Node = (struct node*)malloc(sizeof(struct node)); 
//  Node->data = data; 
//  Node->left = NULL; 
//  Node->right = NULL; 
//  
//  return(Node); 
//}
//
//int main()
//{
//	struct node *root = newNode(1); 
//  root->left        = newNode(2); 
//  root->right       = newNode(3); 
//  root->left->left  = newNode(4); 
//  root->left->right = newNode(5); 
//	
//	struct node *curr=root;
//	
//	while(!isempty(s) || curr )
//	{
//		while(curr)
//		{
//			printf("%d",curr->data);
//			push(&s,curr);
//			curr=curr->left;
//		}
//			
//  	
//		curr=peek(s)->right;
//		pop(&s);	
//	}
//	
//		
//		
//	return 0;
//}

#include<stdio.h>

struct node
{
	struct node *left;
	struct node *right;
	int data;	
};

struct node *newNode(int k)
{
	struct node *new=(struct node *)malloc(sizeof(struct node ));
	new->data=k;
	new->left=new->right=NULL;
	return new;
}


struct stack
{
	struct node *d;
	struct stack *next;
};
struct stack *s=NULL;

void push(struct stack **s,struct node *t)
{
	struct stack *s1=(struct stack *)malloc(sizeof(struct stack));
	s1->d=t;
		
	if(*s==NULL)
	{
		s1->next=NULL;
		*s=s1;
	}
	else
	{	s1->next=*s;
		*s=s1;
	}
}
void pop(struct stack **s)
{
	if(*s==NULL)
		printf("nothing to pop");
	*s=(*s)->next;	
}

struct node *top(struct stack *s)
{
	return (s->d);
}

int isempty(struct stack *s)
{
	if(s==NULL)
		return 1;
	return 0;
}




int main()
{
	struct node *root = newNode(1); 
	root->left        = newNode(2); 
	root->right       = newNode(3); 
	root->left->left  = newNode(4); 
	root->left->right = newNode(5); 
	
	struct node *curr=root;
	
	//preorder
	
	while(curr || !isempty(s))
	{
		while(curr)
		{
			push(&s,curr);
			curr=curr->left;
		}
		struct node *temp=top(s);
		if(temp->right==NULL)
		{
			printf("%d",temp->data);
			pop(&s);
				while(!isempty(s) && top(s)->right==temp)
				{
					temp=top(s);
					pop(&s);
					printf("%d",temp->data);
				}
				curr=top(s)->right;
		}
		else
		{
			curr=temp->right;
		}
	}
	
	return 0;
}






























