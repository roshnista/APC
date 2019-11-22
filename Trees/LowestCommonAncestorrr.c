//lowest common ancestor in Binary tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};

struct node *newNode(int d)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=d;
	n->left=n->right=NULL;
	return n;
}


struct node * find(struct node *root,int n1,int n2)
{
	if(root==NULL)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;
	struct node *x=find(root->left,n1,n2);
	struct node *y=find(root->right,n1,n2);
	
	if(x && y)
		return root;
	if(x)
		return x;
	if(y)
		return y;
	return NULL;
}


int main()
{
	
	struct node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
	struct node *m=find(root,6,4); 
	printf("%d",m->data);
	return 0;
}
