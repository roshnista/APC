//left view of binary tree
//right view of binary tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;	
};


struct node * items[100];
int front=0, rear=0;

struct node *newNode(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->left=n->right=NULL;	
	return n;
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


int size1()
{
	return rear-front;
}
int isempty()
{
	if(size1()==0)
		return 1;
	return 0;
}



int main()
{
	struct node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6);
	
	enq(&rear,root);

	while(!isempty())
	{
		int n1=size1();
		int i;
		//int n2=size1();
		for(i=1;i<=n1;i++)
		{
				
			struct node *n=deq(&front);
			if(i==1)
				printf("%d",n->data);
			if(n->left!=NULL)
				enq(&rear,n->left);
			if(n->right!=NULL)
				enq(&rear,n->right);
		
		}
	}
		
	return 0;
}


