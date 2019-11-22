//tree from preorder
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

struct node *treeee(int a[],int *pre,int key,int min,int max,int size)
{
	if(*pre>=size)
		return NULL;
	struct node *n=NULL;
	
	if(key>min && key<max)
	{
		n=newnode(key);
		*pre=*pre+1;
		if(*pre<size)
		{
			n->left=treeee(a,pre,a[*pre],min,key,size);
			
			n->right=treeee(a,pre,a[*pre],key,max,size);		
		}
	}	
	return n;
}
struct node *trr(int a[],int l)
{
	int pre=0;
	return treeee(a,&pre,a[0],INT_MIN,INT_MAX,l);
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
	int a[]={10, 5, 1, 7, 40, 50};
	int l=sizeof(a)/sizeof(a[0]);
	
	
	struct node *k=trr(a,l);
	
	printInorder(k);	
	return 0;
}
