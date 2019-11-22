////level order tree
//#include <stdio.h> 
//#include <stdlib.h> 
//struct node 
//{ 
//    int data; 
//    struct node* left; 
//    struct node* right; 
//}; 
//struct node * items[100];
//int front=0, rear=0;
//
//struct node *newNode(int x)
//{
//	struct node *n=(struct node *)malloc(sizeof(struct node));
//	n->data=x;
//	n->left=n->right=NULL;	
//	return n;
//}
//
//void enq(int *rear,struct node *t)
//{
//	items[*rear] = t; 
//    (*rear)++; 
//}
//
//struct node *deq(int *front)
//{
//	(*front)++;
//	return items[*front-1];
//}
//
//
//int size1()
//{
//	return rear-front;
//}
//
//int main()
//{
// 	struct node *root = newNode(1);  
//    root->left = newNode(2);  
//    root->right = newNode(3);  
//    root->left->left = newNode(4);  
//    root->left->right = newNode(5);  
//    root->right->right = newNode(6);
//	//struct node *root=root1;
//	
//	enq(&rear,root);
//	while(1)
//	{
//		int nc=size1();
//		if(nc==0)
//			break;
//		while(nc>0)
//		{
//			
//			struct node *n=deq(&front);
//			printf("%d",n->data);
//			if(n->left!=NULL)
//				enq(&rear,n->left);
//			if(n->right!=NULL)
//				enq(&rear,n->right);
//			nc--;
//		}
//		printf("\n");
//	}
//	return 0;
//}

#include<stdio.h>

struct node
{
	int data;
	struct node *left,*right;
};

int front=0;
int rear=0;
struct node *items[100];

struct node *newNode(int k)
{
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=k;
	n->left=n->right=NULL;
	return n;
}

void enq(int *rear,struct node *x)
{
	items[*rear]=x;
	(*rear)++;
}

struct node *deq(int *front)
{
	(*front)++;
	return items[*front-1];
}

int sz()
{
	return rear-front;
}

int main()
{
	
 	struct node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);
	
	enq(&rear,root);
	while(1)
	{
		int si=sz();
		if(si==0)
			break;
		else
		{
			while(si>0)
			{
				struct node *k=deq(&front);
				printf("%d",k->data);
				if(k->left)
					enq(&rear,k->left);
				if(k->right)
					enq(&rear,k->right);
					
				si--;
			}
			printf("\n");
		}
	}
		
	return 0;
}




























