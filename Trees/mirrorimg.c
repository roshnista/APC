//mirror image
#include<stdio.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data) 
{ 
  struct node* Node = (struct node*)malloc(sizeof(struct node)); 
  Node->data = data; 
  Node->left = NULL; 
  Node->right = NULL; 
  
  return(Node); 
}

void inOrder(struct node* node)  
{ 
    if (node == NULL)  
        return; 
      
    inOrder(node->left); 
    printf("%d ",node->data ); 
    inOrder(node->right); 
}

void mirror(struct node* node)  
{ 
    if (node == NULL)  
        return;  
    else
    { 
        struct node* temp; 
        
        mirror(node->left); 
        mirror(node->right); 
      
       	temp     = node->left; 
        node->left = node->right; 
        node->right = temp; 
    } 
}  
  
int main()
{
	struct node *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
  	root->left->left  = newNode(4); 
  	root->left->right = newNode(5); 

	
 	mirror(root);
    
    //print
    inOrder(root);
   
	return 0;
}
