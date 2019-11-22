#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

struct stree{
	struct tree *node;
	int dist;
};

struct map{
	int key;
	int value;
};

typedef struct node{
	struct stree *ptr;
	struct node *next;
};node;

typedef struct queue{
	struct node *front;
	struct node *rear;
};queue;

queue *q=(queue*)malloc(sizeof(queue));
q->front=NULL;
q->rear=NULL;

void push(queue *q,struct stree *m)
{
	node *n=(node*)malloc(sizeof(node));
	n->ptr=m;
	n->next=NULL;
	if(q->rear==NULL)
	{
		q->rear=n;
		q->front=n;	
	}
	else
	{
		q->rear->next=n;
		q->rear=n;
	}
}

void pop(queue *q)
{
	if(q->rear == NULL)
		return;
	else
		while(q->front->next!=NULL)
		{
			q=q->front->next;
		}
		q->front->next=NULL;
		
}

queue  *top (queue *q)
{
	return q->rear->ptr;
	 
}
 int isempty(queue *q)
 {
 	if(q->rear == NULL)
 		return 1;
 	return 0;
 }



int main()
{
		stree *root1 = newNode(1); 
	  root1->left        = newNode(2); 
	  root1->right       = newNode(3); 
	  root1->left->left  = newNode(4); 
	  root1->left->right = newNode(5); 
	root1->right->left = newNode(6);
	root1->right->right = newNode(7);
	root1->left->left->left = newNode(8);
	root1->left->right->left = newNode(9);
	root1->right->left->right = newNode(10);     	
		
	
	
	
	stree *r=(stree*)malloc(sizeof(stree));
	root->node=r;
	root->dist=0;
	push(q,root);
	
	while(!isempty(q))
	{
		struct stree *root=top(q);
		pop(q);
		if(root->node->left!=NULL)
		{
			push(q,root->node->right);
			insert(root->node->right-1),;
		}
		if(root->node->right!=NULL)
		{
			push(q,root->node->left);
			root->dist=root->node->left-1;
		}
		root=q->front;
		
	}
	return 0;
}





