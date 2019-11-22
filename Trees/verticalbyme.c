//vertically print by me
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}tree;

typedef struct stree
{
	struct tree *tnode;
	int dist;
}stree;

typedef struct queue
{
	struct stree *s;
	struct queue *next;
}queue;

typedef struct LL
{
	int val;
	struct LL *next;
}LL;

void push(queue **front,queue **rear,stree *st)
{
	queue *q=(queue *)malloc(sizeof(queue));
	q->next=NULL;
	q->s=st;
	if(*front==NULL && *rear==NULL)
	{
		*front=*rear=q;
	}
	else
	{
		(*rear)->next=q;
		*rear=q;
	}	
}

void pop(queue **front,queue **rear)
{
	if(*front ==*rear)
	{
		*front=*rear=NULL;
	}
	else
	{
		*front=(*front)->next;
	}
}

int min=INT_MAX;
int max=INT_MIN;

void height(tree *root,int h)
{
	if(root==NULL)
		return;
	if(h<min)
		min=h;
	if(h>max)
		max=h;
	height(root->left,h-1);
	height(root->right,h+1);
}

void vertical(tree *root)
{
	height(root,0);
	int min=-min;
	int n=max>min?max:min;
	n=n*2+1;
	int i;
	LL *a[n];
	for(i=0;i<n;i++)
	{
		a[i]=(LL*)malloc(sizeof(LL));
	}
	for(i=0;i<n;i++)
	{
		a[i]->val=i-(n/2);
		a[i]->next=NULL;
	}
	
	stree *s=(stree *)malloc(sizeof(stree));
	s->tnode=root;
	s->dist=0;
	
	queue *front=NULL;
	queue *rear=NULL;
	push(&front,&rear,s);
	
	while(front && rear)
	{
		int index=front->s->dist;
		int value=front->s->tnode->data;
		
		for(i=0;i<n;i++)
			{
				if(index==a[i]->val)
				{
					LL *new= (LL*)malloc(sizeof(LL));
					new->val=value;
					new->next=NULL;
					
					LL *ptr=a[i];
					while(ptr && ptr->next)
						ptr=ptr->next;
					ptr->next=new;
					break;
				}
			}
		if(front->s->tnode->left)
		{
			stree *s=(stree*)malloc(sizeof(stree));
			s->tnode=front->s->tnode->left ;	
			s->dist=front->s->dist -1;
			push(&front,&rear,s);
		}
		
		if(front->s->tnode->right)
		{
			stree *s=(stree*)malloc(sizeof(stree));
			s->tnode=front->s->tnode->right ;	
			s->dist=front->s->dist +1;
			push(&front,&rear,s);
		}
		
		pop(&front,&rear);
	}
	
	//PRINT
	for(i=0;i<n;i++)
	{
		LL *ptr=a[i]->next;
		while(ptr)
		{
			printf(" %d  ",ptr->val);
			ptr=ptr->next;
		}
	}
	
}


tree * BST(tree *root,int d)
{
	if(root==NULL)
	{
		tree *t=(tree *)malloc(sizeof(tree));
		t->data=d;
		t->left=t->right=NULL;
		return t;
	}
	else if(root->data < d)
		root->left=BST(root->left,d);
	else if(root->data > d)
		root->right=BST(root->right,d);
		return root;
}

void createTree(tree** root)
{
    *root=BST(*root,10);
    *root=BST(*root,6);
    *root=BST(*root,12);
    *root=BST(*root,7);
    *root=BST(*root,4);
    *root=BST(*root,11);
    *root=BST(*root,14);
    *root=BST(*root,5);
    *root=BST(*root,13);
    *root=BST(*root,3);
    *root=BST(*root,16);
    *root=BST(*root,15);
    *root=BST(*root,1);
    *root=BST(*root,2);
}


int main()
{
    tree* root=NULL;
    createTree(&root);
    vertical(root);
}
