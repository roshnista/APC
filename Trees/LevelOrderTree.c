//level order tree
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


int main()
{
	struct node *root1 = newnode(1); 
    root1->left        = newnode(2); 
    root1->right       = newnode(3); 
    root1->left->left  = newnode(4); 
    root1->left->right = newnode(5); 
  	
	struct node *root=root1;
	//level order
	while(root)
	{
		printf("%d",root->data);
		if(root->left)	
			enq(&rear,root->left);
		if(root->right)
			enq(&rear,root->right);
		root=deq(&front);
		
	}
	return 0;
}
