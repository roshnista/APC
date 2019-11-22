#include<stdio.h>
#include<stdlib.h>
int min=INT_MAX;
int max=INT_MIN;

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}tree;


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


void ma(tree *root,int d)
{
	if(root==NULL)
		return;
	if(d>max)
		max=d;
	if(d<min)
		min=d;
	ma(root->left,d-1);
	ma(root->right,d+1);
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
	ma(root,0);
	printf("%d %d",max,min);
	return 0;
}
