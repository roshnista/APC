//top view by me
#include<stdio.h>
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
	struct stree *dist; 
}stree;

typedef struct queue
{
	struct stree *st;
	struct queue *next;
}queue;


void push(queue **front,queue **rear,stree *t)
{
	queue *q=(queue *)malloc(sizeof(queue));
	q->st=t;
	q->next=NULL;
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
	if(*front==*rear)
	{
		*front=*rear=NULL;
	}
	else
	{
		*front=(*front)->next;
	}
}

void topview(tree *root)
{
	int a[100],i,center=50;
	for(i=0;i<100;i++)
		a[i]=0;
	i=0;
	
	stree *temp=(stree *)malloc(sizeof(stree));
	temp->tnode=root;
	temp->dist=0;
		
	queue *rear=NULL;
	queue *front=NULL;
	
	push(&front,&rear,temp);
	while(front && rear)
	{
		int index=front->st->dist;
		int value=front->st->tnode->data;
		
		if(a[center+index]==0)
			a[center+index]=value;
		
		
		if(front->st->tnode->left)
		{
			stree *temp1=(stree *)malloc(sizeof(stree));
			temp1->tnode=front->st->tnode->left;
			temp1->dist=front->st->dist-1;	
			push(&front,&rear,temp1);
		}
		if(front->st->tnode->right)
		{
			stree *temp1=(stree *)malloc(sizeof(stree));
			temp1->tnode=front->st->tnode->right;
			temp1->dist=front->st->dist+1;	
			push(&front,&rear,temp1);
		}
		pop(&front,&rear);
		
	}
	
	for(i=0;i<100;i++)
		if(a[i]!=0)
			printf(" %d ",a[i]);

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

int main()
{
	tree *root=NULL;
	root=BST(root,10);
    root=BST(root,6);
    root=BST(root,12);
    root=BST(root,7);
    root=BST(root,4);
    root=BST(root,11);
    root=BST(root,14);
    root=BST(root,5);
    root=BST(root,13);
    root=BST(root,3);
    root=BST(root,16);
    root=BST(root,15);
    root=BST(root,1);
    root=BST(root,2);
	topview(root);
	return 0;
}
