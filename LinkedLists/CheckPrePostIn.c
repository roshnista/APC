#include<stdio.h>
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


int search(int in[],int s,int e,int data)
{
	int i=0;
	for( i=s;i<=e;i++)
	{
		if(in[i]==data)
			return i;
	}
}

int checkp(struct node *n,int post[],int index)
{
	if(n==NULL)
		return 0;
	
	index=checkp(n->left,post,index);
	index=checkp(n->right,post,index);
	
	if(n->data==post[index])
		index++;
	else
		return -1;
		
	return index;
}

struct node * treee(int in[],int pre[],int s,int e)
{
	static int ind=0;
	struct node *t=newNode(pre[ind++]);
	
	if(s>e)
		return NULL;
	
	if(s==e)
		return t;
	
	int i=search(in,s,e,t->data);
	t->left=treee(in,pre,s,i-1);
	t->right=treee(in,pre,i+1,e);
	return t;
}


int main()
{
	int in[] = {4, 2, 5, 1, 3}; 
    int pre[] = {1, 2, 4, 5, 3}; 
    int post[] = {4, 5, 2, 3, 1}; 
    int l=5;
    
	struct node *n=	treee(in,pre,0,l-1);
	
	int index=checkp(n,post,0);
	if(index==l)
		printf("True");
	else
		printf("false");
	return 0;
}
