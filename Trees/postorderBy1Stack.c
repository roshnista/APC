#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct stack
{
	struct node *data;
	struct stack *next;	
};
struct stack *s=NULL;


void push(struct stack **a,struct node *val)
{
	struct stack *p=(struct stack*)malloc(sizeof(struct stack));
	p->data=val;
	if(*a==NULL)
	{
		p->next=NULL;
		*a=p;
	}
	else
	{
		p->next=*a;
		*a=p;
	}
	
}

void pop(struct stack **a)
{
	if(*a==NULL)
		printf("nothing to pop");
	else
	{
		struct stack *x=*a;
		*a=(*a)->next;
		free(x);
	}

}

struct node * peek(struct stack *a)
{
	if(a!=NULL)
	return a->data;
	else
	return -1;	
}

int isempty(struct stack *a)
{
	if(a==NULL)
		return 1;
	else 
		return 0;
}

struct node* newNode(int data) 
{ 
 struct node* Node = (struct node*)malloc(sizeof(struct node)); 
 Node->data = data; 
 Node->left = NULL; 
 Node->right = NULL; 
 
 return(Node); 
}

int main()
{
	struct node *root = newNode(1); 
 root->left        = newNode(2); 
 root->right       = newNode(3); 
 root->left->left  = newNode(4); 
 root->left->right = newNode(5); 
root->right->left = newNode(6);
root->right->right = newNode(7);
root->left->left->left = newNode(8);
root->left->right->left = newNode(9);
root->right->left->right = newNode(10);     	
		
	struct node *curr=root;
    struct node *d;
    
    do
    {
        while(root)
        {
            if(root->right)
                push(&s,root->right);
            push(&s,root);
            root=root->left;
        }
        root=peek(s);
        pop(&s);
        if(root->right && root->right==peek(s))
        {
            pop(&s);
            push(&s,root);
            root=root->right;
        }
        else
        {
            printf("%d",root->data);
            root=NULL;
        }
        
    }while(!isempty(s));
    
    return 0;
}
