//construct tree from given inorder
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

struct node *newnode(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->left=n->right=NULL;	
	return n;
}

int max(int a[],int strt,int end)
{
	int m=a[strt];
	int ind=strt,i=0;
	for(i=strt+1;i<=end;i++)
		{
			if(a[i]>m)
			{
				ind=i;
				m=a[i];
			}
		}
	return ind;
}

struct node *treeee(int a[],int strt,int end)
{
	if(strt>end)
		return NULL;
	int ma=max(a,strt,end);
	//printf("%d",ma);
	struct node *root=newnode(a[ma]);
	if(strt==end)
		return root;
	root->left=treeee(a,strt,ma-1);
	root->right=treeee(a,ma+1,end);

	return root;
}

void printInorder(struct node* node) 
{ 
    if(node == NULL) 
        return; 
    printInorder(node->left); 
    printf("%d ", node->data); 
    printInorder(node->right); 
}

int main()
{
	int a[]={5, 10, 40, 30, 28};
	int l=sizeof(a)/sizeof(a[0]);
	
	
	struct node *k=treeee(a,0,l-1);
	
	printInorder(k);	
	return 0;
}
