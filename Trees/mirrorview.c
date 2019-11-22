#include<stdio.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

struct node *newnode(int k)
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->data=k;
	n->left=NULL;
	n->right=NULL;
	return n;
}

struct node *insert(struct node *root,int key)
{
	if(root==NULL)
		return newnode(key);
	else if(root->data  > key)
		root->left=insert(root->left,key);
	else
		root->right=insert(root->right,key);
	return root;
}

void inorder(struct node *root)
{
	if(root==NULL)
		return ;
	printf("%d",root->data);
	inorder(root->left);

	inorder(root->right);
}

int main()
{
	int x;
	struct node *root=(struct node *)malloc(sizeof(struct node));
	root=insert(root,10);
	insert(root,20);insert(root,12);insert(root,5);insert(root,8);insert(root,23);
	
	inorder(root); 
	
	return 0;

}
