//lowest common ancestor in Binary tree //not done
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

int path(struct node *root,int a[],int *count,int num)
{
	if(root==NULL)
		return 0;
	a[*count++]=root->data;
	if(root->data == num)
		return 1;
	int x= (path(root->left,a,count,num) || path(root->right,a,count,num) );

	if(x==0)
		*count--;
	return x;
}

int lca2(struct node *root,int n1,int n2)
{
	int a1[100],a2[100];
	int count=0;
	
	int x=path(root,a1,&count,n1);
	int y=path(root,a2,&count,n2);	
	int i=0;
	if(x>y)
	{
		return a2[y-1];
	}
	else if(x<y)
	{
		return a1[x-1];
	}
	else
	{
		for(i=0;i<x;i++)
		{
			if(a1[i]!=a2[i])
				break;
		}
		return a1[i-1];
	}
	
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
	int x=lca2(root,6,5); 
	printf("%d",x);
	return 0;
}
