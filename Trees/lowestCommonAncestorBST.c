//lowest common ancestor in BST
#include<stdio.h>
struct node
{
	int data;
	struct node *left,*right;
};

struct node *newnode(int d)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=d;
	n->left=n->right=NULL;
	return n;
}

int search(struct node *root,int k)
{	
	while (root)
	{
		if (k < root->data)
			root = root->left;
		else if (k > root->data)
			root = root->right;
		else
			return 1;
	}
	return 0;
}
struct node *lca(struct node *root,int n1,int n2)
{
	if(!search(root,n1) || !search(root,n2)   || root==NULL) 
	{
		return NULL;
	}
	while(root)
	{
		if(root->data>n1 && root->data>n2)
		{
			root=root->left;
		}
		else if(root->data<n1 && root->data<n2)
		{
			root=root->right;
		}
		else
		{
			break;
		}
	}
	return root;	
}


int main()
{
	
	struct node *root=newnode(20);
	root->left=newnode(10);
	root->right=newnode(25);
	root->left->right=newnode(12);
	root->left->left=newnode(1);
	
	struct node *x=	lca(root,10,25);
	printf("%d",x->data);
	return 0;
}

