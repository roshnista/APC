//delete a tree	
#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left,*right;	
};

struct node* newNode(int data) 
{ 
  struct node* Node = (struct node*)malloc(sizeof(struct node)); 
  Node->data = data; 
  Node->left = NULL; 
  Node->right = NULL; 
  
  return(Node); 
}

void delete(struct node *curr)
{
	if(curr==NULL)
		return;
	
	delete(curr->left);
	curr=NULL;
	delete(curr->right);
	
}
void inorder(struct node *curr)
{
	if(curr==NULL)
	return;
	inorder(curr->left);
	printf("%d ",curr->data);
	inorder(curr->right);
}
int main()
{
	struct node *root = newNode(1); 
	root->right       = newNode(3); 
	root->left    = newNode(2); 
	
  	root->left->left  = newNode(4); 
  	root->left->right = newNode(5); 
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->right->left = newNode(9);
	root->right->left->right = newNode(10);     	
		
	struct node *curr=root;
	inorder(curr);
	delete(curr);
	inorder(curr);
	
}
