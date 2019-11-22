//connect nodes level-level order
#include<stdio.h>
struct node
{
	int data;
	struct node *left,*right,*nextRight;
};
struct node * items[100];
int front=0, rear=0;

struct node *newnode(int x)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->left=n->right=NULL;
	n->nextRight=NULL;	
	return n;
}

void enq(int *rear,struct node *t)
{
	items[*rear] = t; 
    (*rear)++; 
}

struct node *deq(int *front)
{
	(*front)++;
	return items[*front-1];
}
int isempty()
{
	if(front==rear)
		return 1;
	return 0;
}
struct node * peek(int *front)
{
	return items[*front];
}



void level(struct node *n)
{
	enq(&rear,n);
	enq(&rear,NULL);

	while(!isempty())
	{
		struct node *p=deq(&front);
		if(p!=NULL)
		{
			p->nextRight=peek(&front);
					
			if(p->left)	
				enq(&rear,p->left);
			if(p->right)
				enq(&rear,p->right);
		}
		else if(!isempty())
		{
			enq(&rear,NULL);
		}		
	}
	
}

int main()
{
	struct node *n=newnode(1);
	n->left=newnode(2);
	n->right=newnode(3);
	n->left->left=newnode(4);
	n->left->right=newnode(5);

	
	level(n);
	struct node *root=n;
	
	printf("nextRight of %d is %d \n", root->data, root->nextRight ? root->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->left->data, 
     root->left->nextRight ? root->left->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->right->data, 
     root->right->nextRight ? root->right->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->left->left->data, 
     root->left->left->nextRight ? root->left->left->nextRight->data : -1); 
    printf("nextRight of %d is %d \n", root->right->right->data, 
     root->right->right->nextRight ? root->right->right->nextRight->data : -1); 
  

}



